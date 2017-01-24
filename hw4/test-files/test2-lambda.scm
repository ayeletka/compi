
;(define tst-simple (lambda (a) a))
;(tst-simple 1)

(define tst (lambda (a c . b) a))

(tst 1 2 3 4)

;(define tst-simple (lambda (a) a))
;(tst-simple 1)


;(define tst (lambda (a c d . b) b))
;(tst 23 23 22 21 22)


;(define tst (lambda a a))
;(tst 22)

;'(2 3 4)
;((lambda (x y) (set! x 6) x ) 3 4)
;((lambda (x y) x y) 6 5)  ;5
;((lambda (x y) (lambda (y) x)) 6 5) 
;((lambda (x y) x y) 6 5) ;5
;((lambda (x y) (lambda (y) x) y) 6 5) ;5 - but not working!! when two applications of lambda are done one after the other
;((lambda (x y) (lambda (y) x) y) 6 5) 
;(+ 1 2)