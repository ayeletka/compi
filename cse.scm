



(define isMember?
	(lambda (var exp)
		(letrec 
			((counter2 0)
			(loop (lambda (exp2)
				(if (or (not (list? exp2)) (null? exp2)) counter2
					(let ((varCar (car exp2))
						 (rest (cdr exp2)))
						(cond 
							((or (not (list? varCar)) (null? varCar)) (loop rest))
							(else 
								(if (equal? var varCar) 
									(begin 
										(set! counter2 (+ counter2 1))
										(loop rest))
									(begin 
										(loop varCar)
										(loop rest))
									))))))))
		(begin (loop exp)
		(>= counter2 2)))))





(define const?
  (lambda (exp)
    (cond ((not (list? exp)) #t)
          ((and (list? exp) (not (> (length exp) 1))) #f)
            ((and (list? exp) (> (length exp) 1) (not (equal? (car exp) 'quote))) #f)
             (else #t))))
              




(define recurringList
	(lambda (exp)
		(letrec ((rlist (list))
			(loop (lambda (exp2 rest)
				(if (and (list? exp2) (not (null? exp2)) (not (const? exp2)))
					(let ((var (car exp2))
						(newRest (cdr exp2)))
						(if (and (list? var) (not (null? var)) (not (const? var))) 
							 (if (and (isMember? var  rest) (not (member var rlist)))
											(begin (set! rlist (append rlist (list var)))
													(loop newRest rest))
											(if (not (member var rlist)) 
												(begin
												(loop var rest) 
												(loop newRest rest))
												(loop newRest rest)))
							(loop newRest rest)))
				rlist))))
			(loop exp exp))))


(define gensymVars
	(lambda (rlst)
		(map (lambda (var)
			(let ((newVar  (gensym)))
				(list newVar var)))
			 rlst)
		))

(define flatten
	(lambda  (lst)
  		(cond ((null? lst) '())
        	((pair? lst) (append (flatten (car lst)) (flatten (cdr lst))))
        		(else (list lst)))))

(define minFinder
	(lambda (lst)
		 (if (null? (cdr lst)) (car lst)
		 	(let ((lr (minFinder (cdr lst))))
		 		(cond 
		          ((< (length (car lst)) (length lr)) (car lst))
		          ((= (length (car lst)) (length lr))
		          	(if (< (length (flatten (car lst))) (length (flatten lr)))
		          		(car lst)
		          		(minFinder (cdr lst))))
		          (else (minFinder (cdr lst)))) ))))


(define sortLst
	(lambda (lst)
		(letrec ((loop (lambda (newLst lst2)
					(if (null? lst2) (append newLst lst2)
						(let ((minf (minFinder lst2)))
						(loop (append newLst (list minf)) (remove minf lst2))
				)))))
		(loop (list) lst))
		))





(define swap 
	(lambda (oldVar newVar lst)
		(cond 
			((not (list? lst)) lst)
			((const? lst) lst)
			((null? lst) lst)
			((equal? lst oldVar) newVar)
			(else
				(cons
					(swap oldVar newVar (car lst))
					(swap oldVar newVar (cdr lst)))))))



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
		(let* ((newExp exp)
			 (byswap (letrec 
			 	((loop
					(lambda (var rest)
						(set! newExp (swap (cadr var) (car var) newExp))
						(if (null? rest) newExp
							(loop (car rest) (cdr rest))
							))))
			 (loop (car vars) (cdr vars)))))
			byswap
		))
	)




(define *void-object* (void))


(define constEliminator
	(lambda (lst)
		(let ((noConstLst (map
					(lambda (var)
						(if (not (const? var)) var)
						) lst)))
			(remove *void-object* noConstLst))
		))




(define cse-2
	(lambda (exp)
		(let* (
				(rlist (recurringList exp)))
				(if (null? rlist)
					 exp
				(let* (
						(lstNoConst (constEliminator rlist))
						(srlist (sortLst lstNoConst))
						(letVars (gensymVars srlist))
						(swapedVars (swapped letVars))
						(swapedBody (swapped-body swapedVars exp)))
				(if (equal? (length swapedVars) 1) 
					`(let  ,swapedVars  ,swapedBody)
					`(let* ,swapedVars ,swapedBody)))))
		))


