

(define isMember?
	(lambda (var exp)
		(letrec 
			((counter2 0)
			(loop (lambda (exp2)
			(cond 
				((or (not (list? exp2)) (null? exp2)) counter2)
				(else 
					(if (equal? var exp2) 
						(begin 
							(set! counter2 (+ counter2 1))
							(loop (car exp2) )
							(loop (cdr exp2) ) )
						(begin 
							(loop (car exp2))
							(loop (cdr exp2)))
						))))))
		(begin (loop exp)
		(>= counter2 2)))))


(define recurringList
	(lambda (exp)
		(letrec ((rlist (list))
			(loop (lambda (exp2 rest)
				(if (list? exp2)
					(let ((var (car exp2))
						(newRest (cdr exp2)))
					(if (list? var)
							(if (and (isMember? var (list newRest rest)) (not (member var rlist)))
									(begin (set! rlist (append rlist (list var)))
									(loop (car var) newRest)
									(if (null? (cdr var)) rlist (loop (cdr var) (cdr var)))
									(if (null? newRest) rlist (loop newRest newRest))
									)
								(begin
								(loop var newRest)
								(if (null? (cdr var)) rlist (loop (cdr var) (cdr var)))
								(if (null? newRest) rlist (loop newRest newRest))))
							(if (null? newRest) rlist (loop newRest (list newRest rest)))))
					rlist))))
			(loop exp exp))))



(define gensymVars
	(lambda (rlst)
		(map (lambda (var)
				(list (gensym "#:g") var))
			 rlst)
		))


(define cse
	(lambda (exp)
		(let ((rlist (recurringList exp)))
			(gensymVars rlist)
		)))


(cse '((b) (b)))

(cse '(+ (* (- x y) (* x x))
(* x x)
(foo (- x y))
(goo (* (- x y) (* x x)))))
