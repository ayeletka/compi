(define remainder 
	(lambda (num1 num2) 
		(if (and (number? num1) (number? num2))
			(cond
				((= num1 0) num1)
				((= num2 num1) (- num1 num2))
				((= num2 (- num1)) (+ num2 num1))
				((< num2 0) (remainder num1 (- num2)))
				((and (< num1 0) (> (- num1) num2)) (remainder (- (- (- num1) num2))  num2))
				((< num1 0) num1)
				((> num1 num2) (remainder (- num1 num2) num2))
				(else num1)
				)
			"")))

(define cadr 
	(lambda (x) (car (cdr x))))


(define caar 
	(lambda (x) (car (car x))))

(define cddr 
	(lambda (x) (cdr (cdr x))))

(define caddr 
	(lambda (x) (car (cdr (cdr x))))) 

(define caadr 
	(lambda (x) (car (car (cdr x))))) 

(define cdddr 
	(lambda (x) (cdr (cdr (cdr x))))) 

(define caaar 
	(lambda (x) (car (car (car x))))) 

(define caaadr 
	(lambda (x) (car (car (car (cdr x))))))

(define caaddr 
	(lambda (x) (car (car (cdr (cdr x))))))

(define cadddr 
	(lambda (x) (car (cdr (cdr (cdr x))))))

(define cddddr 
	(lambda (x) (cdr (cdr (cdr (cdr x))))))

(define caaaar 
	(lambda (x) (car (car (car (car x))))))

(define append2Lists
	(lambda (list1 list2)
        (if (null? list1) list2
            (cons (car list1) (append2Lists (cdr list1) list2)))))

(define append
	(lambda lst
		(if (null? lst) lst
			(if (null? (cdr lst)) (car lst)
			(append (cons (append2Lists (car lst) (cadr lst)) (cddr lst)))
		))))

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