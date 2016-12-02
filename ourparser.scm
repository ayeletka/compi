(load "compiler-scm-tag-parser.scm")

(display "\n- ---  Our parser: ----\n\n")

(parse '(set! x 3))

(parse '(set! v (f x)))

(display "\n- ---  Meirs parser: ----\n\n")

(load "tagparser.so")


(parse '(set! x 3))

(parse '(set! v (f x)))

