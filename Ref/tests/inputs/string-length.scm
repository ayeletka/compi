(define str (make-string 9 (integer->char 55)))

(and (= (string-length str) 9) (= (string-length (make-string 2)) 2) (= (string-length (make-string 0)) 0))
