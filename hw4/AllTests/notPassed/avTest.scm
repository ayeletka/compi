; test 144
(begin
    (define vec (make-vector 4))
    (vector-set! vec 1 4)
    (vector-set! vec 3 'a)
    (symbol? (vector-ref vec 3))
    )
