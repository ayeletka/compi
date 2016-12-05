(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")


(parse #f)

(display "\n- ---  Meirs parser: ----\n\n")

(load "tagparser.so")

(parse #f)
