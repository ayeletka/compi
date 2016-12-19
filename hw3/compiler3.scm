(load "pattern-matcher.scm")
(load "pc.scm")

(define defGetter
	(lambda (exp rest)
		(letrec ((listDef (list))
				(loop (lambda (exp rest)
						(cond
							((not (list? exp)) `(seq (,@listDef ,exp ,@rest))) 
							((null? exp) listDef)
							((null? rest) (if (equal? (car exp) 'def) 
											(begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) listDef)
											`(seq (,@listDef ,exp))))
							((equal? (car exp) 'def) (begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) (loop (car rest) (cdr rest))))
							(else `(seq (,@listDef ,exp ,@rest)))
				))))
				(loop exp rest)
	)))


(define validSeq?
	(lambda (exp)
		(andmap (lambda (shit) (not (equal? (car shit) 'def))) exp)
	)
)


(define inLambda 
	(let ((run 
			(compose-patterns
				;;;;def
				(pattern-rule
				`(def ,(? 'var) ,(? 'val) )
					(lambda (var val)  `(seq (set ,var ,val)) ))
				;;;;seq
				(pattern-rule
				`(seq ,(? 'exp))
					(lambda (exp)  (let ((defExp (defGetter (car exp) (cdr exp))))
												(if (validSeq? (cadr defExp))
													defExp
													(error 'inLambda "Seq in not a valid seq: ~s" )))
					)) 
		)))  
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))


(define eliminate-nested-defines
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
							((list? (car exp)) `(,(eliminate-nested-defines (car exp)) ,@(eliminate-nested-defines (cdr exp))))
							(else `(,(car exp) ,@(eliminate-nested-defines (cdr exp)))))
						))


		)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))







(eliminate-nested-defines '(def (var my-even?)
(lambda-simple
(e)
(seq ((def (var even?)
(lambda-simple
(n)
(or ((applic (var zero?) ((var n)))
(applic
(var odd?)
((applic (var -) ((var n) (const 1)))))))))
(def (var odd?)
(lambda-simple
(n)
(if3 (applic (var positive?) ((var n)))
(applic
(var even?)
((applic (var -) ((var n) (const 1)))))
(const #f))))
(applic (var even?) ((var e))))))))

