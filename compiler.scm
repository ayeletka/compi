(load "pc.scm")



;;;;;;;;;;;;;;;;;;;;;; Boolean;;;;;;;;;;;;;;;;;;;;;;

(define <Boolean>
	(new (*parser (char #\#))
		 (*parser (char-ci #\T))
		 		 (*caten 2)
		 		 (*pack-with 
		 		 	(lambda(a b)
		 		 		#t))

		 (*parser (char #\#))
		 (*parser (char-ci #\F))
		 		 (*caten 2)
		 		 (*pack-with 
		 		 	(lambda(a b)
		 		 		#f))
		 (*disj 2)
	done))

 (test-string <Boolean> "#t")
  (test-string <Boolean> "#F")


;;;;;;;;;;;;;;;;;;;;;; Char ;;;;;;;;;;;;;;;;;;;;;;


;;;; hex digit ;;;;


(define <hex-digit>
  (let ((zero (char->integer #\0))
	(lc-a (char->integer #\a))
	(uc-a (char->integer #\A)))
    (new (*parser (range #\0 #\9))
	 (*pack
	  (lambda (ch)
	    (- (char->integer ch) zero)))

	 (*parser (range #\a #\f))
	 (*pack
	  (lambda (ch)
	    (+ 10 (- (char->integer ch) lc-a))))

	 (*parser (range #\A #\F))
	 (*pack
	  (lambda (ch)
	    (+ 10 (- (char->integer ch) uc-a))))

	 (*disj 3)
	 done)))

(define <X>
  (new (*parser <hex-digit>)
       (*pack
			(lambda (l)
			  l ))
		       done))

(define <XX>
  (new (*parser <hex-digit>)
       (*parser <hex-digit>)
       (*caten 2)
       (*pack-with
			(lambda (h l)
			  (+ l (* h 16))))
		       done))

(define <XXX>
	(new (*parser <hex-digit>)
		(*parser <hex-digit>)
       (*parser <hex-digit>)
       (*caten 3)
       (*pack-with
	       (lambda (a b c)
	       	(+ (+ c (* b 16)) (* a 256))
	       	)
		)
       done)
	)

(define <XXXX>
  (new (*parser <XX>)
       (*parser <XX>)
       (*caten 2)
       (*pack-with
	(lambda (h l)
	  (+ l (* 256 h))))
       done))





(define <HexUnicodeChar>
  (new (*parser (char-ci #\x))
       (*parser <XXXX>)
       (*parser <XXX>)
       (*parser <XX>)
       (*parser <X>)
       (*disj 4)
       (*pack integer->char)
       (*caten 2)
       (*pack-with (lambda (_< ch) ch))
       done))




;(test-string <HexUnicodeChar> "xB")	


;;;;;;;;;;;;;;;;;;

(define <CharPrefix>
    (new (*parser (char #\#))
    	(*parser (char #\\))
    	(*caten 2)
    	(*pack-with
    		(lambda(a b)
    			(list a b)))
  
	 done))




(define <VisibleSimpleChar>
	(new 
		(*parser (range #\! #\~))
		(*pack
			(lambda (a)
				 a))
	done))

(define ^<meta-char>
  (lambda (ch)
	 ch))
	 


(define <NamedChar>
	(new 
		(*parser (char #\x0))
		(*parser (word "lambda"))
		(*parser (word "newline"))
		(*parser (word "page"))
		(*parser (word "return"))
		(*parser (word "space"))
		(*parser (word "tab"))
		(*parser (word "DEL"))
		(*disj 8)
		(*pack
		(lambda (a)
		 	 a))
		done))



	
(define <Char>
  (new (*parser <CharPrefix>)
  		;(*parser <NamedChar>)
  		(*parser <HexUnicodeChar>)
  		(*parser <VisibleSimpleChar>)
  		(*disj 2)
  		(*caten 2)
  		(*pack-with
    		(lambda(a b)
    			b))
   done))





(test-string <Char> "#\\x")	



;;;;;;;;;;;;;;;;;;;;;; Number ;;;;;;;;;;;;;;;;;;;;;;

(define <digit-0-9>
  (range #\0 #\9))

(define <digit-1-9>
  (range #\1 #\9))

(define <Natural>
  (new 

  		(*parser (char #\0)) *star
       (*parser <digit-1-9>)
       (*parser <digit-0-9>) *star
       (*caten 3)
       (*pack-with
	(lambda (m a s)
	  (string->number
	   (list->string
	    `(,a ,@s)))))
  	(*parser (char #\0))
       (*pack (lambda (_) 0))
       (*disj 2)
       done))

(define <Integer>
  (new (*parser (char #\+))
       (*parser <Natural>)
       (*caten 2)
       (*pack-with
	(lambda (++ n) n))
       (*parser (char #\-))
       (*parser <Natural>)
       (*caten 2)
       (*pack-with
	(lambda (-- n) (- n)))
       (*parser <Natural>)
       (*disj 3)
       done))

(define <Fraction>
  (new (*parser <Integer>)
       (*parser (char #\/))
       (*parser <Natural>)
       (*guard (lambda (n) (not (zero? n))))
       (*caten 3)
       (*pack-with
	(lambda (num div den)
	  (/ num den)))
       done))

(define <Number>
	(new (*parser <Fraction>)
		(*parser <Integer>)
		(*disj 2)
	done))

(test-string <Number> "-09/0")	
