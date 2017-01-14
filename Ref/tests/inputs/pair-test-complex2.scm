 
(define ls '(1 2 3 "hir"))
 
(define a (lambda(x) "hir" (if (= x 0) "hir" (a (- x 1)))) )


(eq? (a 1000) (car (cdr (cdr (cdr ls)))))