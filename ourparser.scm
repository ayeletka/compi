(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")


(parse '(cond (a b) (c d) (else y))
	)




(display "\n- ---  Meirs parser: ----\n\n")

(load "tagparser.so")

	
(parse '(cond (a b) (c d) (else y))
	)