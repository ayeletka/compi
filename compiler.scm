;(load "/home/shugs/Documents/compi/pc.scm")
(load "pc.scm")

;;;;;;;;;;;;;;;;;;;;;; WhiteSpace;;;;;;;;;;;;;;;;;;;;;;

(define <WhiteSpace>
  (new (*parser (range (integer->char 1) (integer->char 32)))
    *star

    done)
  )

;(test-string <WhiteSpace> "  \t  \r  \f        a")


;;;;;;;;;;;;;;;;;;;;;; Comments;;;;;;;;;;;;;;;;;;;;;;


(define <line-comment>
  (let ((<end-of-line-comment>
   (new (*parser (char #\newline))
        (*parser <end-of-input>)
        (*disj 2)
        done)))
    (new (*parser (char #\;))
   
   (*parser <any-char>)
   (*parser <end-of-line-comment>)
   *diff *star

   (*parser <end-of-line-comment>)
   (*caten 3)
   done)))

(define <sexpr-comment>
  (new (*parser (word "#;"))
       (*delayed (lambda () <sexpr2>))
       (*caten 2)
       done))

(define <Comments>
  (disj <line-comment>
  <sexpr-comment>))

(define <skip>
  (disj <Comments>
  <WhiteSpace>))

(define ^^<wrapped>
  (lambda (<wrapper>)
    (lambda (<p>)
      (new (*parser <wrapper>)
     (*parser <p>)
     (*parser <wrapper>)
     (*caten 3)
     (*pack-with
      (lambda (_left e _right) e))
     done))))

(define ^<CommentOutPrefix*> (^^<wrapped> (star <skip>)))






(define <sexpr-comment-inf>
  (new 
        (*parser (word "#;"))
        (*parser <WhiteSpace>)
       ; (*parser <SymbolComment>)
       ;(*delayed (lambda () <InfixExtension>))
       ;(*delayed (lambda () <sexpr2>))
       ;(*disj 2)
        (*delayed (lambda() <InfixExtension>))
       (*delayed (lambda () <InfixSexprEscape>))
        (*delayed (lambda () <InfixAddSub>))
        (*disj 3)
       (*parser <WhiteSpace>)
       (*caten 4)
       done))


(define <CommentsInf>
  (new 
    (*parser <line-comment>)
    (*parser <sexpr-comment-inf>)
    (*disj 2)

    done))
;(test-string <sexpr2> "## 2+ #; 3- 5*6 8 #; \"abc\"")

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




;(test-string <HexUnicodeChar> "x11000")	



(define <CharPrefix>
    (new (*parser (char #\#))
    	(*parser (char #\\))
    	(*caten 2)
      (*pack-with
        (lambda(a b)
          (list #\# #\\)))
	 done))


;(test-string <CharPrefix> "\#\\")

(define <VisibleSimpleChar>
	(new 
		(*parser (range #\! #\~))
    (*parser <end-of-input>)
    (*caten 2)
    (*pack-with
			(lambda (a end)
				 a))
	done))


(define ^<meta-char>
    (lambda (str ch)
        (new (*parser (word-ci str))
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
  (new 
      (*parser <WhiteSpace>)
      (*parser <CharPrefix>)
  		(*parser <NamedChar>)
  		(*parser <HexUnicodeChar>)
      (*parser <VisibleSimpleChar>)
      ;(*parser <VisibleSimpleChar>)
      ;*not-followed-by
  		(*disj 3)
      (*parser <WhiteSpace>)
      (*caten 4)
      (*pack-with
        (lambda(sp1 a b sp2)
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
    ;;(*delayed (lambda () <SymbolChar>))
    ;;*not-followed-by 
	done))

;(test-string <Number> "-09/0")	
;(test-string <Number> "1+1")  





;;;;;;;;;;;;;;;;;;;;;; String ;;;;;;;;;;;;;;;;;;;;;;
(define <StringLiteralChar>
    (new
        (*parser <any-char>)
        (*parser (char #\\))
        *diff
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
        (*parser <StringLiteralChar>)
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
            

;(test-string <String> "\"TRt\"")

;;;;;;;;;;;;;;;;;;;;;; Symbol ;;;;;;;;;;;;;;;;;;;;;;


(define <SymbolChar>
  (new 
    (*parser (range #\A #\Z))
    (*pack (lambda (ch)
        (integer->char  (+ (char->integer ch) 32))))
    (*parser (range #\a #\z))
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




(define <Symbol>
  (new
    (*parser <Number>)
    (*parser <SymbolChar>) *plus
    *not-followed-by
    (*parser <digit-0-9>) *star
    (*parser <SymbolChar>) *plus
    (*parser <digit-0-9>) *star
    (*caten 3)
    (*pack-with (lambda (ch lst ch2)
      `(,@ch ,@lst ,@ch2)))
    (*pack 
      (lambda(symbols)
       (string->symbol (list->string symbols) )))
    (*disj 2)
  done)
  )





;;;;;;;;;;;;;;;;;;;;;; ProperList ;;;;;;;;;;;;;;;;;;;;;;


(define <ProperList>
  (new
    (*parser (char (integer->char 40))) 
    (*delayed
     (lambda()
        <sexpr2>) 
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
            (lambda() <sexpr2>)) *plus
        (*parser (char #\.))
        (*delayed
            (lambda() <sexpr2>))
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
      (lambda() <sexpr2>))
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
      (lambda() <sexpr2>)) 
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
      (lambda() <sexpr2>))
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
      (lambda() <sexpr2>))
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
    (*parser <Number>)
    (*parser <SymbolChar>) *plus
    *not-followed-by
    (*parser <digit-0-9>) *star
    (*parser <SymbolChar>) 
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
    *plus
    (*parser <digit-0-9>) *star
    (*caten 3)
    (*pack-with (lambda (ch lst ch2)
      `(,@ch ,@lst ,@ch2)))
    (*pack 
      (lambda(symbols)
       (string->symbol (list->string symbols) )))
    (*disj 2)
    ;(*parser <any-char>)
   
    done)) 





;(test-string <SymbolChar> "")

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
    (*parser <WhiteSpace>)
    (*parser <InfixSymbol>) ;*plus
    ;(*pack
    ;  (lambda(symbol)
    ;   (string->symbol (list->string symbol))))
    (*parser <Number>)
    (*disj 2)
    (*parser <WhiteSpace>)
    
    (*caten 3)
    (*pack-with (lambda (sp1 expr sp2)
      expr))
    done))     

;(test-string <InfixLast> "123a")


(define <InfixParen>
  (new
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 40)))
    (*parser <WhiteSpace>)
    (*delayed (lambda () <InfixExpression>))
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 41)))
    (*parser <WhiteSpace>)
    (*caten 7)
    (*pack-with (lambda (sp1 del1 sp2 num sp3 del2 sp4)
        `(,@num)
      ))
  done)) 



(define <InfixArrayGet>
  (new
    (*parser <WhiteSpace>)
    (*parser <InfixLast>)
    (*parser (char (integer->char 40)))
    *not-followed-by
    (*parser <InfixParen>)
    (*disj 2)
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 91)))
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*delayed (lambda () <InfixExpression>))
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*caten 5)
    (*pack-with (lambda (com1 ws1 exp ws2 com2) exp))
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 93)))
    (*parser <WhiteSpace>)
    (*caten 7)
    (*pack-with (lambda (sp1 del1 sp2 num sp3 del2 sp4)
        `(,@num)
      ))
     *plus
    (*caten 2)
       (*pack-with (lambda (arrname lst1)
              (if (equal? (length lst1) 0) arrname
                  (if (equal? (length lst1) 1) `(vector-ref ,arrname ,(car lst1))
                    (letrec ((loop
                          (lambda (exp lst)
                            (if (equal? (length lst) 1) 
                                `(vector-ref ,exp ,(car lst))
                                (loop `(vector-ref ,exp ,(car lst)) (cdr lst))
                              ))))
                    (loop `(vector-ref ,arrname ,(car lst1)) (cdr lst1)))))))
       (*parser <WhiteSpace>)
        (*caten 3)
          (*pack-with (lambda (space exp space2)
            exp))
  done))  



(define <InfixArgList>
    (new 
        (*parser <WhiteSpace>)
        (*delayed (lambda() <InfixExpression>))
        (*parser <WhiteSpace>)
        (*parser (char (integer->char 44)))
        (*parser <WhiteSpace>)
        (*delayed (lambda() <InfixExpression>))
        (*parser <WhiteSpace>)
        (*caten 5)
        (*pack-with (lambda (sp1 del1 sp2 num sp3)
            `(,@num)
          ))
        *star
        (*parser <WhiteSpace>)
        (*caten 4)
        (*pack-with
          (lambda (sp1 num1 lst sp2)
            `(,num1 ,@lst)))
        (*parser <epsilon>)
        (*disj 2)

        done)) 



(define <InfixFuncall>
    (new 

          (*parser <WhiteSpace>)
          (*parser <CommentsInf>) *star
          (*parser <WhiteSpace>)
          (*parser <InfixLast>)
          (*parser <WhiteSpace>)
          (*parser (char (integer->char 40)))
          (*parser <WhiteSpace>)
          (*parser <InfixArgList>)
          (*parser <WhiteSpace>)
          (*parser (char (integer->char 41)))
          (*parser <WhiteSpace>)
          (*caten 7)
          (*pack-with 
            (lambda (sp1 par1 sp2 exp2 sp3 par2 sp4)
              exp2)
              ) 
            *star
          (*caten 2)
          (*pack-with 
            (lambda (func exp2)
                (if (equal? (length exp2) 0) func
                    (if (equal? (length exp2) 1) `(,func ,@(car exp2))
                            (letrec ((loop
                            (lambda (exp1 lst1)
                                (if (equal? (length lst1) 1) `(,exp1 ,@(car lst1))
                                    (loop `(,exp1 ,@(car lst1)) (cdr lst1))))))
                                   (loop `(,func ,@(car exp2)) (cdr exp2)))))))
         
          (*parser <WhiteSpace>)
          (*parser <CommentsInf>) *star
          (*parser <WhiteSpace>)
          (*caten 7)
          (*pack-with (lambda (sp1 com1 sp2 exp sp3 inf sp4)
            exp ))
      done))

(define <InfixPow>
    (new
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <InfixArrayGet>)
        (*parser <InfixParen>)
        (*parser <InfixFuncall>)
        (*disj 3)
        (*parser (word "-"))
        (*parser <InfixArrayGet>)
        (*parser <InfixParen>)
        (*parser <InfixFuncall>)
        (*disj 3)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <PowerSymbol>)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <InfixArrayGet>)
        (*parser <InfixParen>)
        (*parser <InfixFuncall>)
        (*disj 3)
        (*parser (word "-"))
        (*parser <InfixArrayGet>)
        (*parser <InfixParen>)
        (*parser <InfixFuncall>)
        (*disj 3)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*caten 8)         
        (*pack-with (lambda (sp1 com1 delim sp2 com2 exp2 sp3 com3)
            `(,@exp2)))
        *star
        (*caten 2) 
        (*pack-with (lambda (exp2 lst)
                (if (equal? (length lst) 0) exp2
                (if (equal? (length lst) 1) `(expt ,exp2 ,(car lst))
                 (letrec ((loop
                            (lambda (exp1 lst1)
                                (if (equal? (length lst1) 2) `(expt ,exp1 (expt ,(car lst1) ,(cadr lst1)))
                                    `(expt ,exp1 ,(loop (car lst1) (cdr lst1)))))))
                                   (loop exp2 lst))))))
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*caten 5)
          (*pack-with (lambda (space com1 exp space2 com2)
            exp))
        done))



(define <InfixMul>
    (new
        (*parser <WhiteSpace>) 
        (*parser <InfixPow>)
        (*parser (word "-"))
        (*parser <InfixPow>)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser (word "*"))
        (*parser (word "/"))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <InfixPow>)
        (*parser (word "-"))
        (*parser <InfixPow>)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*caten 5)         
         (*pack-with (lambda (sp1 delim sp2 exp2 sp3)
            `(,(string->symbol (list->string delim)) ,exp2)))
        *star
        (*caten 2) 
        (*pack-with (lambda (exp1 lst)
                (if (equal? (length lst) 0) exp1
                (letrec ((loop
                            (lambda (exp1 lst1)
                                (if (equal? (length lst1) 1) `(,(caar lst1) ,exp1 ,(cadar lst1))
                                    (loop `(,(caar lst1) ,exp1 ,(cadar lst1)) (cdr lst1))))))
                                   (loop exp1 lst)))))
        (*parser <WhiteSpace>)
        (*caten 3)
          (*pack-with (lambda (space exp space2)
            exp))
        done))


(define <InfixAddSub>
    (new
        (*parser <WhiteSpace>)
        (*parser <InfixMul>)
        (*parser (word "-"))
        (*parser <InfixMul>)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>) ; sp n sp
        (*parser <CommentsInf>) *star
        (*parser (word "+"))
        (*parser (word "-"))
        (*disj 2)
        (*parser <WhiteSpace>) ; sp n sp cm + sp
        (*parser <CommentsInf>) *star
        (*parser <InfixMul>)
        (*parser (word "-"))
        (*parser <InfixMul>)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>) ; sp n sp cm + sp cm n sp
        (*parser <CommentsInf>) *star ; sp n sp cm + sp cm n sp cm
        (*caten 8)         
        (*pack-with (lambda (sp1 com1 delim sp2 com2 exp2 sp3 com3)
            `(,(string->symbol (list->string delim)) ,exp2)))
        *star
        (*caten 2) 
        (*pack-with (lambda (exp1 lst)
              (if (equal? (length lst) 0) exp1
               (letrec ((loop
                            (lambda (exp1 lst1)
                                (if (equal? (length lst1) 1) `(,(caar lst1) ,exp1 ,(cadar lst1))
                                    (loop `(,(caar lst1) ,exp1 ,(cadar lst1)) (cdr lst1))))))
                                   (loop exp1 lst)))))
        (*parser <WhiteSpace>)
        (*caten 3)
          (*pack-with (lambda (space exp space2)
            exp))
      done)) 


(define <InfixNeg>
  (new
      (*parser <WhiteSpace>)
      (*parser (char (integer->char 45)))
      (*parser <WhiteSpace>)
      (*delayed
        (lambda() <InfixExpression>))
      (*caten 3)
      (*pack-with
        (lambda (a sp expr)
          `(- ,expr)))
      (*parser <WhiteSpace>)
      (*caten 3)
          (*pack-with (lambda (space exp space2)
            exp))
      done))






(define <InfixSexprEscape>
  (new 
      (*parser <WhiteSpace>)
      ;(*parser <CommentsInf>) *star
      (*parser <InfixPrefixExtensionPrefix>)
      (*parser <WhiteSpace>)
       (*parser <CommentsInf>) *star
      ;(*parser <Symbol>)
      (*delayed (lambda () <sexpr2>))
      (*parser <WhiteSpace>)
      (*parser <CommentsInf>) *star
      (*delayed 
        (lambda () <InfixExpression>))
      *star
      (*caten 7)
      (*pack-with (lambda (prefix sp com1 symb sp2 com2 lst)
        (if (equal? (length lst) 0) symb
         `(,symb ,@lst))))
      (*parser <WhiteSpace>) 
      (*caten 3)
        (*pack-with (lambda (sp exp sp2)
          exp))
      done)) ;goes all the way down to infixLast and returns a space, not sure why

(define <InfixExpression>
    (new
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <WhiteSpace>) 
        (*parser <InfixSexprEscape>)
        (*parser <InfixAddSub>)
        ;(*parser <InfixNeg>)
        ;(*parser <InfixArrayGet>)
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <WhiteSpace>)
        (*caten 7)
        (*pack-with (lambda (space comment1 space1 exp space2 comment2 space3)
          exp))
        done))
;(test-string <InfixExpression> "-f(1 , (2*3))")

 ;(test-string <InfixExpression> " 2+4 ")
;(test-string <InfixExpression> "2^7")
;(test-string <InfixExpression> "ab[2]")



   
        
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
;(test-string <InfixExtension> "##2+3+4")
;;;;;;;;;;;;;;;;;;;;;; Sexpr ;;;;;;;;;;;;;;;;;;;;;;

(define <sexpr2>
  ;(^<CommentOutPrefix*>
  (new
    (*parser <WhiteSpace>)
    (*parser <Comments>) *star
    (*parser <WhiteSpace>)
    (*parser <InfixExtension>)
    (*parser <Symbol>)
    (*parser <Boolean>)
    (*parser <Char>)
    (*parser <String>)
    (*parser <ProperList>)
    (*parser <ImproperList>)
    (*parser <Vector>)
    (*parser <Quoted>)
    (*parser <QuasiQuoted>)
    (*parser <Unquoted>)
    (*parser <UnquoteAndSpliced⟩>)
    (*disj 12)
    (*parser <WhiteSpace>)
    (*parser <Comments>) *star
    (*parser <WhiteSpace>)
    (*caten 7)
    (*pack-with 
     (lambda (space1 comm1 space3 expr space2 comm2 space4)
           expr))
  done))


(test-string <Char> "#\\abc")
;(test-string <ProperList> "(#\\a)")



;(test-string <sexpr2> "(cons 1 2)")


;expected: ((match (cons (f (+ x y) (- x z) (* x t) (g (cons x y) (cons x y) (list x y) (h (* x y) (expt x z)))) 2)) (remaining ))
; actual:   ((match (cons (f (+ x y) (- x z) (* x t) (g (cons x y) (cons x y) (x ,y) (h (* x y) (expt x z)))) 2)) (remaining ))