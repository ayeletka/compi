

(define equal?
  
    (letrec ((equal?
	      (lambda (a b)
	
		 ((and (number? a) (number? b)) (= a b))
		 
	)))
      equal?))

(equal? 1 2)