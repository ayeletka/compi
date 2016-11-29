(load "pattern-matcher.scm")
;;;;;;;; tag-parser;;;;;;;
(define beginify
	(lambda (s)
		(cond
			((null? s) *void-object*)
			((null? (cdr s)) (car s))
			(else `(begin ,@s)))))


(define simple-const?
	(lambda (var)
		(cond 
			((null? var) var)
			((vector? var) var)
			((equal? var #t) var)
			((equal? var #f) var) ;;;check how boolean is received and parsed
			((char? var) var)
			((number? var) var)
			((string? var) var)
			(else #f)
			)
		))

(define *reserved-words*
	'(and begin cond define do else if lambda
		let let* letrec or quasiquote unquote
		unquote-splicing quote set!))

(define var?
	(lambda (var)
		(cond 
			((and (symbol? var) 
				(not (ormap (lambda (rw)
					 (equal? rw var)) *reserved-words*))) var)
			(else #f)
			)))

(define *void-object* (void))

(define improper-list?
	(lambda (vars)
		(if (pair? vars)
				(letrec ((loop 
							(lambda (lst rest)
								(cond 
									 ((pair? rest) (loop `(,@lst ,(car rest)) (cdr rest)))
									 (else (list lst rest))))))
				(loop (list) vars))
			#f
			)))

(define parse
	(let ((run 
			(compose-patterns
				;;;;const
				(pattern-rule
					(? 'c simple-const?)
					(lambda (c) `(const ,c)))
				;;;;qoute-const
				(pattern-rule
					`(quote ,(? 'c))
					(lambda (c) `(const ,c)))
				;;;;variable
				(pattern-rule
					(? 'v var?)
					(lambda (v) `(var ,v)))
				;;;; if 2 parms
				(pattern-rule
					`(if ,(? 'test) ,(? 'dit))
					(lambda (test dit) `(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
				;;;; if 3 params
				(pattern-rule
					`(if ,(? 'test) ,(? 'dit) ,(? 'dif))
					(lambda (test dit dif) `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
				;;;;; or
				(pattern-rule
					`(or . ,(? 'rest))
					(lambda (rest) `(or ,(map parse rest))))
				;;;; regular lambda 
				(pattern-rule
					`(lambda ,(? 'vars list?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-simple ,vars ,(parse (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;; lambda optional args
				(pattern-rule
					`(lambda ,(? 'vars pair?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-opt ,@(improper-list? vars) ,(parse (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;;; variadic lambda
				(pattern-rule 
					`(lambda args ,(? 'body) . ,(? 'rest))
					(lambda (body rest) `(lambda-var args ,(parse (beginify (cons body rest)))))) ;notice begin is not memomash, WTF args
				;;;;;;;; sequences i.e. begin
				(pattern-rule
					`(begin ,(? 'args) . ,(? 'rest))
					(lambda (args rest) `(seq (,(parse args) ,@(map parse rest)))))
				;;;;;define
				()
				;;let*
				;(pattern-rule
				;	`(let* () ,(? 'expr) . ,(? 'exprs list?))
				;	(lambda (expr exprs) (parse (beginify (cons expr exprs)))))
				;(pattern-rule
				;	`(let* ((,(? 'var var?) ,(? val?)) . ,(? 'rest)) . ,(? 'exprs))
				;	(lambda (var val rest exprs) (parse `(let ((,var val)) (let* ,rest . ,exprs)))))
				;; add more rules here
				)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))

 
 (parse '(lambda (a) (if a b c) (if a b c)))