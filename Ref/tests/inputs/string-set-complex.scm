(define str (make-string 5 (integer->char 83)))

(define a (lambda (x) (lambda (y) (lambda (z) (string-set! x y z)) ))) 

(((a str) 3) (integer->char 98))

str