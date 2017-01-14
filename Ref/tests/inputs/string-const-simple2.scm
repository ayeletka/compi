(define str "Merry had") 

(define func (lambda () 
    (let ((other-str " a little lambda."))
      (lambda (x)
	(string-append str other-str x)
      )
      
    )
))


((func) "123")