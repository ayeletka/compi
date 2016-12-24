(load "compiler.scm")
(load "compiler3.scm")

(define test1 '(lambda a (begin (+ a 2) (lambda () a)))) ;basic lambda var
(define test2 '(lambda (a b . c) (begin (define d a) (begin (+ 1 2))))) 
(define test3 '(lambda a (lambda () (begin (define d a) (begin (+ 1 2)))))) ;fails on boxingOfVariables - on cdr
(define test4 '(lambda a (letrec ((a b) (c d)) (lambda (a) a))))	;fails on boxingOfVariables - error does not run right + rename to box-set as stated in assaignment)
(define test5 '(lambda a (letrec ((a b) (c d)) (lambda () a))))
(define test6 '(lambda (x y z) (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x))))))

(define *test-expr* '(define my-even? (lambda (e) (define even? (lambda () (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e))))
(define *example* '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b)))))



;(display '(lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x)))))))

;;;;;;;;;;;variables tests;;;;;;;
(define test7 '(lambda x (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x))))))

(define test8 '(lambda (x . y) (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x))))))



(display "\n")	

(define test-parsed (parse test8))

;(display test-parsed)

;(display "\n")

(define end (eliminate-nested-defines test-parsed))

;(display end)

;(display "\n")

(define raln (remove-applic-lambda-nil end))

;(display "\n")

;(display raln)
(display "\n")
;(boxingOfVariables raln)

(pe->lex-pe raln)
