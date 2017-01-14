(define a (lambda (str) 
(lambda (x) (string-ref str x))  
)) 


((a (make-string 5 (integer->char 71))) 4)