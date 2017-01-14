
(define vec '#(#t #f () 5))

(if (and (= 5 (vector-ref vec 3)) (eq? #\c (integer->char 99)) )
  (begin (vector-set! vec 2 3) vec)
  #f
)
