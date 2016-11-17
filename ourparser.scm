(load "compiler.scm")

(display "\n- ---  Our parser: ----\n\n")

(define test1 "(b c    ! .  abc )")



(test-string <sexpr> test1)



(display "\n- ---  Meirs parser: ----\n\n")
(load "parser.so")


(test-string <sexpr> test1)







;(test-string <Sexpr> "-09/0")
;(test-string <Sexpr> "#\aaa")
;(define test3 "1+1")
;(define test4 "+93a")  
;(define test5 "#\\lambda") 
;(define test6 "-1234-12345") 
;(define test7 "(123a+!)")
;(define test8 "(the answer is . 2)")

;(test-string <sexpr> test2)
;(test-string <sexpr> test3)
;(test-string <sexpr> test4)
;(test-string <sexpr> test5)
;(test-string <sexpr> test6)
