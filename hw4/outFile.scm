(define min 
		(lambda lst
		  (if (null? (cdr lst)) (car lst)
		    (if (< (car lst) (apply min (cdr lst)))
			  (car lst)
			  (apply min (cdr lst))))))
	   (apply min '(6 8 3 2 5))