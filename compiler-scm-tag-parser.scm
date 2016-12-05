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
			((not var) var) ;;;check how boolean is received and parsed
			((null? var) var)
			((vector? var) var)
			((equal? var #t) var)
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

(define reserved-words?
	(lambda (var)
		(not (ormap (lambda (rw)
					 (equal? rw var)) *reserved-words*))))

(define var?
	(lambda (var)
		(cond 
			((and (symbol? var) 
				(reserved-words? var)) var)
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

;;;;;;macro helpres;;;;;;;
(define MIT-define-to-regular-define
	(lambda (var&params exp)
			`(def ,(car var&params) (lambda ,(cdr var&params) ,exp))))

(define letVariables?
	(lambda (lst)
		(and (list? lst) (andmap 
			(lambda (vals) (and (pair? vals) (equal? (length vals) 2))) lst))))

(define vals-getter
	(lambda (lst)
		(map cadr lst)))

(define validList?
	(lambda (lst)
		(if (null? lst) #t
			(if (member (car lst) (cdr lst)) #f
				(validList? (cdr lst))))))

(define vars-getter
	(lambda (var lst)
		(let ((vars (cons var (map car lst))))
			(if (validList? vars)
				vars
				(error 'let "Variables must be different")))))

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
				;;;;;;;; sequences i.e. begin
				(pattern-rule
					`(begin ,(? 'args) . ,(? 'rest))
					(lambda (args rest) `(seq (,(parse args) ,@(map parse rest)))))
				;;;;;;;; let-sequences i.e. begin
				(pattern-rule
					`(letseq ,(? 'args list?))
					(lambda (args) (map parse args)))
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
				;;;; define
				(pattern-rule
					`(define ,(? 'var&params)  ,(? 'exp))
					(lambda (var&params exp) 
					(if (pair? var&params)
						 (parse (MIT-define-to-regular-define var&params exp))
						 `(def ,(parse var&params) ,(parse exp))))
				)
				;;;;;;set;;;;;;
				(pattern-rule 
					`(set! ,(? 'var var?) ,(? 'exp))
						(lambda (var exp)
							`(set ,(parse var) ,(parse exp))))
				;;;; applic
				(pattern-rule
					`( ,(? 'func reserved-words?) . ,(? 'rest) )
					(lambda (func rest)
						`(applic ,(parse func) ,(map parse rest))
						))
				;;;;;;;;;;empty let ;;;;;;;;
				(pattern-rule
					`(let ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;;;;;;;;let ;;;;;;;;;
				(pattern-rule
					`(let ((,(? 'var var?) ,(? 'val)) . ,(? 'rest letVariables?)) . ,(? 'exprs))
					(lambda (var val rest exprs)
						(let ((vals (cons val (vals-getter rest)))
								(vars (vars-getter var rest)))
							(parse
								`((lambda (,@vars)
									,@exprs) ,@vals)))))
				;;;;; empty let* ;;;;;;;;;;;
				(pattern-rule
					`(let* ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;; let * ;;;;;;;
				(pattern-rule
					`(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
					(lambda (var val rest exprs) (parse `(let ((,var ,val)) (let* ,rest . ,exprs)))))
				)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))

 
