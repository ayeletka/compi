(define vec (make-vector 3 5)) 


(define setter (lambda ()
  (vector-set! vec 0 #t)
  (vector-set! vec 1 '())
))

(setter)

vec
