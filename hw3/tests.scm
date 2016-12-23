(load "compiler.scm")
(load "compiler3.scm")

(define test1 '(lambda a (+ 1 2))) ;basic lambda var
(define test2 '(lambda (a b . c) (begin (define d a) (begin (+ 1 2))))) 
(define test3 '(lambda a (lambda () (begin (define d a) (begin (+ 1 2)))))) ;fails on boxingOfVariables - on cdr
(define test4 '(lambda a (letrec ((a b) (c d)) (lambda (a) a))))	;fails on boxingOfVariables - error does not run right + rename to box-set as stated in assaignment)
(define *test-expr* '(define my-even? (lambda (e) (define even? (lambda () (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e))))
(define *example* '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b)))))



(display "\n")	
(define test-parsed (parse test3))

(display test-parsed)

(display "\n")

(define end (eliminate-nested-defines test-parsed))

(display end)

(display "\n")

(define raln (remove-applic-lambda-nil end))

(display "\n")

(display raln)

(boxingOfVariables raln)
