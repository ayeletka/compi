(print-gensym #f)
; Change to your own location
(load "cse.scm")
(load "cse.so")

(define my-parse-func cse-2)
(define staff-parse-func cse)

(define a (lambda args 1))
(define b (lambda args 2))
(define c (lambda args 3))
(define foo (lambda args 3))
(define goo (lambda args 13))
(define f (lambda args 5))
(define g (lambda args (lambda args 6)))
(define h (lambda args 7))
(define x 5)
(define y 12)
(define z 18)

(define eval-input
  (lambda (cse input)
    (eval (cse input))
))    

(define replace-gensym
  (lambda (exp-lst)
    (if (null? exp) '()
    (map (lambda (el) 
      (cond             
      ((gensym? el) (symbol->string el))
      ((not (pair? el)) el)
      ((list? el) (replace-gensym el))
      (else (append (replace-gensym (car exp-lst)) (replace-gensym (cdr exp-lst)))))) exp-lst))
))

(define verify-equality
  (lambda (input staff-res my-res)
    (and 
      (equal? (car staff-res) (car my-res))
      (equal? (length (cadr staff-res)) (length (cadr my-res)))
      (equal? (length (cddr staff-res)) (length (cddr my-res)))
      (equal? (eval-input staff-parse-func input) (eval-input my-parse-func input)))      
))      

(define testVSstaff
  (lambda (input)
    (begin (display input)
    (let* ((my-res (begin (gensym-count 0) (replace-gensym (my-parse-func input))))
          (staff-res (begin (gensym-count 0) (replace-gensym (staff-parse-func input)))))     
      ;(display (format "\n => ~s\n" my-res))
      (cond ((or (equal? staff-res my-res) (verify-equality input staff-res my-res))
        (display (format "\033[1;32m Success! ☺ \033[0m \n")) #t)
        (else 
        (display (format "\033[1;31m Failed! ☹\033[0m , Expected: ~s, Actual: ~s \n" staff-res my-res)) #f))
      ))))
      
      
(define runTests
  (lambda (tests-name lst)
  (newline)
  (display (format "\033[1m~s" tests-name))
  (display ":")
  (newline)
  (display "================\033[0m")
  (newline)
  (let ((results (map testVSstaff lst)))
  (newline)
  (cond ((andmap (lambda (exp) (equal? exp #t)) results)  
    (display (format "\033[1;32m~s Tests: SUCCESS! ☺ \033[0m\n \n" tests-name)) #t)   
    (else
    (display (format "\033[1;31m~s Tests: FAILED! ☹ \033[0m\n \n" tests-name)) #f)))
))

(define runAllTests
  (lambda (lst)
    (let ((results (map (lambda (test) (runTests (car test) (cdr test))) lst)))
        (cond ((andmap (lambda (exp) (equal? exp #t)) results)    
    (display "\033[1;32m !!!!!  ☺  ALL TESTS SUCCEEDED  ☺  !!!!\033[0m\n"))
    (else (display "\033[1;31m #####  ☹  SOME TESTS FAILED  ☹  #####\033[0m\n")))
    (newline))
))

(define quotedListsTests
  (list 
      '(append '(a b c d e) '(a b c d e) '(g f h) '(a b c d e) '(a b c d e) '(a b c d e) '(g f h))
      '(g (f '('(1 2 3 4 5 6 7 8 9 0) '(a b c d e)) (list f g h) '('(1 2 3 4 5 6 7 8 9 0) '(a b c d e))) (list f g h))
      '(list '(a b) (list '(a b) '(c d)) (list '(a b) '(c d)))
     ; '(f (+ x 1) (f x) (g x) (lambda (x) (f x)) (+ x 1))
     ; '(begin '(a b) '(a b))       
))

(define otherTests
  (list
    '(* (+ 2 (f 3 5) 4) (+ 2 (f 3 5) 4))   
    '(+ (+ 1 2 3) (+ 4 5 6) (+ 1 2 3) (+ 4 5 6))
    '(a (a 1) (b 2) (a 1) (b 2) (c 3) (c 3))
    '(f (c (a b)) (a b) (c (a b)))
    '(f (c (a b)) (a b) (c (a b)) (a b))    
    '(foo (a b b b b b b))
    '(foo (a (b b) (b c) (b b) (b c) (b b) (b c)))
    '(begin (a) (a) (b) (b) (b) (c) (c) (c) (c))
    '(foo (a) (a) (b) (b) (b) (b) (c) (c) (c))
    '(foo (a) (b) (c) (b) (c) (b) (c) (a))
    '(begin (define goo (a (b b) (b c) (b b) (b c) (b b) (b c))) (a b))
   ; '(a (f (+ g h) 1 (g (+ g h) (+ g h)) 3 (g (+ g h) (+ g h)) (+ g h)))
    ;'(f '('(+ x 1)) (f x) (g x) (lambda (x) (f x)) '(+ x 1))
    ;'(begin '(a b) '(a b))     
    '(+ (+ (+ x 2) 1) (+ (+ x 2) 1) (+ (+ x 2) 1) (+ (+ x 2) 1)) 
    '(let ((a (+ x 1)) (b (+ x 1)))
      (let ((c (+ x 1)) (d (+ x 1)))
       (* a b c d)))
  ;  '(((((((((((+ x 1)))))))))) ((((((((((+ x 1)))))))))))
    '(list (list (list + 2 1)) (list (list + 2 1)))
    '(* (+ (+ 1 (+ 2 (- 3 (+ 4 5))))) (+ (+ 1 (+ 2 (- 3 (+ 4 5))))))
    '(* (+ (* 1 (+ 2 (- 3 (+ 4 5))))) (+ (* 6 (+ 7 (- 8 (+ 4 5))))) (+ (* 9 (+ 10 (- 11 (+ 4 5))))) (+ (* 12 (+ 13 (- 14 (+ 4 5))))))
))

(define mayerExamplesTests
  (list  
    '(+ 2 3)
    '(f (f (f (f x))))
    '(* (+ 2 3 4) (+ 2 3 4))
    '(f (g x y) (f (g x y) z))       
    '(+ (* (- x y) (* x x)) (* x x) (foo (- x y)) (goo (* (- x y) (* x x))))
    '(f (g x) (g (g x)) (h (g (g x)) (g x)) ((g x) (g x)))
    '(list (cons 'a 'b) (cons 'a 'b) (list (cons 'a 'b) (cons 'a 'b)) (list (list (cons 'a 'b) (cons 'a 'b))))
    '(list '(a b) (list '(a b) '(c d)) (list '(a b) '(c d)))
))

(display (format "\033[1mComp171 - CSE Tests\033[0m\n====================\n"))

(runAllTests
  (list
      (cons "Mayer Examples" mayerExamplesTests)     
      (cons "Quoted Lists" quotedListsTests)   
      (cons "Other Tests" otherTests)       
))