(load "compiler.scm")
(load "compiler3.scm")

(define test1 '(lambda a (+ 1 2))) ;basic lambda var
(define test2 '(lambda (a b . c) (begin (define d a) (begin (+ 1 2))))) ;does not pass eliminate-nested-defines
(define test3 '(lambda a (lambda () (begin (define d a) (begin (+ 1 2))))))
(define test4 '(lambda a (letrec ((a b) (c d)) (lambda (a) c))))
(define *test-expr* '(define my-even? (lambda (e) (define even? (lambda () (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e))))



(display "\n")	
(define test-parsed (parse test4))

(display test-parsed)

(display "\n")

(define end (eliminate-nested-defines test-parsed))

(display end)

(display "\n")

(remove-applic-lambda-nil end)