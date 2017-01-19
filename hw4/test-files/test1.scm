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

+
(if 3 #f #t) ;#f
(or #f (if 3 #t #f) 2) ;#t
(or #f (or 3 #f))  ;3
(and 3 4 5) ;5
(and 3 4 (or 3 #f)) ;3

;(lambda () (+ a b))

;t=14 f=12