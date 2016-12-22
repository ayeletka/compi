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
		(andmap (lambda (shit) (not (equal? (car shit) 'def))) exp)
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
													(error 'inLambda "Seq in not a valid seq: ~s" )))))
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
				`(lambda-opt ,(? 'vars) ,(? 'body) )
					(lambda (vars body) `(lambda-opt ,vars ,(inLambda  body ))))
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
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									(not (member var (cadr exp2))))
								 			(loop (caddr exp2)))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									 (member var (cadr exp2)))
											(void))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isBoundOccurence ))))

;(define boundOccurence 
;	(lambda (var exp) 
;		(letrec ((isBoundOccurence #f)
;				(loop (lambda (exp2)
;						(cond 
;							((not (list? exp2)) (void))
;							((null? exp2) (void))
;							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
;									(not (member var (cadr exp2))))
;								 			(if (boundHelper var (caddr exp2)) (set! isBoundOccurence #t) (void)))
;							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
;									 (member var (cadr exp2)))
;											(void))
;							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
;		(begin (loop exp) isBoundOccurence ))))


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
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									(not (member var (cadr exp2))))
								 			(loop (caddr exp2)))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									 (member var (cadr exp2)))
											(void))
							(else (begin (loop (car exp2)) (loop (cdr exp2))))))))
		(begin (loop exp) isGetOccurence ))))



(define createBoxingLst
	(lambda (exp) ;assuming we recieve a lambda
		(let ((varsToBox (map 
							(lambda (var) 
									(if (and (boundOccurence  var (caddr exp)) (setExpression  var (caddr exp)) (getOccurence  var (caddr exp))) 
										`(var ,var)
										(void))) 	
							(cadr exp))
				))
		(remove (void) varsToBox)))
	)

;;;;

(define createSetBoxExpHelper
	(lambda (lstOfVars)
		(cond 
			((null? lstOfVars) (void))
			((null? (cdr lstOfVars)) `((set ,(car lstOfVars) (box ,(car lstOfVars))) ))
			(else `( (set ,(car lstOfVars) (box ,(car lstOfVars))) ,@(createSetBoxExp (cdr lstOfVars))))
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


;(if (null? (cdr (createSetBoxExp '(  (var k) (var k)))))
;	(car (createSetBoxExp '( (var k) (var k))))
;(createSetBoxExp '( (var k) (var k))))



(define createBodyBoxWithOneVar 
	(lambda (var body)
		(cond 
				((not (list? body)) body)
				((null? body) body)
				((and (or (equal? (car body) 'lambda-simple) (equal? (car body) 'lambda-opt) (equal? (car body) 'lambda-var))
						(member (cadr var) (cadr body)))
					 			body)
				((and (equal? (car body) 'set) (equal? (cadr body) var)) `(box-set ,var ,@(createBodyBoxWithOneVar var (cddr body))))

				((equal? body var) `(box-get ,var))
				(else (cons (createBodyBoxWithOneVar var (car body)) (createBodyBoxWithOneVar var (cdr body)))))
	)
	)
;(createBodyBoxWithOneVar '(var x)  '(seq (set (var x) y) (lambda-simple (x) (var x)) (lambda-simple () (seq (var y) (set (var y) (var x))))))

(define createBodyBoxExp
	(lambda (lstVars body)
		(let ((bodyExp body))
			(begin 
				(map (lambda (var) (set! bodyExp (createBodyBoxWithOneVar var bodyExp))) lstVars)
				bodyExp
			))))

;(createBodyBoxExp '((var x) (var y))  '(seq (set (var x) y) (lambda-simple (y) (var x)) (lambda-simple () (seq (var y) (set (var y) (var x))))))


(define changingLambdaWithBoxing
	(lambda (exp)
	`( ,(car exp) ,(cadr exp)
		 ,(list 'seq (list (createSetBoxExp (createBoxingLst exp)) (car (createBodyBoxExp (createBoxingLst exp) (cddr exp))))))
	)
)
(list '(var x) '(var y))

(changingLambdaWithBoxing '(lambda-simple (x y z) (seq (set (var x) y) (lambda-simple (y) (var x)) (lambda-simple () (seq (var y) (set (var y) (var x)))))))
;(equal? '(var a) '(var a))
(changingLambdaWithBoxing '
(lambda-simple
(a)
(applic
(var list)
((lambda-simple () (var a))
(lambda-simple

()
(set (var a) (applic (var +) ((var a) (const 1)))))
(lambda-simple (b) (set (var a) (var b))))))

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

(boxingOfVariables '
(applic
(lambda-simple
(a)
(applic
(var list)
((lambda-simple () (var a))
(lambda-simple
()
(set (var a) (applic (var +) ((var a) (const 1)))))
(lambda-simple (b) (set (var a) (var b))))))
((const 0))))


;(getOccurence 'x '(seq (set (var x) y) (lambda-simple (y) (var x))))
;;;;;;;;fix lambda 
 
