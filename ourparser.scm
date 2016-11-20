(load "compiler.scm")
;(load "/home/shugs/comp/compiler.scm")

(display "\n- ---  Our parser: ----\n\n")


;(define test1 "(the answer is . t)" )
;(define test1 "#(3)" ) 
;(define test2 "#(a b 66)" )    
;(define test8 "##8 ^ (7+8) (3)[4][5][6](5,3+7^2)(9)[(17*3) ^ 5 ] + 7") ;no go, failed with report
;(define test8 "##3^2[3*4^(-2+4)]*4+(1-(5+5)/6)")
;(define test8 "\"trR\"")
;(define test8 "##a^7")
;(define test8 "##---1")
;(define test8 "####f(2*3,6^a[2],7*2)") ;;need to fix spacing in infixlast!
(define test8 "##f()()");;;;have to fix spacing shit

(test-string <sexpr> test8)
;(test-string <sexpr> test2)


(display "\n- ---  Meirs parser: ----\n\n")
(load "parser.so")
;(load "/home/shugs/comp/parser.so")


(test-string <sexpr> test8)
;(test-string <sexpr> test2)






;(test-string <Sexpr> "-09/0")
;(test-string <Sexpr> "#\aaa")
;(define test3 "1+1")
;(define test4 "+93a")  
;(define test5 "#\\lambda") 
;(define test6 "-1234-12345") 
;(define test7 "(123a+!)")
;(define test8 "(the answer is . 2)") ;fixed

;(test-string <sexpr> test2)
;(test-string <sexpr> test3)
;(test-string <sexpr> test4)
;(test-string <sexpr> test5)
;(test-string <sexpr> test6)
