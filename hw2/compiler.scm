(load "pattern-matcher.scm")

(load "pc.scm")


;;;;;;;;;;;;;;;;;;;;;; WhiteSpace;;;;;;;;;;;;;;;;;;;;;;

(define <WhiteSpace>
  (new (*parser (range (integer->char 1) (integer->char 32)))
    *star

    done)
  )


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
       (*delayed (lambda () <sexpr>))
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


(define <CharPrefix>
    (new (*parser (char #\#))
    	(*parser (char #\\))
    	(*caten 2)
      (*pack-with
        (lambda(a b)
          (list #\# #\\)))
	 done))



(define <VisibleSimpleChar>
	(new 
		(*parser (range #\! #\~))
    (*parser (range-ci #\a #\z))
    *not-followed-by
    (*pack
			(lambda (a)
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
  		(*disj 3)
      (*parser <WhiteSpace>)
      (*caten 4)
      (*pack-with
        (lambda(sp1 a b sp2)
          b))
   done))



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
    (*delayed (lambda () <SymbolChar>))
    *not-followed-by 
	done))



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
    (*parser (range #\0 #\9))
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
    (*disj 15)
    done)
  )



(define <Symbol>
  (new
    (*parser <SymbolChar>) *plus
    (*pack (lambda(symbolLst)
                  (string->symbol
                    (list->string symbolLst))))
  done)
  )


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


(define <InfixNumber>
  (new 
    (*parser <Fraction>)
    (*parser <Integer>)
    (*disj 2)
    (*delayed (lambda () <InfixSymbolChar>))
    *not-followed-by 
    done))

(define <InfixSymbolChar>
  (new 
    (*parser (range #\0 #\9))
    (*parser (range #\A #\Z))
    (*pack 
      (lambda (capital)
        (integer->char  (+ (char->integer capital) 32))))
    (*parser (range #\a #\z))
    (*parser (char #\!))
    (*parser (char #\$))
    (*parser (char #\_))
    (*parser (char #\=))
    (*parser (char #\<))
    (*parser (char #\>))
    (*parser (char #\?))
    (*disj 10)
    done))

(define <InfixSymbol>
  (new
    (*parser <InfixNumber>) 
    (*parser <InfixSymbolChar>) *plus
    *not-followed-by
    (*parser <digit-0-9>) *star
    (*parser <InfixSymbolChar>) *plus
    (*parser <digit-0-9>) *star
    (*caten 3)
    (*pack-with 
      (lambda (nums1 charsLst nums2)
      `(,@nums1 ,@charsLst ,@nums2)))
    (*pack 
      (lambda (lst)
        (string->symbol (list->string lst))))        
    (*disj 2)

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
    (*parser <WhiteSpace>)
    (*parser <InfixSymbol>)
    (*parser <InfixNumber>)
    (*disj 2)
    (*parser <WhiteSpace>)
    (*caten 3)
    (*pack-with (lambda (sp1 expr sp2)
      expr))
    done))     



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


(define <InfixFuncallArrayCall>
  (new 
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <InfixParen>)
    (*parser <InfixLast>)
    (*delayed (lambda () <InfixSexprEscape>))
    (*disj 3)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 40)))
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*parser <InfixArgList>)
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 41)))
    (*parser <WhiteSpace>)
    (*caten 11)
    (*pack-with (lambda (ws1 delim1 ws2 com1 ws3 args ws4 com2 ws5 delim2 ws6) (list args)))
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 91)))
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*delayed (lambda () <InfixExpression>))
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*parser (char (integer->char 93)))
    (*parser <WhiteSpace>)
    (*caten 11)
    (*pack-with (lambda (ws1 delim1 ws2 com1 ws3 args ws4 com2 ws5 delim2 ws6) args))
    (*disj 2) *plus
    (*parser <CommentsInf>) *star
    (*parser <WhiteSpace>)
    (*parser <CommentsInf>) *star
    (*caten 8)
    (*pack-with (lambda (ws1 com1 func com2 args com3 ws2 com4) 
                (cond ((equal? (length args) 0) func) 
                      ((and (equal? (length args) 1) (list? (car args)) (equal? (length (car args)) 1) (not (list? (car (car args))))) 
                                            `(,func ,@(car args)))
                      ((and (equal? (length args) 1) (list? (car args)) (equal? (length (car args)) 1) (list? (car (car args)))) 
                                            `(,func ,@(car (car args))))
                      ((and (equal? (length args) 1) (list? (car args))) 
                                            `(vector-ref ,func ,(car args)))
                      ((and (equal? (length args) 1) (not (list? (car args)))) `(vector-ref ,func ,(car args)))
                      (else (letrec ((loop (lambda (func1 args1)
                              (cond
                                ((and (equal? (length args1) 1) (list? (car args1)) (equal? (length (car args1)) 1) (not (list? (car (car args1))))) 
                                                      `(,func1 ,@(car args1)))
                                ((and (equal? (length args1) 1) (list? (car args1)) (equal? (length (car args1)) 1) (list? (car (car args1)))) 
                                                      `(,func1 ,@(car (car args1))))
                                ((and (equal? (length args1) 1) (list? (car args1))) 
                                                      `(vector-ref ,func1 ,(car args1)))
                                ((and (equal? (length args1) 1) (not (list? (car args1)))) `(vector-ref ,func1 ,(car args1)))
                                ((and (not (list? (car args1)))) (loop `(vector-ref ,func1 ,(car args1)) (cdr args1)))
                                ((and (list? (car args1)) (equal? (length (car args1)) 1) (not (list? (car (car args1))))
                                                     (loop `(,func1 ,@(car args1)) (cdr args1))))
                                ((and (list? (car args1)) (equal? (length (car args1)) 1) (list? (car (car args1)))) 
                                                     (loop `(,func1 ,@(car (car args1))) (cdr args1)))
                                ((and (list? (car args1)))
                                                      (loop `(vector-ref ,func1 ,(car args1)) (cdr args1)))))))
                              (loop func args))))
                        ))
    done)
  )



(define <InfixSexprEscape>
  (new 
      (*parser <WhiteSpace>)
      (*parser <InfixPrefixExtensionPrefix>)
      (*parser <WhiteSpace>)
       (*parser <CommentsInf>) *star
      (*delayed (lambda () <sexpr>))
      (*parser <WhiteSpace>)
      (*parser <CommentsInf>) *star
      (*caten 6)
      (*pack-with (lambda (prefix sp com1 symb sp2 com2)
         `(,@symb)))
      (*parser <WhiteSpace>) 
      (*caten 3)
        (*pack-with (lambda (sp exp sp2)
          exp))
      done)) 


(define <InfixPow>
    (new
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <InfixFuncallArrayCall>)
        (*parser <InfixParen>)
        (*parser <InfixSexprEscape>)
        (*parser <InfixLast>)
        (*disj 4)
        (*parser (word "-"))
        (*parser <InfixFuncallArrayCall>)
        (*parser <InfixParen>)
        (*parser <InfixSexprEscape>)
        (*parser <InfixLast>)
        (*disj 4)
        (*caten 2)
        (*pack-with (lambda (minus exp)
            `(- ,exp)))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <PowerSymbol>)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
         (*parser <InfixFuncallArrayCall>)
        (*parser <InfixParen>)
        (*parser <InfixSexprEscape>)
        (*parser <InfixLast>)
        (*disj 4)
        (*parser (word "-"))
        (*parser <InfixFuncallArrayCall>)
        (*parser <InfixParen>)
        (*parser <InfixSexprEscape>)
        (*parser <InfixLast>)
        (*disj 4)
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
        (*parser <WhiteSpace>)
        (*parser (word "*"))
        (*parser (word "/"))
        (*disj 2)
        (*parser <WhiteSpace>)
        (*parser <InfixPow>)
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
        (*parser <WhiteSpace>) 
        (*parser <CommentsInf>) *star
        (*parser (word "+"))
        (*parser (word "-"))
        (*disj 2)
        (*parser <WhiteSpace>) 
        (*parser <CommentsInf>) *star
        (*parser <InfixMul>)
        (*parser <WhiteSpace>) 
        (*parser <CommentsInf>) *star 
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



(define <InfixExpression>
    (new
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <WhiteSpace>) 
        (*parser <InfixAddSub>)
        (*parser <WhiteSpace>)
        (*parser <CommentsInf>) *star
        (*parser <WhiteSpace>)
        (*caten 7)
        (*pack-with (lambda (space comment1 space1 exp space2 comment2 space3)
          exp))
        done))


   
        
(define <InfixExtension>
    (new (*parser <InfixPrefixExtensionPrefix>)
        (*parser <InfixExpression>)
        (*caten 2)
        (*pack-with 
            (lambda (a b)
                b))
        done))


;;;;;;;;;;;;;;;;;;;;;; Sexpr ;;;;;;;;;;;;;;;;;;;;;;

(define <sexpr>
  (new
    (*parser <WhiteSpace>)
    (*parser <Comments>) *star
    (*parser <WhiteSpace>)
    (*parser <InfixExtension>)
    (*parser <Number>)
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
    (*disj 13)
    (*parser <WhiteSpace>)
    (*parser <Comments>) *star
    (*parser <WhiteSpace>)
    (*caten 7)
    (*pack-with 
     (lambda (space1 comm1 space3 expr space2 comm2 space4)
           expr))
  done))


(define <Sexpr> <sexpr>)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;tag-parser;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;




(define beginify
	(lambda (s)
		(cond
			((null? s) *void-object*)
			((null? (cdr s)) (car s))
			(else `(begin ,@s)))))

(define simple-const?
	(lambda (var)
		(cond 
			((null? var) var)
			((vector? var) var)
			((equal? var #t) var)
			((equal? var #f) #t) 
			((char? var) var)
			((number? var) var)
			((string? var) var)
			(else #f)
			)
		))

(define *reserved-words*
	'(and begin cond define do else if lambda
		let let* letrec or quasiquote unquote
		unquote-splicing quote set!))

(define reserved-words?
	(lambda (var)
		(not (ormap (lambda (rw)
					 (equal? rw var)) *reserved-words*))))

(define var?
	(lambda (var)
		(cond 
			((and (symbol? var) 
				(reserved-words? var)) var)
			(else #f)
			)))

(define *void-object* (void))

(define improper-list?
	(lambda (vars)
		(if (pair? vars)
				(letrec ((loop 
							(lambda (lst rest)
								(cond 
									 ((pair? rest) (loop `(,@lst ,(car rest)) (cdr rest)))
									 (else (list lst rest))))))
				(loop (list) vars))
			#f
			)))


(define expWithOutSeq
	(lambda (exp)
		(if (null? exp)
			(list)
			(if (and (list? (car exp)) (equal? (car (car exp)) 'seq))
				`(,@(car (cdr(car exp))) ,@(expWithOutSeq (cdr exp)))
				`(,(car exp) ,@(expWithOutSeq (cdr exp))))
		)))



;;;;;;macro helpres;;;;;;;
(define MIT-define-to-regular-define
	(lambda (var&params exp)
			`(define ,(car var&params) (lambda ,(cdr var&params) ,exp))))

(define letVariables?
	(lambda (lst)
		(and (list? lst) (andmap 
			(lambda (vals) (and (pair? vals) (equal? (length vals) 2))) lst))))

(define vals-getter
	(lambda (lst)
		(map cadr lst)))

(define validList?
	(lambda (lst)
		(let ((lst (if (list? lst) lst (pairToList lst))))
		(if (null? lst) #t
			(if (member (car lst) (cdr lst)) #f
				(validList? (cdr lst)))))))

(define pairToList
	(lambda (lst)
		(letrec ((loop (lambda (lst rest)
					(if (not (pair? rest)) (append lst (list rest))
						(loop (append lst (list (car rest))) (cdr rest))))))
			(loop (list) lst))
	))




		


(define vars-getter
	(lambda (var lst)
		(let ((vars (cons var (map car lst))))
			(if (validList? vars)
				vars
				(error 'let "Variables must be different")))))



(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
	   (eq? (car e) tag)
	   (pair? (cdr e))
	   (null? (cddr e))))))

(define quote? (^quote? 'quote))
(define unquote? (^quote? 'unquote))
(define unquote-splicing? (^quote? 'unquote-splicing))

(define const-quasi?
  (let ((simple-sexprs-predicates
	 (list boolean? char? number? string?)))
    (lambda (e)
      (or (ormap (lambda (p?) (p? e))
		 simple-sexprs-predicates)
	  (quote? e)))))

(define quotify
  (lambda (e)
    (if (or (null? e)
	    (pair? e)
	    (symbol? e)
	    (vector? e))
	`',e
	e)))

(define unquotify
  (lambda (e)
    (if (quote? e)
	(cadr e)
	e)))

(define const-pair?
  (lambda (e)
    (and (quote? e)
	 (pair? (cadr e)))))

(define expand-qq
  (letrec ((expand-qq
	    (lambda (e)
	      (cond ((unquote? e) (cadr e))
		    ((unquote-splicing? e)
		     (error 'expand-qq
		       "unquote-splicing here makes no sense!"))
		    ((pair? e)
		     (let ((a (car e))
			   (b (cdr e)))
		       (cond ((unquote-splicing? a)
			      `(append ,(cadr a) ,(expand-qq b)))
			     ((unquote-splicing? b)
			      `(cons ,(expand-qq a) ,(cadr b)))
			     (else `(cons ,(expand-qq a) ,(expand-qq b))))))
		    ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
		    ((or (null? e) (symbol? e)) `',e)
		    (else e))))
	   (optimize-qq-expansion (lambda (e) (optimizer e (lambda () e))))
	   (optimizer
	    (compose-patterns
	     (pattern-rule
	      `(append ,(? 'e) '())
	      (lambda (e) (optimize-qq-expansion e)))
	     (pattern-rule
	      `(append ,(? 'c1 const-pair?) (cons ,(? 'c2 const-quasi?) ,(? 'e)))
	      (lambda (c1 c2 e)
		(let ((c (quotify `(,@(unquotify c1) ,(unquotify c2))))
		      (e (optimize-qq-expansion e)))
		  (optimize-qq-expansion `(append ,c ,e)))))
	     (pattern-rule
	      `(append ,(? 'c1 const-pair?) ,(? 'c2 const-pair?))
	      (lambda (c1 c2)
		(let ((c (quotify (append (unquotify c1) (unquotify c2)))))
		  c)))
	     (pattern-rule
	      `(append ,(? 'e1) ,(? 'e2))
	      (lambda (e1 e2)
		(let ((e1 (optimize-qq-expansion e1))
		      (e2 (optimize-qq-expansion e2)))
		  `(append ,e1 ,e2))))
	     (pattern-rule
	      `(cons ,(? 'c1 const-quasi?) (cons ,(? 'c2 const-quasi?) ,(? 'e)))
	      (lambda (c1 c2 e)
		(let ((c (quotify (list (unquotify c1) (unquotify c2))))
		      (e (optimize-qq-expansion e)))
		  (optimize-qq-expansion `(append ,c ,e)))))
	     (pattern-rule
	      `(cons ,(? 'e1) ,(? 'e2))
	      (lambda (e1 e2)
		(let ((e1 (optimize-qq-expansion e1))
		      (e2 (optimize-qq-expansion e2)))
		  (if (and (const-quasi? e1) (const-quasi? e2))
		      (quotify (cons (unquotify e1) (unquotify e2)))
		      `(cons ,e1 ,e2))))))))
    (lambda (e)
      (optimize-qq-expansion
       (expand-qq e)))))



(define parse
	(let ((run 
			(compose-patterns
				;;;;const
				(pattern-rule
					(? 'c simple-const?)
					(lambda (c) `(const ,c)))
				;;;;qoute-const
				(pattern-rule
					`(quote ,(? 'c))
					(lambda (c) `(const ,c)))
				;;;;variable
				(pattern-rule
					(? 'v var?)
					(lambda (v) `(var ,v)))
				;;;; if 2 parms
				(pattern-rule
					`(if ,(? 'test) ,(? 'dit))
					(lambda (test dit) `(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
				;;;; if 3 params
				(pattern-rule
					`(if ,(? 'test) ,(? 'dit) ,(? 'dif))
					(lambda (test dit dif) `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
				;;;;; or
				(pattern-rule
					`(or . ,(? 'rest))
					(lambda (rest) 
						(cond 
							((null? rest) (parse #f))
							((equal? (length rest) 1) (parse (car rest)))
							(else `(or ,(map parse rest))))))
				;;;;;;;; sequences i.e. begin
				(pattern-rule
					`(begin . ,(? 'rest))
					(lambda (rest) 
						(cond ((null? rest) `(const ,*void-object*))
								((equal? (length rest) 1) (parse (car rest)))
								(else (let ((fixedRest  rest))
											`(seq ,(expWithOutSeq (map parse fixedRest))))))))
				;;;;;;;; let-sequences i.e. begin
				(pattern-rule
					`(letseq ,(? 'args list?))
					(lambda (args) (map parse args)))
				;;;; regular lambda 
				(pattern-rule
					`(lambda ,(? 'vars list? validList?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-simple ,vars ,(parse (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;; lambda optional args
				(pattern-rule
					`(lambda ,(? 'vars pair? validList?) ,(? 'body) . ,(? 'rest))
					(lambda (vars body rest) `(lambda-opt ,@(improper-list? vars) ,(parse (beginify (cons body rest)))))) ;notice begin is not memomash
				;;;;;;; variadic lambda
				(pattern-rule 
					`(lambda ,(? 'var validList?) . ,(? 'rest))
					(lambda (var rest) `(lambda-var ,var ,(parse (beginify rest))))) ;notice begin is not memomash, WTF args
				;;;; define
				(pattern-rule
					`(define ,(? 'var&params)  ,(? 'exp) . ,(? 'rest))
					(lambda (var&params exp rest) 
					(if (pair? var&params)
						 (parse (MIT-define-to-regular-define var&params (beginify (cons exp rest))))
				 		`(def ,(parse var&params) ,(parse (beginify (cons exp rest))))))
				)
				;;;;;;set;;;;;;
				(pattern-rule 
					`(set! ,(? 'var var?) ,(? 'exp))
						(lambda (var exp)
							`(set ,(parse var) ,(parse exp))))
				;;;;;;;;;;; quasi quote ;;;;;;;;;;;;
				(pattern-rule
					`(quasiquote . ,(? 'expr))
					(lambda (expr)
						(if (or (null? expr) (> (length expr) 1))
							(error 'quasiquote "wrong params")
						(parse (expand-qq (car expr))))
						))
				;;;;;;;;;;;; unqoute;;;;;;;;
				(pattern-rule
					`(unqoute . ,(? 'expr))
					(lambda (expr)
						(expand-qq expr)))
				;;;;;;;;;;;; unqoute-splicing;;;;;;;;
				(pattern-rule
					`(unquote-splicing . ,(? 'expr))
					(lambda (expr)
						(expand-qq expr)))
				;;;; applic
				(pattern-rule
					`( ,(? 'func reserved-words?) . ,(? 'rest) )
					(lambda (func rest)
						`(applic ,(parse func) ,(map parse rest))
						))
				;;;;;;;;;;;empty letrec ;;;;;;;;;
				(pattern-rule
					`(letrec ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse
								`((lambda ()
										((lambda () ,(beginify (cons expr exprs)))
										 ,@vars))	
									,@vars)
								)))
				;;;;;;;;;;;letrec ;;;;;;;;;
				(pattern-rule
					`(letrec ((,(? 'var var?) ,(? 'val)) . ,(? 'rest letVariables?)) . ,(? 'exprs))
					(lambda (var val rest exprs)
						(let* ((vals (cons val (vals-getter rest)))
								(vars (vars-getter var rest))
								(sets (map (lambda (var2 val2)
													`(set! ,var2 ,val2))
													 vars vals))
								(emptylst (list))
								(falsevars (map (lambda (val) '#f) vals)))
							(parse
								`((lambda (,@vars)
									,(beginify 
										`(,@sets ((lambda () ,@exprs) ,@emptylst))	
									)) 
									,@falsevars
								)))))
				;;;;;;;;;;empty let ;;;;;;;;
				(pattern-rule
					`(let ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;;;;;;;;let ;;;;;;;;;
				(pattern-rule
					`(let ((,(? 'var var?) ,(? 'val)) . ,(? 'rest letVariables?)) . ,(? 'exprs))
					(lambda (var val rest exprs)
						(let ((vals (cons val (vals-getter rest)))
								(vars (vars-getter var rest)))
							(parse
								`((lambda (,@vars)
									,@exprs) ,@vals)))))
				;;;;; empty let* ;;;;;;;;;;;
				(pattern-rule
					`(let* ,(? 'vars list? null?) ,(? 'expr) . ,(? 'exprs list?))
						(lambda (vars expr exprs) 
							(parse 
								`((lambda () ,(beginify (cons expr exprs)))
								,@vars))))
				;;;;; let * ;;;;;;;
				(pattern-rule
					`(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
					(lambda (var val rest exprs) 
						(if (not (null? rest))
							(parse `(let ((,var ,val)) 
								(let* ,rest . ,exprs)))
							(parse `(let ((,var ,val)) 
								,@exprs)))))

				;;;;;;;;; and ;;;;;;;
				(pattern-rule
					`(and . ,(? 'vals))
					(lambda (vals) 
						(cond ((null? vals) (parse #t))
							((equal? (length vals) 1) (parse (car vals)))
							((equal? (length vals) 2)
								(parse `(if ,(car vals) ,(cadr vals) #f)))
							(else
								(parse `(if ,(car vals) (and ,@(cdr vals)) #f))))))
				;;;;;;;;; cond ;;;;;;;
				(pattern-rule
					`(cond . ,(? 'vals))
					(lambda (vals) 
						(cond 
							((and (equal? (length vals) 2) (equal? (caadr vals) 'else))
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals)))
									(elseseq (if (> (length (cdadr vals)) 1) (beginify (cdadr vals))
													(cadadr vals))))
								(parse 
									`(if ,(caar vals) ,conseq ,elseseq)
									)))
							((equal? (length vals) 1)
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals))))
							 			(parse `(if ,(caar vals) ,conseq))))
							(else 
								(let ((conseq (if (> (length (cdar vals)) 1) (beginify (cdar vals))
													(cadar vals))))
									(parse `(if ,(caar vals) ,conseq
														(cond ,@(cdr vals))
									)))
								)
							)))

				)))
			(lambda (e)
				(run e
						(lambda ()
							(error 'parse
									(format "I can't recognize this: ~s" e)))))))









