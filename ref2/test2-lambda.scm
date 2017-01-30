(define tst (lambda (a b) ((lambda (b) (+ a b)) b)))

(tst 1 2)
