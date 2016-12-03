(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")


(parse-2 `(quasiquote (a b c)))




(display "\n- ---  Meirs parser: ----\n\n")

(load "tagparser.so")

	
(parse `(quasiquote (a b c)))
