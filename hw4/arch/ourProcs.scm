(define remainder 
(lambda (num1 num2)
(cond ((and (number? num1) (number? 2) (< num1 num2)) num1)
((and (number? num1) (number? 2)) (remainder (- num1 num2) num2))
(else ""))))

(define list (lambda vars vars))

;works in scheme doesnt work in compiler
(define append
	((lambda ()
  (define loop1
		    (lambda (lst1 lst2)
		    			(if (null? lst1) lst2
			  				(cons (car lst1) (loop1 (cdr lst1) lst2)))))
	(define internalApply
		    (lambda (lst1 lst)
		      			(if (null? lst) lst1
			  				(loop1 lst1 (internalApply (car lst) (cdr lst))))))
    (lambda lst
      (if (null? lst) '()
	  (internalApply (car lst) (cdr lst)))))))


;waiting 4 apply
;(define map (lambda (proc lst1 . restLsts)
;  (define (FalseIfTrue proc lstToRun)
;    (and (pair? lstToRun) (or (proc (car lstToRun)) (FalseIfTrue proc (cdr lstToRun)))))
;  (define (map-helper proc lstToRun)
;    (if (null? lstToRun) '()
;        (cons (proc (car lstToRun)) (map-helper proc (cdr lstToRun)))))
;  (let ((lstToRuns (cons lst1 restLsts)))
;    (if (FalseIfTrue null? lstToRuns) '()
;        (cons (apply proc (map-helper car lstToRuns))
;              (apply map proc (map-helper cdr lstToRuns)))))))