

(let ((ls '(1 "hi" 3 (#f #t () "hi") 5 6)))


(eq? (car (cdr ls)) (car (cdr (cdr (cdr (car (cdr (cdr (cdr ls)))))))))
  

)
