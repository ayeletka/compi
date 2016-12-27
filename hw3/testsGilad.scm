(load "compiler.scm")

(define test-all
    (lambda ()
        (if (null? (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results)))
            ((lambda ()
                (display "================ ALL (")
                (display (length tests))
                (if (= (length tests) 1)
                    (display ") TEST SUCCEEDED ================")
                    (display ") TESTS SUCCEEDED ================"))))
            (begin
                (map
                    (lambda (x) 
                        (display "================ WRONG TEST ================")(newline)
                        (display "Test: ")(newline)(display (car x))(newline)(newline)
                        (display "Excepted: ")(newline)(display (car (cdr x)))(newline)(newline)
                        (display "Actual: ")(newline)(display (car (cdr (cdr x))))(newline)(newline)
                        (newline)(newline))
                    (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results)))
                (display "================ ")
                (display (- (length tests) (length (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results)))))
                (if (= (- (length tests) (length (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results)))) 1)
                    (display " TEST SUCCEEDED ================")
                    (display " TESTS SUCCEEDED ================"))
                (newline)(newline)
                (display "================ ")
                (display (length (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results))))
                (if (= (length (filter (lambda(x) (not (equal? #t x))) (test-func tests mayer-results))) 1)
                    (display " TEST FAILED ================")
                    (display " TESTS FAILED ================"))
                (newline)(newline)
                (void)))))

(define test-func
    (lambda (lst r)
        (if (null? lst)
            '()
            (cons (if (equal? (annotate-tc
                        (pe->lex-pe
                            (box-set
                                (remove-applic-lambda-nil
                                    (eliminate-nested-defines
                                        (parse (car lst)))))))
                                        (car r))

                    #t
                    (list   (car lst)
                            (car r)
                            (annotate-tc
                        (pe->lex-pe
                            (box-set
                                (remove-applic-lambda-nil
                                    (eliminate-nested-defines
                                        (parse (car lst)))))))))
                    (test-func (cdr lst) (cdr r))))))

(define tests
    (list
    
    ;; mayer's

    '(lambda (f) ((lambda (x) (f (lambda s (apply (x x) s)))) (lambda (x) (f (lambda s (apply (x x) s))))))

    '(x (lambda (x) (x (lambda () (x (lambda () (x x)))))))

    '(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1))))))

    '(lambda (x) (x x))

    '(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1))))))

    '(lambda (a  b) (lambda (c) (+ a b c)))

    '(x (lambda (x) (x (lambda () (x (lambda () (x x)))))))


    '(let ((a 0)) (list (lambda () a) (lambda () (set! a (+ a 1))) (lambda (b) (set! a b))))
    
    '(define my-even? (lambda (e) (define even? (lambda (n) (or (zero? n) (odd? (- n 1))))) (define odd? (lambda (n) (and (positive? n) (even? (- n 1))))) (even? e))) ;;; not working

    '(+ 1 2)
    '(lambda (x . y) (lambda (x) y x (set! x 1 )))
    '(lambda (x  y) (lambda () y x (set! x 1 )))
    '(lambda (x ) (lambda (x) y  (set! x 1 )))
    '(lambda (x  ) (lambda (x) y x (set! z 1 )))
    '(lambda (x ) (lambda x  x (set! x 1 )))
    '(lambda (x ) x (lambda (a b) (set! x 1 )))
    '(lambda x x (lambda (a b) (set! x 1 )))
   ; '(lambda x a (lambda (a b) (set! x 1 )))
    '(lambda (a) (+ x a (lambda b (+ x a b (lambda (c . d) (+ x a b c d (lambda (e f g) (+ x a b c d e f g))))))))
    '(+ 1 2 (lambda () (if (+ (- 1)) (if ( + (set! a (+ 1))) (or (+ 1) (+ 2) ) (begin (+ 1) (lambda () (+ 2)) (+ 3))) (lambda a (+ a)))))
    '((lambda () (+ ((lambda () a)) ((lambda () b)) ((lambda () ((lambda () c)))))))
    '(+ a b c (lambda (a b c) (+ a b c (lambda (a) (+ a b c (lambda(b) (+ a b c (lambda(c) (+ a b c (lambda (x) a b c) )))))))))
    '(+ a b c(lambda a (+ a b c (lambda (a . b) (+ a b c (lambda (a) (+ a b c (lambda a (+ a b c (lambda (a . b) (+ a b c (lambda (a) (+ a b c)))))))))))))
    
    '(lambda (x)  (set! x 1) (lambda() (set! t (+ x 1) )))
))

(define mayer-results
(list
'(lambda-simple
  (f)
  (tc-applic
    (lambda-simple
      (x)
      (tc-applic
        (bvar f 0 0)
        ((lambda-var
           s
           (tc-applic
             (fvar apply)
             ((applic (bvar x 0 0) ((bvar x 0 0))) (pvar s 0)))))))
    ((lambda-simple
       (x)
       (tc-applic
         (bvar f 0 0)
         ((lambda-var
            s
            (tc-applic
              (fvar apply)
              ((applic (bvar x 0 0) ((bvar x 0 0))) (pvar s 0))))))))))



'(applic
  (fvar x)
  ((lambda-simple
     (x)
     (tc-applic
       (pvar x 0)
       ((lambda-simple
          ()
          (tc-applic
            (bvar x 0 0)
            ((lambda-simple
               ()
               (tc-applic (bvar x 1 0) ((bvar x 1 0))))))))))))

'(def (fvar fact)
     (lambda-simple
       (n)
       (if3 (applic (fvar zero?) ((pvar n 0)))
            (const 1)
            (tc-applic
              (fvar *)
              ((pvar n 0)
                (applic
                  (fvar fact)
                  ((applic (fvar -) ((pvar n 0) (const 1))))))))))

'(lambda-simple (x) (tc-applic (pvar x 0) ((pvar x 0))))


'(def (fvar fact)
     (lambda-simple
       (n)
       (if3 (applic (fvar zero?) ((pvar n 0)))
            (const 1)
            (tc-applic
              (fvar *)
              ((pvar n 0)
                (applic
                  (fvar fact)
                  ((applic (fvar -) ((pvar n 0) (const 1))))))))))

                  
