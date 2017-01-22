;;; file 01

#t
#f
'()
;;; file 02

(if #f #f #t)
(if #t #t #f)

;;; file 02

(or)
(or #t)
(or #f)
(or #f #t)
(or #f #f #f #f #f #t #f)
(and)
(and #t)
(and #t #t)
(and #t #f)
(and #f #t)
(and #t #t #t #t #t #t #t #f)
;;; file 03

1
2
3
#\a
#\A
#\newline
#\"
#\\
'(1 2 3)
'(1 . (2 . (3 . ())))
'((1 2) (3 4))
'1234
'#\a
;;; file 04

(let ((x #f))
  (let ()
    x))

(let ((x #f) (y #t))
  (let ((x #f))
    (let ((x #f) (z #f) (t #f))
      (let ((x #f) (t #f))
y))))

((((lambda (x)
     (lambda (y)
       y))
   (lambda (p)
     (p (lambda (x y)
 (lambda (p)
   (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

((((lambda (x)
     (lambda (y)
       (x y)))
   (lambda (p)
     (p (lambda (x y)
 (lambda (p)
   (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

((((lambda (x)
     (lambda (y)
       (x (x y))))
   (lambda (p)
     (p (lambda (x y)
 (lambda (p)
   (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

(((((lambda (x) ((x x) (x x)))
    (lambda (x)
      (lambda (y)
(x (x y)))))
   (lambda (p)
     (p (lambda (x y)
 (lambda (p)
   (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))
;;; file 05

(let ()
  ((lambda s
     (let ()
       ((lambda s s) s s s)))
   #t))
;;; file 06

(define test
  (let ((p1 (lambda (x1 x2 x3 x4 x5 x6 x7 x8 x9 x10)
     (lambda (z)
(z x2 x3 x4 x5 x6 x7 x8 x9 x10 x1))))
(s '(a b c d e f g h i j)))
    (lambda ()
      (((((((((((apply p1 s) p1) p1) p1) p1) p1) p1) p1) p1) p1)
      list))))

(test)
;;; file 07

(((((lambda (x) (x (x x)))
    (lambda (x)
      (lambda (y)
(x (x y)))))
   (lambda (p)
     (p (lambda (x)
 (lambda (y)
   (lambda (z)
     ((z y) x)))))))
  (lambda (x)
    ((x #t) #f)))
 (lambda (x)
   (lambda (y)
     x)))
;;; file 08

(boolean? #t)
(boolean? #f)
(boolean? 1234)
(boolean? 'a)
(symbol? 'b)
(procedure? procedure?)
(eq? (car '(a b c)) 'a)
(= (car (cons 1 2)) 1)
(integer? 1234)
(char? #\a)
(null? '())
(string? "abc")
(symbol? 'lambda)
(vector? '#(1 2 3))
(vector? 1234)
(string? '#(a b c))
(string? 1234)
(= 3 (vector-length '#(a #t ())))
(pair? '(a . b))
(pair? '())
(zero? 0)
(zero? 234)
;;; file 09

(define with (lambda (s f) (apply f s)))

(define crazy-ack
  (letrec ((ack3
   (lambda (a b c)
     (cond
      ((and (zero? a) (zero? b)) (+ c 1))
      ((and (zero? a) (zero? c)) (ack-x 0 (- b 1) 1))
      ((zero? a) (ack-z 0 (- b 1) (ack-y 0 b (- c 1))))
      ((and (zero? b) (zero? c)) (ack-x (- a 1) 1 0))
      ((zero? b) (ack-z (- a 1) 1 (ack-y a 0 (- c 1))))
      ((zero? c) (ack-x (- a 1) b (ack-y a (- b 1) 1)))
      (else (ack-z (- a 1) b (ack-y a (- b 1) (ack-x a b (- c 1))))))))
  (ack-x
   (lambda (a . bcs)
     (with bcs
(lambda (b c)
 (ack3 a b c)))))
  (ack-y
   (lambda (a b . cs)
     (with cs
(lambda (c)
 (ack3 a b c)))))
  (ack-z
   (lambda abcs
     (with abcs
(lambda (a b c)
 (ack3 a b c))))))
    (lambda ()
      (and (= 7 (ack3 0 2 2))
  (= 61 (ack3 0 3 3))
  (= 316 (ack3 1 1 5))
  #;(= 636 (ack3 2 0 1))
  ))))

(crazy-ack)
;;; file 10

(define fact
  (lambda (n)
    (if (zero? n)
1
(* n (fact (- n 1))))))

(fact 5)
;;; file 11

(letrec ((fact-1
 (lambda (n)
   (if (zero? n)
1
(* n (fact-2 (- n 1))))))
(fact-2
 (lambda (n)
   (if (zero? n)
1
(* n (fact-3 (- n 1))))))
(fact-3
 (lambda (n)
   (if (zero? n)
1
(* n (fact-4 (- n 1))))))
(fact-4
 (lambda (n)
   (if (zero? n)
1
(* n (fact-5 (- n 1))))))
(fact-5
 (lambda (n)
   (if (zero? n)
1
(* n (fact-1 (- n 1)))))))
  (fact-1 10))
;;;file 12: numbers, fraction, primitive functions on those.

(< 2 3)
(< 3 2)
(> 2 3)
(> 3 2)
(- 1); negative
(- 2 1)
(- 1 2)
(- 9 1 1 1 1 1)

(number? 2)
(number? 4/2)
(= 2 4/2)
(remainder 5 4)
(integer->char 56)
(char->integer #\a)
(integer->char (char->integer #\b))
;;;file 13: lists, vectors, primitive functions on those.

(define d '(1 2 3))
(define e (list 1 2 3 4))
(define f (cons '(1 2) (cons (list 3 4) (cons '(5 6 7)'()))))
d
e
f
(car d)
(cdr e)
(map car f)
(map cons e '(1 2 3 4))


(define a '#(1 2 3))
(define b (vector 1 2 3 4))
(define c (make-vector 5 5))
a
b
c
(vector-length a)
(vector-length b)
(vector-length c)
(vector-ref a 2)
(vector-ref b 3)
(vector-ref c 4)
;;;file 14: eq on all possible inputs.
(eq? 'a 'b)
(eq? 'a 'a)
(eq? 'a 1)
(eq? 'a '#(a))
(eq? 'a #t)
(eq? 'a '(a a))
(eq? 'a '#(a a))
(eq? 'a '())
(eq? 'a #\a)
(eq? 'a "a")

(eq? 1 'b)
(eq? 1 1)
(eq? 1 2)
(eq? 1 '#(a))
(eq? 1 #t)
(eq? 1 '(a a))
(eq? 1 '#(a a))
(eq? 1 '())
(eq? 1 #\a)
(eq? 1 "a")

(eq? "a" 'b)
(eq? "a" 2)
(eq? "a" '#(a))
(eq? "a" #t)
(eq? "a" '(a a))
(eq? "a" '#(a a))
(eq? "a" '())
(eq? "a" #\a)

(eq? '() '())
(eq? #t #t)
(eq? #f #f)
(eq? #t #f)
(eq? '() (if #f 1))
(eq? (if #f 1) (if #f 1));void
;;;file 15: adding symbols dynamicly. functions on strings(?).

(define x 1)
(define a (string->symbol "x"));bucket exists
(define b (string->symbol "y"));bucket doesn't exist
(eq? a 'x)
(eq? a 'y)
(eq? b 'x)
(eq? b 'y)

(define aa (string->symbol "x"))
(define bb (string->symbol "y"))

(eq? a aa)
(eq? b bb)
(eq? a bb)
(eq? b aa)

(string-length (make-string 5 #\a))
(string-ref (symbol->string 'x) 0)
(string-length (symbol->string 'y))
(symbol->string 'z)


;;;;; MY CHANGES .... 

(< 1 5 15 20)
(< 1 5 15 20 19)
(= 1 1 1 1 1 1)
(= (- 2 1) 1 (+ 0 0 0 1) (* 1 1 1 1 1 1) (/ 1 1 1 1 1 1))
(= 2 3)
(> 5 4 3 2 1)
(> (- 8 1) (- 7 1) (- 6 1))
(> 1 2 3)

;;; 1

(+ 1 1 1 1 1 1)
(+ 1 2 3 4) 
(* 1 1 1 1 1)
(* 2 2 2)
(- 1) 
(- 1 2) 
(- 1 2 3) 
(/ 8 2 2)
(/ 1) 
(/ 2)

;;;;2

(boolean? #t)
(boolean? #f) 
(boolean? '(1 2 3)) 
(boolean? (cons 1 2)) 
(boolean? 1) 
(boolean? "1") 
(boolean? 'a) 
(boolean? +) 
(boolean? (void))


;;;; 3

(car '(1 2 3)) 
(car '(2 3)) 
(car (cons 1 (cons 2 3))) 
(cdr '(1 2 3)) 
(cdr '(2 3))
(cdr (cons 1 (cons 2 3))) 
(cons 1 (cons 2 (cons 3 4)))

;;;;; 4

(char->integer #\a) 
(char->integer #\b) 
(char->integer #\A) 
(char->integer #\B) 

(integer->char 97) 
(integer->char 98) 
(integer->char 65) 
(integer->char 66) 

(char->integer (integer->char 65)) 
(char->integer (integer->char 120))

;;;;; 5

(number? #t)
(number? #f) 
(number? '(1 2 3)) 
(number? (cons 1 2)) 
(number? 1) 
(number? "1") 
(number? 'a) 
(number? +) 
(number? (void))

;;;;;6 

(integer? #t)
(integer? #f) 
(integer? '(1 2 3)) 
(integer? (cons 1 2)) 
(integer? 1) 
(integer? "1") 
(integer? 'a) 
(integer? +) 
(integer? (void))

;;;; 7
(pair? #t)
(pair? #f) 
(pair? '(1 2 3)) 
(pair? (cons 1 2)) 
(pair? 1) 
(pair? "1") 
(pair? 'a) 
(pair? +) 
(pair? (void))


;;;; 8
(pair? #t)
(pair? #f) 
(pair? '(1 2 3)) 
(pair? (cons 1 2)) 
(pair? 1) 
(pair? "1") 
(pair? 'a) 
(pair? (void))
(pair? +) 

;;;;; 9
(null? 1)
(null? '(1))
(null? +)
(null? (list))
(null? '())

;;;;;; 10

(string? "aaa")
(string? (symbol->string 'aaa))
(string? 123)
(string? '())
(string? +)


(symbol? 'aaa)
(symbol? (string->symbol "aaab"))
(symbol? '(asd))
(symbol? 123)
(symbol? +)

;;;; 11

(zero? 0)
(zero? (- 1 1))
(zero? (* 0 1 2 3 4 5 6 7 8 9))
(zero? '())
(zero? 123)
(zero? '#(1 2 3))

;;;; 12
(vector? '#())
(vector? '#(1 2 3))
(vector? '#((1 2 3) 1 2 3))
(vector? "1233")
(vector? 'qwe)
(vector? 234)


;;;; 13
(char? '#())
(char? '#(1 2 3))
(char? '#((1 2 3) 1 2 3))
(char? "1233")
(char? 'qwe)
(char? 234)
(char? #\a)
(char? #\2)

;;;; 14
;;;;; String testing ...

(define str (make-string 5 #\y))
str

(string-set! str 0 #\y)
(string-set! str 1 #\a)
(string-set! str 2 #\k)
(string-set! str 3 #\o)
(string-set! str 4 #\v)

str ;;;; "yakov"

(string-ref str 0)
(string-ref str 1)
(string-ref str 2)
(string-ref str 3)
(string-ref str 4)


(string-length str)

;;;; 15

(define vec (make-vector 5 #\y))
vec

(vector-set! vec 0 #\y)
(vector-set! vec 1 #\a)
(vector-set! vec 2 #\k)
(vector-set! vec 3 #\o)
(vector-set! vec 4 #\v)

vec ;;;; "yakov"

(vector-ref vec 0)
(vector-ref vec 1)
(vector-ref vec 2)
(vector-ref vec 3)
(vector-ref vec 4)

(vector-length vec)

;;;;;;; 16

(string->symbol "yakov")
(string->symbol (make-string 5 #\a))
(symbol->string 'yakovyakov)
(string->symbol (symbol->string 'yakovyakov))

;;;; 17


(remainder 1 2)
(remainder 2 2)
(remainder 3 10)


;;;; 18

(apply + '(1 2 3 4))
((lambda (args) (apply + args)) '(1 2 3 4))
((lambda (args) (apply * args)) '(1 2 3 4))

;;;; 19

(define lst (list 1 2 3 4))
lst

(set-car! lst 0)
lst

(set-cdr! (cdr lst) (list 0))
lst

(set-cdr! (cdr lst) 1)
lst

;;;;; 20
(define myNumber 5)
myNumber
(define myNumber (add1 myNumber))
myNumber
(define myNumber (add1 myNumber))
myNumber
(define myNumber (add1 myNumber))
myNumber
(define myNumber (sub1 myNumber))
myNumber
(define myNumber (sub1 myNumber))
myNumber
(define myNumber (sub1 myNumber))
myNumber

;;;; 21

(not #t)
(not #f)
(not '())
(not 1)
(not (void))

;;;; 22

(andmap boolean? '(#t #t #f))
(andmap boolean? '(#t #t #f 1))
(andmap boolean? '(#t #t #f 1 (1 2 3)))

(ormap boolean? '(#t #t #f))
(ormap boolean? '(#t #t #f 1))
(ormap boolean? '(1 (1 2 3)))

;;; 23
(< 1 1 1 2 2 2)
(<= 1 1 1 2 2 2)
(> 2 2 2 2 2 2 1)
(>= 2 2 2 1 1 1 0)

(<> 1 1 1 1 1)
(<> 1 2 1 1 1)
(<> 1 2 3 4 5)



;;; 24

(foldr + 0 '(1 2 3)) 
(foldr * 0 '(1 2 3)) 
(foldr * 1 '(1 2 3 4)) 

;;;; 25

(caar '((1 2 3) (4 5 6) (7 8 9)))
(cadr '((1 2 3) (4 5 6) (7 8 9)))
(caadr '((1 2 3) (4 5 6) (7 8 9)))

;;;; 26

((^char-op +) #\a #\b)
((^variadic-right-from-binary * 4) 1 2 3 4)
((^variadic-left-from-binary + 4) 1 2 3 4)

;;;; 27


(char=? #\a #\a)
(char=? #\a #\b)

(char<=? #\a #\a)
(char<=? #\b #\a)

(char<? #\a #\b)
(char<? #\a #\a)

(char>=? #\b #\a)
(char>=? #\a #\b)

(char>? #\b #\a)
(char>? #\a #\b)

;;;;; 28


(char-uppercase? #\A)
(char-uppercase? #\a)


(char-lowercase? #\b)
(char-lowercase? #\B)


(char-upcase #\a)
(char-downcase #\A)

;;;; 29

(char-ci=? #\a #\a)
(char-ci=? #\a #\b)

(char-ci<=? #\a #\a)
(char-ci<=? #\b #\a)

(char-ci<? #\a #\b)
(char-ci<? #\a #\a)

(char-ci>=? #\b #\a)
(char-ci>=? #\a #\b)

(char-ci>? #\b #\a)
(char-ci>? #\a #\b)


;;;; 30

(string-upcase "aBcDeFgH")
(string-downcase "aBcDeFgH")


;;;; 31

(even? 4)
(even? 5)

(odd? 5)
(odd? 4)

;;;; 32

(length (list))
(length '())
(length (list 1 2 3 4))

(list-ref (list 1 2 3 4) 0)
(list-ref (list 1 2 3 4) 1)
(list-ref (list 1 2 3 4) 2)
(list-ref (list 1 2 3 4) 3)

(list? (list 1 2 3 4))
(list? '())
(list? (cons 1 2))
(list? '(1 2 3 . 4))

;;;;; 33

(member? 1 '(1 2 3))
(member? 4 '(1 2 3))

(negative? -1)
(negative? 1)

(positive? 1)
(positive? -1)

;;;; 34


(min 30 40 50 20)
(max 30 40 50 20)

;;; 35


(string->list "abcd")

;;;; 36


(string=? "aaa" "aaa" "aaa")
(string=? "aaa" "aaa" "aab")

(string<? "aaa" "bbb" "ccc")
(string<? "aaa" "bbb" "acc")

(string>? "ccc" "bbb" "aaa")
(string>? "ccc" "bbb" "aaa" "sss")

(string<=? "aaa" "aaa" "bbb")
(string<=? "aaa" "aaa" "bbb" "aaa")

(string>=? "bbb" "bbb" "aaa")
(string>=? "bbb" "bbb" "aaa" "bbb")


;;;;; 37

(list->string '(#\a #\b #\c #\d))


;;;; 38


(list->vector '(1 2 "bbb" yyy (1 . 2)))
(vector->list '#(1 2 "bbb" yyy (1 . 2)) )

;;;; 39

(append '(1 2 3) '(1 2 3))
(string-append "abc" "def" "ghi")
(vector-append '#(1 2 3) '#(1 2 3))

;;;; 40

(void)
(void? (void))
(void? #f)

;;;; 41

(vector 1 2 3 "1" "2" "3" '(1 2 . 3))


;;;; 42

(reverse '(1 2 3 4))

;;; 43

(string-reverse "vokay")

;;; 44
(boolean=? #t #t)
(boolean=? #f #f)
(boolean=? #f #t)
(boolean=? #f 1)

;;; 45

(assoc 1 '((1 1) (2 2) (3 3)))
(assq 1  '((1 1) (2 2) (3 3)))

;;;;; 46

(list-ref '(1 2 3 4) 0)
(list-ref '(1 2 3 4) 1)
(list-ref '(1 2 3 4) 2)
(list-ref '(1 2 3 4) 3)

;;;; 47

(define lstlst (list 10 20 30 40))
lstlst
(list-set! lstlst 3 '(5))
lstlst
(list-set! lstlst 1 '5)
lstlst

;;;; 48




(((((lambda (a)
      (lambda (b)
        (((lambda (a) (lambda (b) ((a b) (lambda (x) (lambda (y) y)))))
	  ((lambda (n)
	     ((n (lambda (x) (lambda (x) (lambda (y) y))))
	      (lambda (x) (lambda (y) x))))
	   (((lambda (a)
	       (lambda (b)
		 ((b (lambda (n)
		       ((lambda (p) (p (lambda (a) (lambda (b) b))))
			((n (lambda (p)
			      (((lambda (a)
				  (lambda (b) (lambda (c) ((c a) b))))
				((lambda (n)
				   (lambda (s)
				     (lambda (z) (s ((n s) z)))))
				 ((lambda (p)
				    (p (lambda (a) (lambda (b) a))))
				  p)))
			       ((lambda (p)
				  (p (lambda (a) (lambda (b) a))))
				p))))
			 (((lambda (a)
			     (lambda (b) (lambda (c) ((c a) b))))
			   (lambda (x) (lambda (y) y)))
			  (lambda (x) (lambda (y) y)))))))
		  a)))
	     a)
	    b)))
	 ((lambda (n)
	    ((n (lambda (x) (lambda (x) (lambda (y) y))))
	     (lambda (x) (lambda (y) x))))
	  (((lambda (a)
	      (lambda (b)
		((b (lambda (n)
		      ((lambda (p) (p (lambda (a) (lambda (b) b))))
		       ((n (lambda (p)
			     (((lambda (a)
				 (lambda (b) (lambda (c) ((c a) b))))
			       ((lambda (n)
				  (lambda (s)
				    (lambda (z) (s ((n s) z)))))
				((lambda (p)
				   (p (lambda (a) (lambda (b) a))))
				 p)))
			      ((lambda (p)
				 (p (lambda (a) (lambda (b) a))))
			       p))))
			(((lambda (a)
			    (lambda (b) (lambda (c) ((c a) b))))
			  (lambda (x) (lambda (y) y)))
			 (lambda (x) (lambda (y) y)))))))
		 a)))
	    b)
	   a)))))
    ((lambda (n)
       ((lambda (p) (p (lambda (a) (lambda (b) b))))
	((n (lambda (p)
	      (((lambda (a) (lambda (b) (lambda (c) ((c a) b))))
		((lambda (n) (lambda (s) (lambda (z) (s ((n s) z)))))
		 ((lambda (p) (p (lambda (a) (lambda (b) a)))) p)))
	       (((lambda (a)
		   (lambda (b)
		     ((b (a (lambda (a)
			      (lambda (b)
				((a (lambda (n)
				      (lambda (s)
					(lambda (z) (s ((n s) z))))))
				 b)))))
		      (lambda (x) (lambda (y) y)))))
		 ((lambda (p) (p (lambda (a) (lambda (b) a)))) p))
		((lambda (p) (p (lambda (a) (lambda (b) b)))) p)))))
	 (((lambda (a) (lambda (b) (lambda (c) ((c a) b))))
	   (lambda (x) x))
	  (lambda (x) x)))))
     (lambda (x) (lambda (y) (x (x (x (x (x y)))))))))
   (((lambda (a)
       (lambda (b)
	 ((b (a (lambda (a)
		  (lambda (b)
		    ((a (lambda (n)
			  (lambda (s) (lambda (z) (s ((n s) z))))))
		     b)))))
	  (lambda (x) (lambda (y) y)))))
     (((lambda (a)
	 (lambda (b)
	   ((b (a (lambda (a)
		    (lambda (b)
		      ((a (lambda (n)
			    (lambda (s) (lambda (z) (s ((n s) z))))))
		       b)))))
	    (lambda (x) (lambda (y) y)))))
       ((lambda (x) (lambda (y) (x (x (x y)))))
	(lambda (x) (lambda (y) (x (x y))))))
      (lambda (x) (lambda (y) (x (x (x y)))))))
    (lambda (x) (lambda (y) (x (x (x (x (x y)))))))))
  #t)
 #f)
 
 
 ;;;;; 49
 
 ((lambda (x) (x x 1000000))
 (lambda (x n)
   (if (zero? n) #t
       (x x (- n 1)))))
       
;;;; 50

(and
 (boolean? #t)
 (boolean? #f)
 (not (boolean? 1234))
 (not (boolean? 'a))
 (symbol? 'b)
 (procedure? procedure?)
 (eq? (car '(a b c)) 'a)
 (= (car (cons 1 2)) 1)
 (integer? 1234)
 (char? #\a)
 (null? '())
 (string? "abc")
 (symbol? 'lambda)
 (vector? '#(1 2 3))
 (not (vector? 1234))
 (not (string? '#(a b c)))
 (not (string? 1234))
 (= 3 (vector-length '#(a #t ())))
 (pair? '(a . b))
 (not (pair? '()))
 (zero? 0)
 (not (zero? 234))
 (= 97 (char->integer (string-ref "abc" 0)))
 (let ((n 10000))
   (= n (string-length (make-string n))))
 (let ((n 10000))
   (= n (vector-length (make-vector n))))
 (let* ((v (make-vector 3))
	(vs! (lambda (i x) (vector-set! v i x))))
   (vs! 0 'a)
   (vs! 1 234)
   (vs! 2 #\P)
   (equal? v '#(a 234 #\P)))
 (let ((p (cons 'a 'b)))
   (set-car! p 'just)
   (set-cdr! p 'fine)
   (equal? p '(just . fine)))
 (let ((v '#(a b c)))
   (eq? 'c (vector-ref v 2)))
 (= 65 (char->integer #\A))
 (let ((string (make-string 2)))
   (string-set! string 0 (integer->char 97))
   (string-set! string 1 (integer->char 98))
   (eq? 'ab (string->symbol string)))
 (let ((string (symbol->string 'abc)))
   (and (char=? (string-ref string 0) #\a)
	(char=? (string-ref string 1) #\b)
	(char=? (string-ref string 2) #\c)
	(= 3 (string-length string))))
 (= 3 (remainder 7 4))
 (= 6 (* 1 2 3))
 (= 1 (*))
 (= 234 (* 234))
 (= 6 (+ 1 2 3))
 (zero? (+))
 (= 234 (+ 234))
 (= 1 (- 6 3 2))
 (< 1 2 3 4 5)
 (> 5 4 3 2 1)
 (equal? '(2 . 3) (apply cons '(2 3)))
 )
 
 
 ;;;;;; 51
 
 
(and
 (= 4 (sub1 5))
 (= -5 (sub1 -4))
 (= 5 (add1 4))
 (= -4 (add1 -5))
 (not #f)
 (not (not 34))
 (not (not 'a))
 (zero? ((compose add1 sub1) 0))
 (eq? 'd (cadddr '(a b c d)))
 (char=? #\a #\a)
 (char-ci=? #\a #\A)
 (char-lowercase? #\a)
 (not (char-lowercase? #\A))
 (char=? #\a (char-downcase #\A))
 (even? 4)
 (odd? 5)
 (not (even? 5))
 (not (odd? 4))
 (= 4 (length '(a b c d)))
 (equal? '(a b c d) (list 'a 'b 'c 'd))
 (eq? 'd (list-ref '(a b c d) 3))
 (list? '())
 (list? '(a b c))
 (not (list? 'a))
 (not (list? '(a . b)))
 (not (list? #f))
 (equal? '(2 3 4) (map add1 '(1 2 3)))
 (equal? '(5 7 9) (map + '(1 2 3) '(4 5 6)))
 (member? 'do '(a b c do re mi 1 2 3))
 (not (member? 'x '()))
 (not (member? 'foo! '(1 2 3 4 5 6)))
 (negative? -4)
 (not (negative? 0))
 (positive? 5)
 (not (positive? 0))
 (not (positive? -5))
 (equal? '#(4 9 6 3 5 1) (vector 4 9 6 3 5 1))
 (ormap even? '(1 3 5 7 9 0 -25))
 (andmap even? '())
 (string=? "Hello World!" (list->string (string->list "Hello World!")))
 (string<=? "abc" "abc")
 (string<=? "" "abc")
 (not (string<=? "def" "abc"))
 (equal? '(4 9 6 3 5 1) (vector->list (list->vector '(4 9 6 3 5 1))))
 (equal? '(a b c) (member 'a '(x y z a b c)))
 (equal? '(a 1) (assoc 'a '((x 23) (b 2) (c 3) (a 1) (d 4))))
 (not (assoc 'a '((x 1) (y 2) (z 3))))
 (equal? '(a b c d) (append '(a b) '(c d)))
 (equal? '(3 2 1) (reverse '(1 2 3)))
 (null? (reverse '()))
 (string=? "abc" (string-reverse (string-reverse "abc")))
 (eq? 'a (list-ref '(x y z a b c) 3))
 (= 10 (max 4 3 2 1 6 7 8 10))
 (zero? (min 4 5 6 0 7 8 9))
 )
 
 ;;;;; #52
 
 (((((lambda (x) (x (x x)))
    (lambda (x)
      (lambda (y)
	(x (x y)))))
   (lambda (p)
     (p (lambda (x)
	  (lambda (y)
	    (lambda (z)
	      ((z y) x)))))))
  (lambda (x)
    ((x #t) #f)))
 (lambda (x)
   (lambda (y)
     x)))
     
     
;;;;; 53

(define even?
  (letrec ((even-1?
	    (lambda (n)
	      (or (zero? n)
		  (odd-2? (- n 1) 'odd-2))))
	   (odd-2?
	    (lambda (n _)
	      (and (positive? n)
		   (even-3? (- n 1) (+ n n) (+ n n n)))))
	   (even-3?
	    (lambda (n _1 _2)
	      (or (zero? n)
		  (odd-5? (- n 1) (+ n n) (* n n) 'odd-5 'odder-5))))
	   (odd-5?
	    (lambda (n _1 _2 _3 _4)
	      (and (positive? n)
		   (even-1? (- n 1))))))
    even-1?))
    
(even? 4)
(even? 5)

;;;;;; 54

(define test
  (let ((p1 (lambda (x1 x2 x3 x4 x5 x6 x7 x8 x9 x10)
	      (lambda (z)
		(z x2 x3 x4 x5 x6 x7 x8 x9 x10 x1))))
	(s '(a b c d e f g h i j)))
    (lambda ()
      (equal? (((((((((((apply p1 s) p1) p1) p1) p1) p1) p1) p1) p1) p1)
	       list)
	      s))))

(test)

;;;;; 55

(let ((a 1))
  (let ((b 2) (c 3))
    (let ((d 4) (e 5) (f 6))
      (= 720 (* a b c d e f)))))
      
;;;; 56

(let ()
  ((lambda s
     (let ()
       ((lambda s s) s s s)))
   #t))
   
;;; 57

(define fact
  (letrec ((fact-1
	    (lambda (n r)
	      (if (zero? n)
		  r
		  (fact-2 (- n 1)
			  (* n r)
			  'moshe
			  'yosi))))
	   (fact-2
	    (lambda (n r _1 _2)
	      (if (zero? n)
		  r
		  (fact-3 (- n 1)
			  (* n r)
			  'dana
			  'michal
			  'olga
			  'sonia))))
	   (fact-3
	    (lambda (n r _1 _2 _3 _4)
	      (if (zero? n)
		  r
		  (fact-1 (- n 1)
			  (* n r))))))
    (lambda (n)
      (fact-1 n 1))))
      
(fact 5)

;;;;; 58

(define fact-1
  (lambda (n)
    (if (zero? n)
	(list 1 'fact-1)
	(with (fact-2 (- n 1))
	  (lambda (r . trail)
	    (cons (* n r)
	      (cons 'fact-1 trail)))))))

(define fact-2
  (lambda (n)
    (if (zero? n)
	(list 1 'fact-2)
	(with (fact-3 (- n 1))
	  (lambda (r . trail)
	    (cons (* n r)
	      (cons 'fact-2 trail)))))))

(define fact-3
  (lambda (n)
    (if (zero? n)
	(list 1 'fact-3)
	(with (fact-1 (- n 1))
	  (lambda (r . trail)
	    (cons (* n r)
	      (cons 'fact-3 trail)))))))
(fact-1 10)

;;;;; 59


(define fact
  (let ((x (lambda (x)
	     ((x (lambda (x) (lambda (y) (lambda (z) ((x z) (y z))))))
	      (lambda (x) (lambda (y) x)))))
	(->
	 ((lambda (x) (x x))
	  (lambda (->)
	    (lambda (n)
	      (if (zero? n)
		  (lambda (x) (lambda (y) y))
		  (let ((z ((-> ->) (- n 1))))
		    (lambda (x)
		      (lambda (y)
			(x ((z x) y)))))))))))
    (lambda (n)
      ((((((((x (x (x (x x)))) (((x (x (x (x x)))) ((x (x (x x))) (x
      (x (x (x x)))))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x x
      ))))) (x (x (x (x x))))))) ((x (x (x x))) (x (x (x x))))) ((((
      (x (x (x (x x)))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x
      (x x)))))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x x)))))
      (x (x (x (x x))))))) ((x (x (x x))) (x (x (x x))))) (((((x (x
      (x (x x)))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x (x x))
      )))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x x))))) (x (x
      (x (x x))))))) ((x (x (x x))) (x (x (x x))))) (((x (x (x (x x)
      ))) (x (x (x x)))) (x (x (x x))))) (((x (x (x(x x)))) (((((x (
      x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (x (x (x x)))
      ) (((x (x (x (x x)))) ((x (x (x x))) (((x(x (x (x x)))) (((x (
      x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (((x (x (x (x
      x)))) ((x (x (x x))) (x (x (x x))))) (x(x (x (x x))))))) ((x (
      x (x x))) (x (x (x x))))))) ((((x (x(x (x x)))) (((x (x (x (x
      x)))) ((x (x (x x))) (x (x (x (x x)))))) (((x (x (x (x x)))) (
      (x (x (x x))) (x (x (x x))))) (x(x (x (x x))))))) ((x (x (x x)
      )) (x (x (x x))))) (((x (x (x (x x)))) (x (x (x x)))) (x (x (x
      x))))))) (((((x (x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))
      ))) (x (x (x x)))) ((x (x(x (x x)))) (((x (x (x (x x)))) ((x (
      x (x x))) (x (x (x (x x)))))) (x (x (x x)))))) (((((x (x (x (x
      x)))) (((x (x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (
      ((x (x (x (x x)))) ((x (x (x x))) (x (x (x x))))) (x (x (x (x
      x))))))) ((x (x (x x))) (x (x (x x))))) (((x (x (x (x x)))) (x
      (x (x x)))) (x (x (x x))))) (x (x (x x))))))) (((x (x (x (x x)
      ))) (((((x (x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (
      x(x (x x)))) (((x(x (x (x x)))) ((x (x (x x))) (x (x (x (x x))
      )))) (x (x (x x))))) (((((x (x (x (x x)))) (((x (x (x (x x))))
      ((x (x (x x)))(x (x (x (x x)))))) (((x (x (x (x x)))) ((x (x (
      x x))) (x (x(x x))))) (x (x (x (x x))))))) ((x (x (x x))) (x (
      x (x x)))))(((x (x (x (x x)))) (x (x (x x)))) (x (x (x x)))))
      (x (x (x x)))))) (((((x (x (x (x x)))) (((x (x (x (x x)))) ((x
      (x (x x)))(x (x (x (x x)))))) (((x (x (x (x x)))) ((x (x (x x)
      )) (x (x(x x))))) (x (x (x (x x))))))) ((x (x (x x))) (x (x (x
      x)))))(((x (x (x (x x)))) (x (x (x x)))) (x (x (x x))))) ((x (
      x (x x))) (((x (x (x (x x)))) (x (x (x x)))) (x (x (x x)))))))
      )))(((((x (x (x (x x)))) ((x (x (x x))) (((x (x (x (x x)))) ((
      (x(x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (((x (x (x
      (x x)))) ((x (x (x x))) (x (x (x x))))) (x (x (x (x x)))))))((
      x (x (x x))) (x (x (x x))))))) ((((x (x (x (x x)))) (((x (x(x
      (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (((x (x (x (x x)))
      )((x (x (x x))) (x (x (x x))))) (x (x (x (x x))))))) ((x(x (x
      x))) (x (x (x x))))) (((x (x (x (x x)))) (x (x (x x))))(x (x (
      x x)))))) (((x (x (x (x x)))) (((x (x (x (x x)))) ((x (x (x x)
      ))(x (x (x (x x)))))) (x (x (x x))))) ((x (x (x x)))(((x (x (x
      (x x)))) (x (x (x x)))) (x (x (x x))))))) (((x (x(x (x x)))) (
      ((x (x (x (x x)))) ((x (x (x x))) (x (x (x (x x)))))) (x (x (x
      x))))) ((x (x (x x))) (((x (x (x (x x)))) (x(x (x x)))) (x (x
      (x x))))))))) ((x (x (x x))) (((x (x (x (x x)))) (x (x (x x)))
      )(x (x (x x))))))
	 (-> n))
	(lambda (x) (+ x 1))) 0))))

(fact 5)

;;;;; 60


;;;; Test eq?

(eq? 1 (+ 1 0 0 0 0))
(eq? 1 (* 1 2))
(eq? (- 1) -1)
(eq? 2 (void))

;;;; 61

(eq? '(1 2 3) '(1 2 3))
(eq? '(1 2 3) (list 1 2 3))
(eq? '(1 "aaa" "bbb" #t) '(1 "aaa" "bbb" #t))
(eq? '(1 "aaa" "bbb" #t) '(1 "aaa" "bbb" #t #f))
(eq? (cdr '(2 1 "aaa" "bbb" #t)) '(1 "aaa" "bbb" #t))
(eq? '(2 1 "aaa" "bbb" #t) '(1 "aaa" "bbb" #t #f))

;;;; 62

(eq? (void) (if #f #f))
(eq? (void) 123)
(eq? (void) (void))
(eq? (void) "aaa")

;;; 63

(eq? #t (eq? 1 1))
(eq? #f (eq? 1 1))
(eq? #f (eq? 1 2))
(eq? #f (void))


;;; 64

(eq? "1234" "1234")
(eq? "1234" (list->string '(1 2 3 4)))
(eq? (symbol->string 'xxx) (symbol->string 'xxx))
(eq? (symbol->string 'xxx) (symbol->string 'xxxy))

;;;; 65
(eq? '() '())
(eq? '() '(1))
(eq? '() (if #t (list)))
(eq? '() (cdr '(1)))

;;;; 66

(eq? (list) (list))
(eq? (list 1) (list 1))
(eq? #t #t)
(eq? #t #f)


;;; 67
(define testeq +)
(eq? testeq +) 
(eq? testeq testeq) 

(define testeq -)
(eq? testeq +) 
(eq? testeq testeq) 


;;; 68

(eq? 'xxx (string->symbol "xxx"))
(eq? (string->symbol "xxx") (string->symbol "xxx"))

;;; 69

(define testeq 'aaa)
(eq? testeq 'aaa)
(eq? testeq (string->symbol (list->string '(#\a #\a #\a))))

;;;;; 70

(eq? #\a #\a)
(eq? #\a #\b)
(eq? #\a 1)



;;;; 71
(let ((x #f))
  (let ()
    x))

(let ((x #f) (y #t))
  (let ((x #f))
    (let ((x #f) (z #f) (t #f))
      (let ((x #f) (t #f))
  y))))

;;; example 0
((((lambda (x)
     (lambda (y)
       y))
   (lambda (p)
     (p (lambda (x y)
    (lambda (p)
      (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

((((lambda (x)
     (lambda (y)
       (x y)))
   (lambda (p)
     (p (lambda (x y)
    (lambda (p)
      (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

;;; example 1
((((lambda (x)
     (lambda (y)
       (x (x y))))
   (lambda (p)
     (p (lambda (x y)
    (lambda (p)
      (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))

;;; example 2
(((((lambda (x) ((x x) (x x)))
    (lambda (x)
      (lambda (y)
  (x (x y)))))
   (lambda (p)
     (p (lambda (x y)
    (lambda (p)
      (p y x))))))
  (lambda (z) (z #t #f)))
 (lambda (x y) x))


 ;;;72
