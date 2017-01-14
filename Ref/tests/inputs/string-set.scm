(let ((str (make-string 4 (integer->char 61)))
      )

  (string-set! str 3 (integer->char 60)) 
  (string-set! str 2 (integer->char 59)) 
  (string-set! str 1 (integer->char 58))
  (string-set! str 0 (integer->char 57))
  str
)