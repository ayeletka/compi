(((((lambda (x) ((x x) (x x)))
    (lambda (x) (lambda (y) (x (x y)))))
   (lambda (x) (x (lambda (x) (lambda (y) (lambda (z) ((z y) x)))))))
  (lambda (x) ((x #f) #t)))
 (lambda (x) (lambda (y) y)))


(define a 2)

(set! a 3)

a
