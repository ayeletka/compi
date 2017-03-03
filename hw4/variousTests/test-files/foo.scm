(((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 (lambda (p )a))))
   #f #f)
  #f #f #f)
 #t) #f)

    ;works
((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 b)))
   #f #t)
  #f #f #f)
 #f)

   ;works
((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 c)))
   #f #f)
  #t #f #f)
 #f)

  ;works
((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 d)))
   #f #f)
  #f #t #f)
 #f)

 ;works
((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 e)))
   #f #f)
  #f #f #t)
 #f)

;works
((((lambda (a b)
     (lambda (c d e)
       (lambda (a)
	 a)))
   #f #f)
  #f #f #f)
 #t)
