(load "compiler.scm")
(load "compiler3.scm")

(define test1 '(lambda a (begin (+ a 2) (lambda () a)))) ;basic lambda var
(define test2 '(lambda (a b . c) (begin (define d a) (begin (+ 1 2))))) 
(define test3 '(lambda a (lambda () (begin (define d a) (begin (+ 1 2)))))) 
(define test4 '(lambda a (letrec ((a b) (c d)) (lambda (a) a))))	
(define test5 '(lambda a (letrec ((a b) (c d)) (lambda () a)))) ;what happens with seq after seq? should we eliminate secnd seq? from boxing
(define test6 '(lambda (x y z) (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x))))))



;;;;;;;;;;;;;meir examples;;;;;;;;;;
(define *test-expr* '(define my-even? (lambda (e) (define even? (lambda () (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e))))
(define *example* '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b)))))
(define *example-boxing* '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b)))))
;;;;;;;;;;;pe->lex-pe - meir	;;;;;;;
;(pe->lex-pe (parse '(x (lambda (x) (x (lambda () (x (lambda () (x x)))))))))
;(pe->lex-pe (parse '(lambda (a b) (lambda (c) (+ a b c)))))
;(pe->lex-pe (parse '(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1))))))))

;;;;;;;;;;;variables tests;;;;;;;
(define test7 '(lambda x (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x)))))) ;what happens with seq after seq? should we eliminate secnd seq? from boxing
(define test8 '(lambda (x . y) (begin (define x y) (lambda (y) y) (lambda () (begin y (set! y x))))))



;(display '(lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x)))))))

(display "\n")	

(define test-parsed (parse test8))

(display test-parsed)

(display "\n\n")

(define end (eliminate-nested-defines test-parsed))

(display end)

(display "\n\n")

(define raln (remove-applic-lambda-nil end))

(display "\n\n")

(display raln)

(display "\n\n")

(define bs (box-set raln))

(display "\n\n")

(display bs)

(display "\n\n")

(pe->lex-pe bs)
