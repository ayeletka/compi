((lambda (y) ((lambda (x)
	(set! y 20)
	((lambda (z)
		(set! x (+ y 10))) 2)
	x) 2)) 2)