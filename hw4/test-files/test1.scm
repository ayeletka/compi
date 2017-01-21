1
"abc"
#f
#t
#\a
'#(1 2 3 4 5 6) ;vector print - identical to referance but not to scheme output. need to think about what to do about it 
'abc
'()
24
'(1 . 2)
;(void) - no void object after computation so dont know how to check

+ ;- should be procedure + after implementation
(if 3 (if a (if 2  20 #t) #t) #t) ;#20
(or #f (if 3 #t #f) 2) ;#t
(or #f (or 3 #f))  ;3
(and 3 4 5) ;5
(and 3 4 (or 3 #f)) ;3
(begin "a" (if 3 #f #t) 2) ;2
(+ 1 1 5) ;7 doesn't work

((lambda () (+ 1 2)))

((lambda () (+ 1 2))) ;3

((lambda () (if (or 2 4) 4 (or #f)))) ;4
;t=14 f=12