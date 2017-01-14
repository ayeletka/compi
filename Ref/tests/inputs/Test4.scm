 
(((lambda(x y) (if x (lambda(y) y) y)) #t #f) (if #f #t))