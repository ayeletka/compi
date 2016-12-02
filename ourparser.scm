;(load "compiler.scm")
(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")
 (parse
'(lambda (x y . z)
 6 (if x y z)))

 (parse '(define (foo x y z)
(if x y z)))
 
(parse '(define (list . args)
args))



(display "\n- ---  Meirs parser: ----\n\n")
(load "tagparser.so")
;(load "/home/shugs/comp/parser.so")
 (parse '(lambda (x y . z)
 6 (if x y z))))


(parse '(define (foo x y z)
(if x y z)))

(parse '(define (list . args)
args))



