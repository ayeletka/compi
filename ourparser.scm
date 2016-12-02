(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")

(parse '(letrec ()		
		(loop 2)))


(display "\n- ---  Meirs parser: ----\n\n")

(load "tagparser.so")


(parse '(letrec ()		
		(loop 2)))
