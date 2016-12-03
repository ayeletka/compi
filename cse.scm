

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
			(let ((newVar (gensym)))
				(list newVar var)))
			 rlst)
		))

(define minFinder
	(lambda (lst)
		 (cond ((null? (cdr lst)) (car lst))
          ((< (length (car lst)) (length (minFinder (cdr lst)))) (car lst))
          (else (minFinder (cdr lst)))) ))

(define sortLst
	(lambda (lst)
		(letrec ((loop (lambda (newLst lst2)
					(if (null? lst2) (append newLst lst2)
						(let ((minf (minFinder lst2)))
						(loop (append newLst (list minf)) (remove minf lst2))
				))))
			)
		(loop (list) lst))
		)
	)

(define maxFinder
	(lambda (lst)
		 (cond ((null? (cdr lst)) (car lst))
          ((> (length (car lst)) (length (maxFinder (cdr lst)))) (car lst))
          (else (maxFinder (cdr lst)))) ))

(define reSortLst
	(lambda (lst)
		(letrec ((loop (lambda (newLst lst2)
					(if (null? lst2) (append newLst lst2)
						(let ((maxf (maxFinder lst2)))
						(loop (append newLst (list maxf)) (remove maxf lst2))
				))))
			)
		(loop (list) lst))
		)
	)


(define swap 
	(lambda (oldVar newVar lst)
		(cond 
			((not (list? lst)) lst)
			((null? lst) lst)
			((equal? lst oldVar) newVar)
			(else
				(cons
					(swap oldVar newVar (car lst))
					(swap oldVar newVar (cdr lst)))))))

;(swap '(a) '(new) '((a) (b) (a)))


(define swapVars
	(lambda (exp)
		(append  (list (car exp)) (swap (cadar exp) (caar exp) (cdr exp)))))

(define swapped
	(lambda (exp)
		(let ((newExp exp))
			(if (null? exp) exp
				(begin 
					(set! newExp (swapVars exp))
					(append (list (car newExp))
					(swapped (cdr newExp))))
		))
	))

(define swapped-body
	(lambda (vars exp)
		(let ((newExp exp))
			(begin (map
				(lambda (var)
					(set! newExp (swap (cadr var) (car var) newExp))) vars)
			newExp)
		))
	)

(define cse
	(lambda (exp)
		(let* (
				(rlist (recurringList exp))
				(srlist (sortLst rlist))
				(letVars (gensymVars srlist))
				(swapedVars (swapped letVars))
				(swapedBody (swapped-body (reSortLst swapedVars) exp)))

		;(display letVars)
		(display `(let* ,swapedVars ,swapedBody))
		)))


(cse '((b) ))


(cse '((b) (b)))

(cse '(+ (* (- x y) (* x x))
(* x x)
(foo (- x y))
(goo (* (- x y) (* x x)))))



(cse '(f (g x)
(g (g x))
(h (g (g x)) (g x))
((g x) (g x))))