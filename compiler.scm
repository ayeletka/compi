(load "/home/shugs/comp/pc.scm")
;(load "pc.scm")

;;;;;;;;;;;;;;;;;;;;;; WhiteSpace;;;;;;;;;;;;;;;;;;;;;;

(define <WhiteSpace>
  (new (*parser (range (integer->char 1) (integer->char 32)))
    *star
    done)
  )

;(test-string <WhiteSpace> "  \t  \r  \f        a")

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

 ;(test-string <Boolean> "#t")
 ; (test-string <Boolean> "#F")


;;;;;;;;;;;;;;;;;;;;;; Char ;;;;;;;;;;;;;;;;;;;;;;



(define <HexChar>
  (new
      (*parser (range #\0 #\9))
      (*parser (range-ci #\a #\f))
      (*disj 2)
       done))



(define <HexUnicodeChar>
  (new (*parser (char-ci #\x))
       (*parser <HexChar>)
       (*parser <HexChar>) *star
       (*caten 3)
       (*pack-with
          (lambda (x digit digits)
            (integer->char 
            (string->number
                (list->string `(,digit ,@digits)) 16))))
       done))




;(test-string <HexUnicodeChar> "x12")	



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
    (lambda (str ch)
        (new (*parser (word str))
            (*pack (lambda (_) ch))
            done)))
        

(define <NamedChar>
    (new
        (*parser (^<meta-char> "lambda" (integer->char 955)))
        (*parser (^<meta-char> "newline" (integer->char 10)))
        (*parser (^<meta-char> "page" (integer->char 12)))
        (*parser (^<meta-char> "return" (integer->char 13)))
        (*parser (^<meta-char> "space" (integer->char 32)))
        (*parser (^<meta-char> "tab" (integer->char 9)))
        (*parser (^<meta-char> "nul" (integer->char 0)))
        (*disj 7)
        done))

	
(define <Char>
  (new (*parser <CharPrefix>)
  		(*parser <NamedChar>)
  		(*parser <HexUnicodeChar>)
  		(*parser <VisibleSimpleChar>)
      (*parser <VisibleSimpleChar>)
      *not-followed-by
  		(*disj 3)
  		(*caten 2)
  		(*pack-with
    		(lambda(a b)
    			b))
   done))




;(test-string <Char> "#\lambda")	



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

;(test-string <Number> "-09/0")	
;(test-string <Number> "1+1")  





;;;;;;;;;;;;;;;;;;;;;; String ;;;;;;;;;;;;;;;;;;;;;;
(define <StringVisibleChar>
    (new
        (*parser (range #\! #\~))
        (*pack
            (lambda (a) a))
        done))



(define <StringMetaChar>
    (new
        (*parser (^<meta-char> "\\\\" #\\))
        (*parser (^<meta-char> "\\\"" #\"))
        (*parser (^<meta-char> "\\n" #\newline))
        (*parser (^<meta-char> "\\t" #\tab))
        (*parser (^<meta-char> "\\f" #\page))
        (*parser (^<meta-char> "\\r" #\return))
        (*disj 6)
        done))


(define <StringHexChar>
    (new
        (*parser (char #\\))
        (*parser (char-ci #\x))
        (*parser <HexChar>) *star
        (*parser (char #\;))
        (*caten 4)
        (*pack-with
          (lambda (s x digits end)
            (integer->char 
            (string->number
                (list->string digits) 16))))
        done))

(define <StringChar>
    (new
        (*parser <StringMetaChar>)
        (*parser <StringHexChar>)
        (*parser <StringVisibleChar>)
        (*disj 3)
        
        done))

;(test-string <StringChar> "\\xabc;")



(define <String>
  (new 
            (*parser (word "\""))
            (*parser <StringChar>)
            (*parser (word "\"")) *diff *star
            (*parser (word "\""))
            (*caten 3)
            (*pack-with
                (lambda (open-delim chars close-delim)
                    (list->string chars)))
            done))
            



;;;;;;;;;;;;;;;;;;;;;; Symbol ;;;;;;;;;;;;;;;;;;;;;;


(define <SymbolChar>
  (new 
    (*parser <digit-0-9>)
    (*parser (range-ci #\a #\z))
    (*parser (char #\!))
    (*parser (char #\$))
    (*parser (char #\^))
    (*parser (char #\*))
    (*parser (char #\-))
    (*parser (char #\_))
    (*parser (char #\+))
    (*parser (char #\=))
    (*parser (char #\>))
    (*parser (char #\<))
    (*parser (char #\?))
    (*parser (char #\/))
    (*disj 14)
    done)
  )
;(test-string <SymbolChar> "a")


(define <Symbol>
  (new
    (*parser <SymbolChar>) *plus
    (*pack 
      (lambda(symbols)
       (string->symbol (list->string symbols) )))
  done)
  )

;(test-string <Symbol> "x")


;;;;;;;;;;;;;;;;;;;;;; ProperList ;;;;;;;;;;;;;;;;;;;;;;


(define <ProperList>
  (new
    (*parser (char (integer->char 40))) 
    (*delayed
     (lambda()
        <sexpr>) 
      )
      *star    
    (*parser (char (integer->char 41))) 
    (*caten 3)
    (*pack-with (lambda (a b c)  
            b)) 
    done)
  )


;;;;;;;;;;;;;;;;;;; ImproperList ;;;;;;;;;;;;;;


        
(define <ImproperList>
    (new    
        (*parser (char #\())
        (*delayed
            (lambda() <sexpr>)) *plus
        (*parser (char #\.))
        (*delayed
            (lambda() <sexpr>))
        (*parser (char #\)))
        (*caten 5)
        (*pack-with 
            (lambda (open lst dot var close)
                 `(,@lst . ,var)))
        done))
 

 ;;;;;;;;;;;;;;;;;;; Vector ;;;;;;;;;;;;;;;;
  
  (define <Vector>
    (new
      (*parser (char (integer->char 35)))
      (*parser <ProperList>)
      (*caten 2)
      (*pack-with
        (lambda(a b)
          (list->vector b)))

     done))
  
  
 ;;;;;;;;;;;;;;;;;;; Quoted ;;;;;;;;;;;;;;;;;

(define <Quoted>
  (new
    (*parser (char (integer->char 39))) 
    (*delayed
      (lambda() <sexpr>))
    (*caten 2)
    (*pack-with
      (lambda (q expr)
        (list 'quote expr)))
    done))


 ;;;;;;;;;;;;;;;;;;; QuasiQuoted ;;;;;;;;;;;;;;;;;

(define <QuasiQuoted>
  (new
    (*parser (char (integer->char 96))) 
    (*delayed
      (lambda() <sexpr>))
    (*caten 2)
    (*pack-with
      (lambda (q expr)
        (list 'quasiquote expr)))
    done))

;;;;;;;;;;;;;;;;;;; QuasiQuoted ;;;;;;;;;;;;;;;;;

(define <Unquoted>
  (new
    (*parser (char (integer->char 44))) 
    (*delayed
      (lambda() <sexpr>))
    (*caten 2)
    (*pack-with
      (lambda (q expr)
        (list 'unquote expr)))
    done))

;;;;;;;;;;;;;;;;;;; UnquoteAndSpliced⟩ ;;;;;;;;;;;;;;;;;

(define <UnquoteAndSpliced⟩>
  (new
    (*parser (char (integer->char 44))) 
    (*parser (char (integer->char 64))) 
    (*delayed
      (lambda() <sexpr>))
    (*caten 3)
    (*pack-with
      (lambda (a b expr)
        (list 'unquote-splicing expr)))
  done))

;;;;;;;;;;;;;;;;;;; Infix the Satan;;;;;;;;;

(define <InfixPrefixExtensionPrefix>
  (new 
    (*parser (char (integer->char 35))) 
    (*parser (char (integer->char 35))) 
    (*caten 2)
    (*parser (char (integer->char 35)))
    (*parser (char (integer->char 37))) 
    (*caten 2)
    (*disj 2)
    done))
  
(define <InfixSymbol>
  (new 
    (*parser <Symbol>)
    (*parser (char (integer->char 43))) ;+
    (*parser (char (integer->char 45))) ;-
    (*parser (char (integer->char 42))) ;*
    (*parser (char (integer->char 42))) ;**
    (*parser (char (integer->char 42))) ;**
    (*caten 2)
    (*parser (char (integer->char 94))) ;^
    (*parser (char (integer->char 47))) ;/
    (*disj 6)
    *diff
    done))       
 
(define <PowerSymbol>
    (new 
        (*parser (word "**")) ;**
        (*parser (word "^")) ;^
        (*disj 2)
        (*pack 
            (lambda(symbol)
                (string->symbol (list->string symbol)) ))
        done))
        

(define <InfixLast>
    (new 
        (*parser <Number>)
        (*parser <InfixSymbol>) ;returns the wrong output not sure why
        (*disj 2)
        done))              
        
(define <InfixPow>
    (new 
        (*parser <InfixLast>)
        (*parser <PowerSymbol>)
        (*parser <InfixLast>)
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
            `(,@exp2))) *star
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
                `('expt ,exp1 ,@exp2)))
        done))
        
(test-string <InfixPow> "3^2^5")

 (define <InfixDiv>
    (new 
        (*parser <InfixPow>)
        (*parser (char (integer->char 47)))
        (*parser <InfixPow>)
        (*caten 2) *star
        ;(*pack-with (lambda (exp1 exp2)
        ;    `(/ ,@exp2)))
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
                `(,@exp2 ,@exp1)))
        done))

(test-string <InfixDiv> "4/3^2")
        
(define <InfixMul>
    (new 
        (*parser <InfixDiv>)
        (*parser (char (integer->char 42)))
        (*parser <InfixDiv>)
        (*caten 2) *star
        ;(*pack-with (lambda (exp1 exp2)
         ;   `(* ,@exp2)))        
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
                `(,@exp2 ,@exp1)))
        done))
        
        
(define <InfixSub>
    (new 
        (*parser <InfixMul>)
        (*parser (char (integer->char 45)))
        (*parser <InfixMul>)
        (*caten 2) *star
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
                `(,@exp2 ,@exp1)))
        done))

(define <Add>
    (new
        (*parser <InfixSub>)
        (*parser (char (integer->char 43)))
        (*parser <InfixSub>)
        (*caten 3)
        (*pack-with
            (lambda (num1 plus num2)
                `(+ ,num1 ,num2)))
        done))
  
(define <InfixAdd>
    (new 
        ;(*parser <Add>)
        (*parser <InfixSub>)
        ;(*disj 2)
        (*parser (char (integer->char 43)))
        (*parser <InfixSub>)
        (*caten 2)
        (*pack-with (lambda (exp1 exp2)
            `(,@exp2))) 
         *star
        (*caten 2) 
        (*pack-with (lambda (exp1 exp2)
                `(+ ,exp1 ,@exp2)))
        done))
   (test-string <InfixAdd> "2+3+4+5")
        
(define <InfixExpression>
    (new 
        (*parser <InfixAdd>) 
        done)) 
        
(define <InfixExtension>
    (new (*parser <InfixPrefixExtensionPrefix>)
        (*parser <InfixExpression>)
        (*caten 2)
        (*pack-with 
            (lambda (a b)
                b))
        done))

;(test-string <InfixExtension> "##3");nott sure why this returns as xsomething and not as3
;(test-string <InfixExpression> "**");not sure why this returns as xsomething and not as3
(test-string <InfixExtension> "##2+3+4")
;;;;;;;;;;;;;;;;;;;;;; Sexpr ;;;;;;;;;;;;;;;;;;;;;;

(define <sexpr>
  (new
    (*parser <WhiteSpace>)
    (*parser <InfixExtension>)
    (*parser <Number>)
    (*parser <Boolean>)
    (*parser <Symbol>)
    (*parser <Char>)
    (*parser <String>)
    (*parser <ProperList>)
    (*parser <ImproperList>)
    (*parser <Vector>)
    (*parser <Quoted>)
    (*parser <QuasiQuoted>)
    (*parser <Unquoted>)
    (*parser <UnquoteAndSpliced⟩>)
    (*disj 13)
    (*parser <WhiteSpace>)
    (*caten 3)
    (*pack-with 
     (lambda(space1 expr space2)
           expr))
  done)
)

