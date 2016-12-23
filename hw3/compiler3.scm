(load "pattern-matcher.scm")
(load "pc.scm")

(define defGetter
	(lambda (exp rest)
		(letrec ((listDef (list))
				(loop (lambda (exp rest)
						(cond
							((not (list? exp)) `(,listDef ,exp ,@rest))
							((null? exp) listDef)
							((null? rest) (if (equal? (car exp) 'def) 
											(begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) listDef)
											`(,listDef ,exp)))
							((equal? (car exp) 'def) (begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) (loop (car rest) (cdr rest))))
							(else `(,listDef ,exp ,@rest)))
				)))
				(loop exp rest)
	)))


(define validSeq?
	(lambda (exp)
		(if (null? exp) #f
		(andmap (lambda (shit) (not (equal? (car shit) 'def))) exp))
	))

(define varsGetter
	(lambda (exp)
		(map (lambda (exp2) (cadadr exp2)) exp)))

(define falseMaker
	(lambda (exp)
		(map (lambda (exp2) '(const #f)) exp)))

(void)

(define noDefines
	(lambda (exp)
		(letrec ((isValidNoDefList #t)
				(loop (lambda (exp2)
						(cond 
							((not (list? exp2)) (void))
							((null? exp2) (void))
							((equal? (car exp2) 'def) (set! isValidNoDefList #f))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isValidNoDefList ))))


(define inLambda 
	(let ((run 
			(compose-patterns
				;;;;def
				(pattern-rule
				`(def ,(? 'var) ,(? 'val) )
					(lambda (var val)  `(seq (set ,var ,(eliminate-nested-defines-helper val))) ))
				;;;;seq
				(pattern-rule
				`(seq ,(? 'exp))
					(lambda (exp)  
						(let ((defExp (defGetter (car exp) (cdr exp))))
								(if (validSeq? (car defExp))
									(let* ((vars (varsGetter (car defExp)))
											(falseLst (falseMaker vars)))
											`(applic (lambda-simple ,vars (seq (,@(eliminate-nested-defines-helper (car defExp)) ,@(eliminate-nested-defines-helper (cdr defExp)))))
												,falseLst))
									(if (null? (car defExp)) 
										(eliminate-nested-defines-helper exp)
													(error 'inLambda "Seq in not a valid seq: ~s" ))))))
				(pattern-rule
				(? 'exp)
					(lambda (exp)  (eliminate-nested-defines-helper exp)))
		)))  
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))


(define eliminate-nested-defines-helper
	(let ((run 
			(compose-patterns
				;;;;lambda
				(pattern-rule
				`(lambda-simple ,(? 'vars) ,(? 'body) )
					(lambda (vars body) `(lambda-simple ,vars ,(inLambda  body ))))
				(pattern-rule
				`(lambda-var ,(? 'vars) ,(? 'body) )
					(lambda (vars body) `(lambda-var ,vars ,(inLambda  body ))))
				(pattern-rule
				`(lambda-opt ,(? 'vars) ,(? 'var) ,(? 'body) )
					(lambda (vars var body) `(lambda-opt ,vars ,var ,(inLambda  body ))))
				(pattern-rule
				(? 'exp)
					(lambda (exp)  
						(cond
							((null? exp) exp) 
							((not (list? exp)) exp)
							((list? (car exp)) `(,(eliminate-nested-defines-helper (car exp)) ,@(eliminate-nested-defines-helper (cdr exp))))
							(else `(,(car exp) ,@(eliminate-nested-defines-helper (cdr exp)))))))
		)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))


(define eliminate-nested-defines
	(lambda (exp)
		(let ((noNestedDefines (eliminate-nested-defines-helper exp)))
			(if (noDefines (cdr noNestedDefines))
				noNestedDefines
				(error 'define "tibeten calender ~s" ))
			)
		))

;;;;;;;;;;;;;;;;;;;;; Boxing of variables ;;;;;;;;;;;;;;;;;;;;


(define boundOccurence 
	(lambda (var exp) 
		(letrec ((isBoundOccurence #f)
				(loop (lambda (exp2)
						(cond 
							((and (not (list? exp2)) (equal? var exp2)) (set! isBoundOccurence #t))
							((not (list? exp2)) (void))
							((null? exp2) (void))
							((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
									(not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
								 			(loop (caddr exp2)))
							((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) (loop (cadddr exp2)))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
									 (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
											(void))
							((and (equal? (car exp2) 'lambda-opt) (member var (append (cadr exp2) (list (caddr exp2))))) (void))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isBoundOccurence ))))



(define setExpression 	
	(lambda (var exp) 
		(letrec ((isSetOccurence #f)
				(loop (lambda (exp2)
						(cond 
							((not (list? exp2)) (void))
							((null? exp2) (void))
							((and (equal? (car exp2) 'set) (equal? (cadadr exp2) var)) 
								 			(set! isSetOccurence #t))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isSetOccurence ))))


(define getOccurence 
	(lambda (var exp) 
		(letrec ((isGetOccurence #f)
				(loop (lambda (exp2)
						(cond 
							((and (not (list? exp2)) (equal? var exp2)) (set! isGetOccurence #t))
							((not (list? exp2)) (void))
							((null? exp2) (void))
							((and (equal? (car exp2) 'set) (equal? (cadadr exp2) var)) (loop (cddr exp2)))
							((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
									(not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
								 			(loop (caddr exp2)))
							((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) (loop cadddr exp2))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
									 (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
											(void))
							((and (equal? (car exp2) 'lambda-opt)  (member var (append (cadr exp2) (list (caddr exp2))))) (void))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isGetOccurence ))))


(define createBoxingLst
	(lambda (exp) ;assuming we recieve a lambda
		(let* (
				(body (if (equal? (car exp) 'lambda-opt)
								(cadddr exp)
							 	(caddr exp)))
				(varsToBox (map 
							(lambda (var) 
									(if (and (boundOccurence  var body) (setExpression  var body) (getOccurence  var body)) 
										`(var ,var)
										(void))) 	
							(cond 
								((equal? (car exp) 'lambda-opt) (append (cadr exp) (list (caddr exp))))
								((equal? (car exp) 'lambda-var) (list (cadr exp)))
							 	(else (cadr exp)))
				))
		)
		(remove (void) varsToBox)))
	)

;;;;

(define createSetBoxExpHelper
	(lambda (lstOfVars)
		(cond 
			((null? lstOfVars) (void))
			((null? (cdr lstOfVars)) `((set ,(car lstOfVars) (box ,(car lstOfVars))) ))
			(else `( (set ,(car lstOfVars) (box ,(car lstOfVars))) ,@(createSetBoxExpHelper (cdr lstOfVars))))
		)
	)
)

(define createSetBoxExp
	(lambda (lstOfVars)
		(let ((setBoxLst (createSetBoxExpHelper lstOfVars)))
			(if (null? (cdr setBoxLst))
				(car setBoxLst)
			setBoxLst)
			)
))


(define createBodyBoxWithOneVar 
	(lambda (var body)
		(cond 
				((not (list? body)) body)
				((null? body) body)
				((and (or (equal? (car body) 'lambda-simple)  (equal? (car body) 'lambda-var))
						(member (cadr var) (if (list? (cadr body)) (cadr body) (list (cadr body)))))
					 			body)
				((and (equal? (car body) 'lambda-opt) (member (cadr var) (append (cadr body) (list (caddr body)))))  body)

				((and (equal? (car body) 'set) (equal? (cadr body) var)) `(box-set ,var ,@(createBodyBoxWithOneVar var (cddr body))))

				((equal? body var) `(box-get ,var))
				(else (cons (createBodyBoxWithOneVar var (car body)) (createBodyBoxWithOneVar var (cdr body)))))
	)
	)

(define createBodyBoxExp
	(lambda (lstVars body)
		(let ((bodyExp body))
			(begin 
				(map (lambda (var) (set! bodyExp (createBodyBoxWithOneVar var bodyExp))) lstVars)
				bodyExp
			))))

(define changingLambdaWithBoxing
	(lambda (exp)
		(let* 
			((params (if (equal? (car exp) 'lambda-opt) 
						(append (cadr exp) (list (caddr exp)))
						(if (list? (cadr exp)) (cadr exp) (list (cadr exp)))))
			(body (if (equal? (car exp) 'lambda-opt)
					(cadddr exp)
				 	(caddr exp))))
	`( ,(car exp) ,params
		 ,(list 'seq (list (createSetBoxExp (createBoxingLst exp))  (createBodyBoxExp (createBoxingLst exp) body)))))
	)
)

(define boxingOfVariables
	(lambda (exp)
		(cond ((not (list exp)) exp)
		      ((null? exp) exp)
		      ((or (equal? (car exp) 'lambda-simple) (equal? (car exp) 'lambda-opt) (equal? (car exp) 'lambda-var))
						(changingLambdaWithBoxing exp))
		      (else (cons (if (list? (car exp)) (boxingOfVariables (car exp)) (car exp)) (boxingOfVariables (cdr exp))))
		  )
	)
)

;;;; tests
;(boxingOfVariables '(lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x)))))))
;(boxingOfVariables '(seq (lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x)))))) (lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x))))))))
;(boxingOfVariables '(applic (lambda-opt (z) a (applic (var list) ((lambda-simple () (var a)) (lambda-simple () (set (var a) (applic (var +) ((var a) (const 1))))) (lambda-simple (b) (set (var a) (var b))))))  ((const 0))))
;(boxingOfVariables ' (applic (lambda-simple (a)  (applic (var list)
;((lambda-simple () (var a)) (lambda-simple () 
;(set (var a) (applic (var +) ((var a) (const 1)))))
;(lambda-simple (b) (set (var a) (var b))))))
;((const 0))))
;(boxingOfVariables '(applic (lambda-var args (applic (var list) ((lambda-simple () (var args)) (lambda-simple () (set (var args) (applic (var +) ((var args) (const 1))))) (lambda-simple (b) (set (var args) (var b))))))  ((const 0))))



;;;;;;;;;;;;;;;;;;;;; Removing redundant applications ;;;;;;;;;;;;;;;;;;;;

(define changingApplicLambdaNil
	(lambda (exp)
		 (car (cddadr exp))
	)
)


(define remove-applic-lambda-nil
	(lambda (exp)
	(cond ((not (list exp)) exp)
		      ((null? exp) exp)
		      ((and (equal? (car exp) 'applic) (equal? (caadr exp) 'lambda-simple) (null? (cadadr exp)))
						(changingApplicLambdaNil exp))
		      (else (cons (if (list? (car exp)) (remove-applic-lambda-nil (car exp)) (car exp)) (remove-applic-lambda-nil (cdr exp))))
		  )
	)
)

;(define exp '(applic (lambda-simple (fact) (seq ((set (var fact) (box (var fact))) (box-set (var fact)
;	(lambda-simple (n) (if3 (applic (var zero?) ((var n))) (const 1)
;	(applic (var *) ((var n) (applic (box-get (var fact)) ((applic (var -) ((var n) (const 1))))))))))
;	(applic (lambda-simple () (applic (box-get (var fact)) ((const 5)))) ())))) ((const #f))))

;(remove-applic-lambda-nil exp)


;;;;;;;;;;;;;;;;;;;;;  Annotating tail calls ;;;;;;;;;;;;;;;;;;;;

;; to add seq and or

(define annotate-tc
	(lambda (exp)
		(letrec ((loop
                (lambda (expr tail?)
                    (cond
                    	((not (list? expr)) expr)
                    	((null? expr) expr)
                    	((equal? (car expr) 'applic) 
                    		(if tail?
                    			(list 'tc-applic (loop (cadr expr) #f) (loop (caddr expr) #f))
                    			(list 'applic (loop (cadr expr) #f) (loop (caddr expr) #f))
                    		)
                    	)
                    	((equal? (car expr) 'lambda-simple) (list 'lambda-simple (cadr expr) (loop (caddr expr) #t))) 
                    	((equal? (car expr) 'lambda-opt) (list 'lambda-opt (cadr expr) (caddr expr) (loop (cadddr expr) #t))) 
                    	((equal? (car expr) 'lambda-var) (list 'lambda-var (cadr expr) (loop (caddr expr) #t)))
                    	((equal? (car expr) 'if3) 
								(list 'if3 (loop (cadr expr) #f) (loop (caddr expr) tail?) (loop (cadddr expr) tail?)))
                    	(else (cons (loop (car expr) tail?) (loop (cdr expr) tail?))) 
                    )
                    )))
       (loop exp #t))
	))


;;; tests
(define exp1 '(lambda-simple (x) (applic (var x) (var x))))
(define exp2 '(def (var fact)
	(lambda-simple (n)
(if3 (applic (var zero?) ((var n)))
(const 1)
(applic
(var *)
((var n)
(applic
(var fact)
((applic (var -) ((var n) (const 1)))))))))))


(define exp3 '(applic (var x) ((lambda-simple (x) (applic (var x)
((lambda-simple () (applic (var x) ((lambda-simple () (applic (var x) ((var x)))))))))))))
(define exp4 '(lambda-simple (f) (applic (lambda-simple (x)
(applic (var f) ((lambda-var s (applic (var apply)
((applic (var x) ((var x))) (var s))))))) ((lambda-simple (x) (applic (var f) ((lambda-var s
(applic (var apply) ((applic (var x) ((var x))) (var s)))))))))))

;(annotate-tc exp1)
;(annotate-tc exp2)
;(annotate-tc exp3)
;(annotate-tc exp4)



;;;;;;;;;;;;;;;annotating Variables with their Lexical address;;;;;;;;;

(define pvarLstMaker
	(lambda (exp) ;assuming is a lambda
		(letrec ((pvars (cond ((equal? (car exp) 'lambda-var) (list (list 'var (cadr exp))))
							((equal? (car exp) 'lambda-opt) (cadr exp)) ;;;;;check!!! is probably wrong both for empty lambda and opt and variadic 
							(else (cadr exp))))
				(loop (lambda (var rest num)
					(if (null? rest) (list `(pvar ,(cadr var) ,num))
						(cons `(pvar ,(cadr var) ,num) (loop (car rest) (cdr rest) (+ num 1))))
					)))
			(loop (car pvars) (cdr pvars) 0))
			))


(define bvarLstMaker
	(lambda (exp pvars bvars) ;assuming is a lambda
		(letrec ((bvarsnew (cond ((equal? (car exp) 'lambda-var) (list (cadr exp)))
							((equal? (car exp) 'lambda-opt) (cadr exp)) ;;;;;check!!! is probably wrong
							(else (cadr exp))))
				(loop (lambda (var rest num)
					(cond 
						((ormap (lambda (pvar) (equal? (cadr var) (cadr pvar))) pvars)
							(if (null? rest) (list `(bvar ,(cadr var) 0 ,num))
								(cons `(bvar ,(cadr var) 0 ,num) (loop (car rest) (cdr rest) (+ num 1)))))
						;;;;compare to bvars! and attach to it + give them bigger number... 
						(else '())
					))))
			(loop (car bvarsnew) (cdr bvarsnew) 0))
			))


(define pvar '((pvar a 0) (pvar b 1) (pvar c 2)))


(define pe->lex-pe
	(lambda (exp)
		;(bvarLstMaker exp pvar '())
		(pvarLstMaker exp)
		))



;(pe->lex-pe '(lambda-simple ((var a) (var b) (var c) (var d))	 ()))

;;;;;check all possible  of previous calls 