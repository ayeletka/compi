
(define a (lambda (x) (lambda (y) (set-car! x y) (set-cdr! x y) x)))

((a (cons 8 #t)) 200)
