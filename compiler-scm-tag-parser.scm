(load "pattern-matcher.scm")
;;;;;;;; tag-parse-2r;;;;;;;
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
			((equal? var #f) #t) ;;;check how boolean is received and parse-2d
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
			`(define ,(car var&params) (lambda ,(cdr var&params) ,exp))))

(define letVariables?
	(lambda (lst)
		(and (list? lst) (andmap 
			(lambda (vals) (and (pair? vals) (equal? (length vals) 2))) lst))))

(define vals-getter
	(lambda (lst)
		(map cadr lst)))

(define validList?
	(lambda (lst)
		(let ((lst (if (list? lst) lst (pairToList lst))))
		(if (null? lst) #t
			(if (member (car lst) (cdr lst)) #f
				(validList? (cdr lst)))))))

(define pairToList
	(lambda (lst)
		(letrec ((loop (lambda (lst rest)
					(if (not (pair? rest)) (append lst (list rest))
						(loop (append lst (list (car rest))) (cdr rest))))))
			(loop (list) lst))
	))




			
	


(define vars-getter
	(lambda (var lst)
		(let ((vars (cons var (map car lst))))
			(if (validList? vars)
				vars
				(error 'let "Variables must be different")))))



(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
	   (eq? (car e) tag)
	   (pair? (cdr e))
	   (null? (cddr e))))))

(define quote? (^quote? 'quote))
(define unquote? (^quote? 'unquote))
(define unquote-splicing? (^quote? 'unquote-splicing))

(define const-quasi?
  (let ((simple-sexprs-predicates
	 (list boolean? char? number? string?)))
    (lambda (e)
      (or (ormap (lambda (p?) (p? e))
		 simple-sexprs-predicates)
	  (quote? e)))))

(define quotify
  (lambda (e)
    (if (or (null? e)
	    (pair? e)
	    (symbol? e)
	    (vector? e))
	`',e
	e)))

(define unquotify
  (lambda (e)
    (if (quote? e)
	(cadr e)
	e)))

(define const-pair?
  (lambda (e)
    (and (quote? e)
	 (pair? (cadr e)))))

