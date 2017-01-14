(define x 
  (lambda (n)
    (letrec ((fact 
      (lambda (n) (if (= n 0) 1 (* n (fact (- n 1)))))
      
    ))
    (fact n)
    )
  ))


(x 6)
