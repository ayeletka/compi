(define funcifunc 
    (lambda (x) (lambda ls (lambda(z) (x z ls))))) 


(define x (cons 0 0))

(set-car! x (((funcifunc apply) 1 2 3) +))

x