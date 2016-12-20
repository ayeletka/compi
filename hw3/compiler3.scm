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

(define boundHelper 
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

(define boundOccurence 
	(lambda (var exp) 
		(letrec ((isBoundOccurence #f)
				(loop (lambda (exp2)
						(cond 
							((not (list? exp2)) (void))
							((null? exp2) (void))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									(not (member var (cadr exp2))))
								 			(if (boundHelper var (caddr exp2)) (set! isBoundOccurence #t) (void)))
							((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
									 (member var (cadr exp2)))
											(void))
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
									(if (and (boundOccurence (cadr var) (caddr exp)) (setExpression (cadr var) (caddr exp)) (getOccurence (cadr var) (caddr exp))) 
										var
										(void))) 	
							(cadr exp))
				))
		(remove (void) varsToBox)))
	)


(createBoxingLst '(lambda-simple ((var x) (var y) (var z)) (seq (set (var x) y) (lambda-simple (y) (var z)) (lambda-simple () (seq (var y) (set (var y) (var z)))))))

;(getOccurence 'x '(seq (set (var x) y) (lambda-simple (y) (var x))))
;;;;;;;;fix lambda 
