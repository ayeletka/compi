


;((lambda (x y) x y) 6 5)  ;5
;((lambda (x y) (lambda (y) x)) 6 5) 
;((lambda (x y) x y) 6 5) ;5

((lambda (x y) (lambda (y) x) y) 6 5) ;5 - but not working!! when two applications of lambda are done one after the other


((lambda (x y) (lambda (y) x) y) 6 5) 

;(+ 1 2)