'(lambda-simple
  (a b)
  (lambda-simple
    (c)
    (tc-applic
      (fvar +)
      ((bvar a 0 0) (bvar b 0 1) (pvar c 0)))))

'(applic
  (fvar x)
  ((lambda-simple
     (x)
     (tc-applic
       (pvar x 0)
       ((lambda-simple
          ()
          (tc-applic
            (bvar x 0 0)
            ((lambda-simple
               ()
               (tc-applic (bvar x 1 0) ((bvar x 1 0))))))))))))


'(applic
  (lambda-simple
    (a)
    (seq ((set (pvar a 0) (box (pvar a 0)))
           (tc-applic
             (fvar list)
             ((lambda-simple () (box-get (bvar a 0 0)))
               (lambda-simple
                 ()
                 (box-set
                   (bvar a 0 0)
                   (applic (fvar +) ((box-get (bvar a 0 0)) (const 1)))))
               (lambda-simple (b) (box-set (bvar a 0 0) (pvar b 0))))))))
  ((const 0)))



'(def (fvar my-even?)
     (lambda-simple
       (e)
       (tc-applic
         (lambda-simple
           (even? odd?)
           (seq ((set (pvar even? 0) (box (pvar even? 0)))
                  (set (pvar odd? 1) (box (pvar odd? 1)))
                  (box-set
                    (pvar even? 0)
                    (lambda-simple
                      (n)
                      (or ((applic (fvar zero?) ((pvar n 0)))
                            (tc-applic
                              (box-get (bvar odd? 0 1))
                              ((applic
                                 (fvar -)
                                 ((pvar n 0) (const 1)))))))))
                  (box-set
                    (pvar odd? 1)
                    (lambda-simple
                      (n)
                      (if3 (applic (fvar positive?) ((pvar n 0)))
                           (tc-applic
                             (box-get (bvar even? 0 0))
                             ((applic (fvar -) ((pvar n 0) (const 1)))))
                           (const #f))))
                  (tc-applic (box-get (pvar even? 0)) ((bvar e 0 0))))))
         ((const #f) (const #f)))))

         
         

    '(applic (fvar +) ((const 1) (const 2)))

    '(lambda-opt  (x)  y  (lambda-simple    (x)    (seq ((bvar y 0 1) (pvar x 0) (set (pvar x 0) (const 1))))))

    '(lambda-simple (x y) (seq ((set (pvar x 0) (box (pvar x 0))) (lambda-simple () (seq ((bvar y 0 1) (box-get (bvar x 0 0)) (box-set (bvar x 0 0) (const 1))))))))

    '(lambda-simple
  (x)
  (lambda-simple
    (x)
    (seq ((fvar y) (set (pvar x 0) (const 1))))))

    
    
    '(lambda-simple
  (x)
  (lambda-simple
    (x)
    (seq ((fvar y) (pvar x 0) (set (fvar z) (const 1))))))

    
    '(lambda-simple
  (x)
  (lambda-var
    x
    (seq ((pvar x 0) (set (pvar x 0) (const 1))))))

    
    
    '(lambda-simple
  (x)
  (seq ((set (pvar x 0) (box (pvar x 0)))
         (box-get (pvar x 0))
         (lambda-simple (a b) (box-set (bvar x 0 0) (const 1))))))

    '(lambda-var
  x
  (seq ((set (pvar x 0) (box (pvar x 0)))
         (box-get (pvar x 0))
         (lambda-simple (a b) (box-set (bvar x 0 0) (const 1))))))
         
;;         
;;     '(lambda-var
;;   x
;;   (seq ((set (pvar x 0) (box (pvar x 0)))
;;          (fvar a)
;;          (lambda-simple (a b) (box-set (bvar x 0 0) (const 1))))))
         
         
    '(lambda-simple
  (a)
  (tc-applic
    (fvar +)
    ((fvar x)
      (pvar a 0)
      (lambda-var
        b
        (tc-applic
          (fvar +)
          ((fvar x)
            (bvar a 0 0)
            (pvar b 0)
            (lambda-opt
              (c)
              d
              (tc-applic
                (fvar +)
                ((fvar x) (bvar a 1 0) (bvar b 0 0) (pvar c 0) (pvar d 1)
                  (lambda-simple
                    (e f g)
                    (tc-applic
                      (fvar +)
                      ((fvar x) (bvar a 2 0) (bvar b 1 0) (bvar c 0 0)
                        (bvar d 0 1) (pvar e 0) (pvar f 1)
                        (pvar g 2)))))))))))))

    
    
    '(applic
  (fvar +)
  ((const 1)
    (const 2)
    (lambda-simple
      ()
      (if3 (applic (fvar +) ((applic (fvar -) ((const 1)))))
           (if3 (applic
                  (fvar +)
                  ((set (fvar a) (applic (fvar +) ((const 1))))))
                (or ((applic (fvar +) ((const 1)))
                      (tc-applic (fvar +) ((const 2)))))
                (seq ((applic (fvar +) ((const 1)))
                       (lambda-simple () (tc-applic (fvar +) ((const 2))))
                       (tc-applic (fvar +) ((const 3))))))
           (lambda-var a (tc-applic (fvar +) ((pvar a 0))))))))

           
           
    
    
    '(applic (fvar +) ((fvar a) (fvar b) (fvar c)))

    
    
    '(applic
  (fvar +)
  ((fvar a)
    (fvar b)
    (fvar c)
    (lambda-simple
      (a b c)
      (tc-applic
        (fvar +)
        ((pvar a 0)
          (pvar b 1)
          (pvar c 2)
          (lambda-simple
            (a)
            (tc-applic
              (fvar +)
              ((pvar a 0)
                (bvar b 0 1)
                (bvar c 0 2)
                (lambda-simple
                  (b)
                  (tc-applic
                    (fvar +)
                    ((bvar a 0 0)
                      (pvar b 0)
                      (bvar c 1 2)
                      (lambda-simple
                        (c)
                        (tc-applic
                          (fvar +)
                          ((bvar a 1 0)
                            (bvar b 0 0)
                            (pvar c 0)
                            (lambda-simple
                              (x)
                              (seq ((bvar a 2 0)
                                     (bvar b 1 0)
                                     (bvar c 0 0))))))))))))))))))

    
    
    '(applic
  (fvar +)
  ((fvar a)
    (fvar b)
    (fvar c)
    (lambda-var
      a
      (tc-applic
        (fvar +)
        ((pvar a 0)
          (fvar b)
          (fvar c)
          (lambda-opt
            (a)
            b
            (tc-applic
              (fvar +)
              ((pvar a 0)
                (pvar b 1)
                (fvar c)
                (lambda-simple
                  (a)
                  (tc-applic
                    (fvar +)
                    ((pvar a 0)
                      (bvar b 0 1)
                      (fvar c)
                      (lambda-var
                        a
                        (tc-applic
                          (fvar +)
                          ((pvar a 0)
                            (bvar b 1 1)
                            (fvar c)
                            (lambda-opt
                              (a)
                              b
                              (tc-applic
                                (fvar +)
                                ((pvar a 0)
                                  (pvar b 1)
                                  (fvar c)
                                  (lambda-simple
                                    (a)
                                    (tc-applic
                                      (fvar +)
                                      ((pvar a 0)
                                        (bvar b 0 1)
                                        (fvar c)))))))))))))))))))))
                                        
    '(lambda-simple
  (x)
  (seq ((set (pvar x 0) (box (pvar x 0)))
         (box-set (pvar x 0) (const 1))
         (lambda-simple
           ()
           (set (fvar t)
                (applic (fvar +) ((box-get (bvar x 0 0)) (const 1))))))))


    
    
    
))


(define test-all2
    (test-all)

    )















