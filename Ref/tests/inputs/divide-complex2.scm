

(define 4-arty (lambda (x y z w) (/ x y z w)))

(+ 5 6 ((lambda (x y z . w) (4-arty x y z (car w))) 5000 100 5 2))
