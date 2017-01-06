(load "compiler.scm")

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

;;;;;;;;;;annotate-tc tests;;;;;;;;;;
(define test9 '(x (lambda (x) (x (lambda () (x (lambda () (x x)))))))) ;; V
(define test11 '(lambda (x y) (begin #t (x x) (y y)))) ;; V

;;;;;;;;;;Removing redundant applications;;;;;;;;;;
(define test12 '(lambda (fact) (letrec ((x 1) (y 2) (a 5)) b1 b2 (or 1 2 3) (if 1 2 3) #t))) ;;V

;;;;;;;;;;boxing tests;;;;;;;;;;
(define test13 '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b))))) ;;V
(define test14 '(lambda (x y z) (begin (set! x y) (lambda (y)  y) (lambda () (begin y (set! y x)))))) ;;V
(define test15 '(lambda (z . a) (list (lambda ()  a) (lambda () (set! a 1 ) (lambda (b) a))))) ;;V
(define test16 '(lambda expr (list (lambda ()  expr) (lambda () (set! expr 1 ) (lambda (b) expr))))) ;;V

;;;;;;;;;Gilad Tests;;;;;;;;;;;
(define test17 '(lambda (x y) (lambda () y x (set! x 1))))
(define test18 '(lambda (f) ((lambda (x) (f (lambda s (apply (x x) s)))) (lambda (x) (f (lambda s (apply (x x) s)))))))
(define test19 '(x (lambda (x) (x (lambda () (x (lambda () (x x))))))))
(define test20 '(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1)))))))
(define test21 '(lambda (x) (x x)))
(define test22 '(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1)))))))
(define test23 '(lambda (a  b) (lambda (c) (+ a b c))))
(define test24 '(x (lambda (x) (x (lambda () (x (lambda () (x x))))))))
(define test25 '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b)))))
(define test26 '(lambda (x) (define a (list? x)) (set! a b)))
(define test27 '(letrec ((a (list? x))) (lambda () a)))
(define test29 '(or (+ 1) (or (+ 2) (+ 3)) (+ 4)))
;(display '(lambda-simple (x y z) (seq (set (var x) (var y)) (lambda-simple (y) (var y)) (lambda-simple () (seq (var y) (set (var y) (var x)))))))

(define test30 '(lambda (x) x (lambda (a b) (set! x 1))))
(define test31 '(lambda () (or (+ 1) (or (+ 2) (+ 3)) (+ 4))))
(define test31 '((lambda () (+ ((lambda () a)) ((lambda () b)) ((lambda () ((lambda () c))))))))
(define test32 '((lambda () 1) 2 3 4))
(define test33 '(lambda (a) a (lambda (b c) (set! a 4) (+ a b) (lambda () (set! b 8)))))
(define test34 '(lambda (z) (define a 5) (define b 123) (lambda (y) (define x 10) 
	(define x1 (lambda (abc) (define a 56) (define x1 10) (+ 1 2))) (f 32 45 'a)) (a 5)))

(define test28  '(define my-even? (lambda (e) (define even? (lambda (n) (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e)))) ;;;many bugs - come back later
(define test35 '(lambda (a) (begin 5 (box-set b 2) (box-get a) #t)))

(display "\n\n parsed: \n\n")	

(define test-parsed (parse test35))

test-parsed

(display "\n\n eliminate-nested-defines: \n\n")

(define end (eliminate-nested-defines test-parsed))

end
(display "\n\n remove-applic-lambda-nil: \n\n")

(define raln (remove-applic-lambda-nil end))

 raln

(display "\n\n boxing: \n\n")

(define bs (box-set raln))

 bs

(display "\n\n lexing: \n\n")

(define lex (pe->lex-pe bs))
 lex

(display "\n\n tail: \n\n")

(annotate-tc lex)