(define expand-qq
  (letrec ((expand-qq
	    (lambda (e)
	      (cond ((unquote? e) (cadr e))
		    ((unquote-splicing? e)
		     (error 'expand-qq
		       "unquote-splicing here makes no sense!"))
		    ((pair? e)
		     (let ((a (car e))
			   (b (cdr e)))
		       (cond ((unquote-splicing? a)
			      `(append ,(cadr a) ,(expand-qq b)))
			     ((unquote-splicing? b)
			      `(cons ,(expand-qq a) ,(cadr b)))
			     (else `(cons ,(expand-qq a) ,(expand-qq b))))))
		    ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
		    ((or (null? e) (symbol? e)) `',e)
		    (else e))))
	   (optimize-qq-expansion (lambda (e) (optimizer e (lambda () e))))
	   (optimizer
	    (compose-patterns
	     (pattern-rule
	      `(append ,(? 'e) '())
	      (lambda (e) (optimize-qq-expansion e)))
	     (pattern-rule
	      `(append ,(? 'c1 const-pair?) (cons ,(? 'c2 const-quasi?) ,(? 'e)))
	      (lambda (c1 c2 e)
		(let ((c (quotify `(,@(unquotify c1) ,(unquotify c2))))
		      (e (optimize-qq-expansion e)))
		  (optimize-qq-expansion `(append ,c ,e)))))
	     (pattern-rule
	      `(append ,(? 'c1 const-pair?) ,(? 'c2 const-pair?))
	      (lambda (c1 c2)
		(let ((c (quotify (append (unquotify c1) (unquotify c2)))))
		  c)))
	     (pattern-rule
	      `(append ,(? 'e1) ,(? 'e2))
	      (lambda (e1 e2)
		(let ((e1 (optimize-qq-expansion e1))
		      (e2 (optimize-qq-expansion e2)))
		  `(append ,e1 ,e2))))
	     (pattern-rule
	      `(cons ,(? 'c1 const-quasi?) (cons ,(? 'c2 const-quasi?) ,(? 'e)))
	      (lambda (c1 c2 e)
		(let ((c (quotify (list (unquotify c1) (unquotify c2))))
		      (e (optimize-qq-expansion e)))
		  (optimize-qq-expansion `(append ,c ,e)))))
	     (pattern-rule
	      `(cons ,(? 'e1) ,(? 'e2))
	      (lambda (e1 e2)
		(let ((e1 (optimize-qq-expansion e1))
		      (e2 (optimize-qq-expansion e2)))
		  (if (and (const-quasi? e1) (const-quasi? e2))
		      (quotify (cons (unquotify e1) (unquotify e2)))
		      `(cons ,e1 ,e2))))))))
    (lambda (e)
      (optimize-qq-expansion
       (expand-qq e)))))

(define parse-2
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
					(lambda (test dit) `(if3 ,(parse-2 test) ,(parse-2 dit) (const ,*void-object*))))
				;;;; if 3 params
				(pattern-rule
					`(if ,(? 'test) ,(? 'dit) ,(? 'dif))
					(lambda (test dit dif) `(if3 ,(parse-2 test) ,(parse-2 dit) ,(parse-2 dif))))
				;;;;; or
				(pattern-rule
					`(or . ,(? 'rest))
					(lambda (rest) 
						(cond 
							((null? rest) (parse-2 #f))
							((equal? (length rest) 1) (parse-2 (car rest)))
							(else `(or ,(map parse-2 rest))))))
				;;;;;;;; sequences i.e. begin
				(pattern-rule
					`(begin . ,(? 'rest))
					(lambda (rest) 
						(cond ((null? rest) `(const ,*void-object*))
								((equal? (length rest) 1) (parse-2 (car rest)))
								(else `(seq ,(map parse-2 rest))))))
				;;;;;;;; let-sequences i.e. begin
				(pattern-rule
					`(letseq ,(? 'args list?))
					(lambda (args) (map parse-2 args)))
				;;;; regular lambda 
				(pattern-rule
					`(lambda ,(? 'vars list? validList?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-simple ,vars ,(parse-2 (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;; lambda optional args
				(pattern-rule
					`(lambda ,(? 'vars pair? validList?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-opt ,@(improper-list? vars) ,(parse-2 (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;;; variadic lambda
				(pattern-rule 
					`(lambda ,(? 'var validList?) . ,(? 'rest))
					(lambda (var rest) `(lambda-var ,var ,(parse-2 (beginify rest))))) ;notice begin is not memomash, WTF args
				;;;; define
				(pattern-rule
					`(define ,(? 'var&params)  ,(? 'exp))
					(lambda (var&params exp) 
					(if (pair? var&params)
						 (parse-2 (MIT-define-to-regular-define var&params exp))
						 `(def ,(parse-2 var&params) ,(parse-2 exp))))
				)
				;;;;;;set;;;;;;
				(pattern-rule 
					`(set! ,(? 'var var?) ,(? 'exp))
						(lambda (var exp)
							`(set ,(parse-2 var) ,(parse-2 exp))))
				;;;;;;;;;;; quasi quote ;;;;;;;;;;;;
				(pattern-rule
					`(quasiquote . ,(? 'expr))
					(lambda (expr)
						(if (or (null? expr) (> (length expr) 1))
							(error 'quasiquote "wrong params")
						(parse-2 (expand-qq (car expr))))
						))
				;;;;;;;;;;;; unqoute;;;;;;;;
				(pattern-rule
					`(unqoute . ,(? 'expr))
					(lambda (expr)
						(expand-qq expr)))
				;;;;;;;;;;;; unqoute-splicing;;;;;;;;
				(pattern-rule
					`(unquote-splicing . ,(? 'expr))
					(lambda (expr)
						(expand-qq expr)))
				;;;; applic
				(pattern-rule
					`( ,(? 'func reserved-words?) . ,(? 'rest) )
					(lambda (func rest)
						`(applic ,(parse-2 func) ,(map parse-2 rest))
						))
				;;;;;;;;;;;empty letrec ;;;;;;;;;
				(pattern-rule
					`(letrec ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse-2
								`((lambda ()
										((lambda () ,(beginify (cons expr exprs)))
										 ,@vars))	
									,@vars)
								)))
				;;;;;;;;;;;letrec ;;;;;;;;;
				(pattern-rule
					`(letrec ((,(? 'var var?) ,(? 'val)) . ,(? 'rest letVariables?)) . ,(? 'exprs))
					(lambda (var val rest exprs)
						(let* ((vals (cons val (vals-getter rest)))
								(vars (vars-getter var rest))
								(sets (map (lambda (var2 val2)
													`(set! ,var2 ,val2))
													 vars vals))
								(emptylst (list))
								(falsevars (map (lambda (val) '#f) vals)))
							(parse-2
								`((lambda (,@vars)
									,(beginify 
										`(,@sets ((lambda () ,@exprs) ,@emptylst))	
									)) 
									,@falsevars
								)))))
				;;;;;;;;;;empty let ;;;;;;;;
				(pattern-rule
					`(let ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse-2 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;;;;;;;;let ;;;;;;;;;
				(pattern-rule
					`(let ((,(? 'var var?) ,(? 'val)) . ,(? 'rest letVariables?)) . ,(? 'exprs))
					(lambda (var val rest exprs)
						(let ((vals (cons val (vals-getter rest)))
								(vars (vars-getter var rest)))
							(parse-2
								`((lambda (,@vars)
									,@exprs) ,@vals)))))
				;;;;; empty let* ;;;;;;;;;;;
				(pattern-rule
					`(let* ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse-2 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;; let * ;;;;;;;
				(pattern-rule
					`(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
					(lambda (var val rest exprs) 
						(if (not (null? rest))
							(parse-2 `(let ((,var ,val)) 
								(let* ,rest . ,exprs)))
							(parse-2 `(let ((,var ,val)) 
								,@exprs)))))

				;;;;;;;;; and ;;;;;;;
				(pattern-rule
					`(and . ,(? 'vals))
					(lambda (vals) 
						(cond ((null? vals) (parse-2 #t))
							((equal? (length vals) 1) (parse-2 (car vals)))
							((equal? (length vals) 2)
								(parse-2 `(if ,(car vals) ,(cadr vals) #f)))
							(else
								(parse-2 `(if ,(car vals) (and ,@(cdr vals)) #f))))))
				;;;;;;;;; cond ;;;;;;;
				(pattern-rule
					`(cond . ,(? 'vals))
					(lambda (vals) 
						(cond 
							((and (equal? (length vals) 2) (equal? (caadr vals) 'else))
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals)))
									(elseseq (if (> (length (cdadr vals)) 1) (beginify (cdadr vals))
													(cadadr vals))))
								(parse-2 
									`(if ,(caar vals) ,conseq ,elseseq)
									)))
							((equal? (length vals) 1)
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals))))
							 			(parse-2 `(if ,(caar vals) ,conseq))))
							(else 
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals))))
									(parse-2 `(if ,(caar vals) ,conseq
														(cond ,@(cdr vals))
									)))
								)
							)))

				)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse-2
									(format "I can't recognize this: ~s" e)))))))


(validList? '(a c . a))