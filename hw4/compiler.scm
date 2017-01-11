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



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; homeWork3;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;




(define defGetter
  (lambda (exp rest)
    (letrec ((listDef (list))
        (loop (lambda (exp rest)
            (cond
              ((not (list? exp)) `(,listDef ,exp ,@rest))
              ((null? exp) listDef)
              ((null? rest) (if (equal? (car exp) 'def) 
                      (begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) listDef)
                      `(,listDef ,exp)))
              ((equal? (car exp) 'def) (begin (set! listDef `(,@listDef (set ,(cadr exp) ,(caddr exp)))) (loop (car rest) (cdr rest))))
              (else `(,listDef ,exp ,@rest)))
        )))
        (loop exp rest)
  )))


(define validSeq?
  (lambda (exp)
    (if (null? exp) #f
    (andmap (lambda (shit) (not (equal? (car shit) 'def))) exp))
  ))

(define varsGetter
  (lambda (exp)
    (map (lambda (exp2) (cadadr exp2)) exp)))

(define falseMaker
  (lambda (exp)
    (map (lambda (exp2) '(const #f)) exp)))

(void)

(define noDefines
  (lambda (exp)
    (letrec ((isValidNoDefList #t)
        (loop (lambda (exp2)
            (cond 
              ((not (list? exp2)) (void))
              ((null? exp2) (void))
              ((equal? (car exp2) 'def) (set! isValidNoDefList #f))
              (else (begin (loop (car exp2)) (loop (cdr exp2))))))))
    (begin (loop exp) isValidNoDefList ))))


(define inLambda 
  (let ((run 
      (compose-patterns
        ;;;;def
        (pattern-rule
        `(def ,(? 'var) ,(? 'val) )
          (lambda (var val)  `(seq ((set ,var ,(eliminate-nested-defines-helper val))) )))
        ;;;;seq
        (pattern-rule
        `(seq ,(? 'exp))
          (lambda (exp)  
            (let ((defExp (defGetter (car exp) (cdr exp))))
                (if (validSeq? (car defExp))
                  (let* ((vars (varsGetter (car defExp)))
                      (falseLst (falseMaker vars)))
                      `(applic (lambda-simple ,vars (seq (,@(eliminate-nested-defines-helper (car defExp)) ,@(eliminate-nested-defines-helper (cdr defExp)))))
                        ,falseLst))
                  (if (null? (car defExp)) 
                    `(seq ,(eliminate-nested-defines-helper exp))
                          (error 'inLambda "Seq in not a valid seq: ~s" ))))))
        (pattern-rule
        (? 'exp)
          (lambda (exp)  (eliminate-nested-defines-helper exp)))
    )))  
      (lambda (e)
        (run e
            (lambda ()
              (error 'parse
                  (format "I can't recognize this: ~s" e)))))))


(define eliminate-nested-defines-helper
  (let ((run 
      (compose-patterns
        ;;;;lambda
        (pattern-rule
        `(lambda-simple ,(? 'vars) ,(? 'body) )
          (lambda (vars body) `(lambda-simple ,vars ,(inLambda  body ))))
        (pattern-rule
        `(lambda-var ,(? 'vars) ,(? 'body) )
          (lambda (vars body) `(lambda-var ,vars ,(inLambda  body ))))
        (pattern-rule
        `(lambda-opt ,(? 'vars) ,(? 'var) ,(? 'body) )
          (lambda (vars var body) `(lambda-opt ,vars ,var ,(inLambda  body ))))
        (pattern-rule
        (? 'exp)
          (lambda (exp)  
            (cond
              ((null? exp) exp) 
              ((not (list? exp)) exp)
              ((list? (car exp)) `(,(eliminate-nested-defines-helper (car exp)) ,@(eliminate-nested-defines-helper (cdr exp))))
              (else `(,(car exp) ,@(eliminate-nested-defines-helper (cdr exp)))))))
    )))
      (lambda (e)
        (run e
            (lambda ()
              (error 'parse
                  (format "I can't recognize this: ~s" e)))))))


(define eliminate-nested-defines
  (lambda (exp)
    (let ((noNestedDefines (eliminate-nested-defines-helper exp)))
      (if (noDefines (cdr noNestedDefines))
        noNestedDefines
        (error 'define "tibeten calender ~s" ))
      )
    ))

;;;;;;;;;;;;;;;;;;;;; Boxing of variables ;;;;;;;;;;;;;;;;;;;;


(define boundOccurence-helper 
  (lambda (var exp) 
    (letrec ((isBoundOccurence #f)
        (loop (lambda (exp2)
            (cond 
              ((and (list? exp2) (equal? `(var ,var) exp2)) (set! isBoundOccurence #t))
              ((not (list? exp2)) (void))
              ((null? exp2) (void))
              ((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
                  (not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
                      (loop (caddr exp2)))
              ((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) (loop (cadddr exp2)))
              ((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
                   (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
                      (void))
              ((and (equal? (car exp2) 'lambda-opt) (member var (append (cadr exp2) (list (caddr exp2))))) (void))
              (else (begin (loop (car exp2)) (loop (cdr exp2))))))))
    (begin (loop exp) isBoundOccurence ))))


(define boundOccurence 
  (lambda (var exp) 
    (letrec ((isBoundOccurence #f)
        (loop (lambda (exp2)
            (cond 
              ((and (not (list? exp2)) (equal? var exp2)) (void))
              ((not (list? exp2)) (void))
              ((null? exp2) (void))
              ((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
                  (not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
                      (let ((helper (boundOccurence-helper  var (caddr exp2))))
                        (if helper (set! isBoundOccurence helper) (void))))
              ((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) 
                    (let ((helper (boundOccurence-helper var (cadddr exp2))))
                        (if helper (set! isBoundOccurence helper) (void)))) 
              ((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
                   (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
                      (void))
              ((and (equal? (car exp2) 'lambda-opt) (member var (append (cadr exp2) (list (caddr exp2))))) (void))
              (else (begin (loop (car exp2)) (loop (cdr exp2))))))))
    (begin (loop exp) isBoundOccurence ))))


(define setExpression 
  (lambda (var exp) 
    (letrec ((isSetOccurence #f)
        (loop (lambda (exp2)
            (cond 
              ((not (list? exp2)) (void))
              ((null? exp2) (void))
              ((and (equal? (car exp2) 'set) (equal? (cadadr exp2) var)) 
                      (set! isSetOccurence #t))
              ((and (equal? (car exp2) 'set) (equal? (cadadr exp2) var)) (loop (cddr exp2)))
              ((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
                  (not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
                      (loop (caddr exp2)))
              ((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) (loop (cadr (cddr exp2))))
              ((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
                   (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
                      (void))
              ((and (equal? (car exp2) 'lambda-opt)  (member var (append (cadr exp2) (list (caddr exp2))))) (void))
              (else (begin (loop (car exp2)) (loop (cdr exp2))))))))
    (begin (loop exp) isSetOccurence ))))

(define getOccurence 
  (lambda (var exp) 
    (letrec ((isGetOccurence #f)
        (loop (lambda (exp2)
            (cond 
              ((and (list? exp2) (equal? `(var ,var) exp2)) (set! isGetOccurence #t))
              ((not (list? exp2)) (void))
              ((null? exp2) (void))
              ((and (equal? (car exp2) 'set) (equal? (cadadr exp2) var)) (loop (cddr exp2)))
              ((and (or (equal? (car exp2) 'lambda-simple)  (equal? (car exp2) 'lambda-var))
                  (not (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2))))))
                      (loop (caddr exp2)))
              ((and (equal? (car exp2) 'lambda-opt) (not (member var (append (cadr exp2) (list (caddr exp2)))))) (loop (cadr (cddr exp2))))
              ((and (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var))
                   (member var (if (list? (cadr exp2)) (cadr exp2) (list (cadr exp2)))))
                      (void))
              ((and (equal? (car exp2) 'lambda-opt)  (member var (append (cadr exp2) (list (caddr exp2))))) (void))
              (else (begin (loop (car exp2)) (loop (cdr exp2))))))))
    (begin (loop exp) isGetOccurence ))))


(define createBoxingLst
  (lambda (exp) ;assuming we recieve a lambda
    (let* (
        (body (if (equal? (car exp) 'lambda-opt)
                (cadddr exp)
                (caddr exp)))
        (varsToBox (map 
              (lambda (var) 
                  (if (and (boundOccurence  var body) (setExpression  var body) (getOccurence  var body)) 
                    `(var ,var)
                    (void)))  
              (cond 
                ((equal? (car exp) 'lambda-opt) (append (cadr exp) (list (caddr exp))))
                ((equal? (car exp) 'lambda-var) (list (cadr exp)))
                (else (cadr exp)))
        ))
    )
    (remove (void) varsToBox)))
  )

(define createSetBoxExpHelper
  (lambda (lstOfVars)
    (cond 
      ((null? lstOfVars) (void))
      ((null? (cdr lstOfVars)) `((set ,(car lstOfVars) (box ,(car lstOfVars))) ))
      (else `( (set ,(car lstOfVars) (box ,(car lstOfVars))) ,@(createSetBoxExpHelper (cdr lstOfVars))))
    )
  )
)

(define createSetBoxExp
  (lambda (lstOfVars)
    (if (null? lstOfVars) lstOfVars
      (let ((setBoxLst (createSetBoxExpHelper lstOfVars)))
           setBoxLst
      ))  ))


(define createBodyBoxWithOneVar 
  (lambda (var body)
    (cond 
        ((not (list? body)) body)
        ((null? body) body)
        ((and (or (equal? (car body) 'lambda-simple)  (equal? (car body) 'lambda-var))
            (member (cadr var) (if (list? (cadr body)) (cadr body) (list (cadr body)))))
                body)
        ((and (equal? (car body) 'lambda-opt) (member (cadr var) (append (cadr body) (list (caddr body)))))  body)

        ((and (equal? (car body) 'set) (equal? (cadr body) var)) `(box-set ,var ,@(createBodyBoxWithOneVar var (cddr body))))

        ((equal? body var) `(box-get ,var))
        (else  
              (cons (createBodyBoxWithOneVar var (car body)) (createBodyBoxWithOneVar var (cdr body)))))
  )
  )

(define createBodyBoxExp
  (lambda (lstVars body)
    (let ((bodyExp body))
      (begin 
        (map (lambda (var) (set! bodyExp (createBodyBoxWithOneVar var bodyExp))) lstVars)
        bodyExp
      ))))

(define changingLambdaWithBoxing
  (lambda (exp)
    (let* 
      ((params (if (equal? (car exp) 'lambda-opt) 
            (list (cadr exp) (caddr exp)) 
            (if (list? (cadr exp)) (cadr exp) (cadr exp))))
      (body (if (equal? (car exp) 'lambda-opt)
          (cadddr exp)
          (caddr exp)))
      (lstToBox (createBoxingLst exp)))
      (if (null? lstToBox) 
        (if (equal? (car exp) 'lambda-opt) `(,(car exp) ,(cadr exp) ,(caddr exp) ,(box-set body))
          `(,(car exp) ,params ,(box-set body)))
        (let ((body2 (if (equal? (car body) 'seq) (cadr body) body)))
              (cond 
                ((and (equal? (car exp) 'lambda-opt) (equal? (car body) 'seq))
                    `(,(car exp) ,(cadr exp) ,(caddr exp) 
                      (seq (,@(createSetBoxExp (createBoxingLst exp)) ,@(createBodyBoxExp (createBoxingLst exp) (box-set body2))))))
                ((equal? (car exp) 'lambda-opt) 
                  `(,(car exp) ,(cadr exp) ,(caddr exp) 
                    (seq (,@(createSetBoxExp (createBoxingLst exp)) ,(createBodyBoxExp (createBoxingLst exp) (box-set body2))))))
                ((equal? (car body) 'seq) 
                  `(,(car exp) ,params 
                    (seq (,@(createSetBoxExp (createBoxingLst exp))  ,@(createBodyBoxExp (createBoxingLst exp) (box-set body2))))))
                (else 
                  `(,(car exp) ,params 
                    (seq (,@(createSetBoxExp (createBoxingLst exp))  ,(createBodyBoxExp (createBoxingLst exp) (box-set body2))))))
                ))))
  )
)



(define box-set
  (lambda (exp)
    (cond ((not (list exp)) exp)
          ((null? exp) exp)
          ((or (equal? (car exp) 'lambda-simple) (equal? (car exp) 'lambda-opt) (equal? (car exp) 'lambda-var))
            (changingLambdaWithBoxing exp))
          (else (cons (if (list? (car exp)) (box-set (car exp)) (car exp)) (box-set (cdr exp))))
      )
  )
)



;;;;;;;;;;;;;;;;;;;;; Removing redundant applications ;;;;;;;;;;;;;;;;;;;;

(define changingApplicLambdaNil
  (lambda (exp)
     (car (cddadr exp))
  )
)


(define remove-applic-lambda-nil
  (lambda (exp)
  (cond ((not (list exp)) exp)
          ((null? exp) exp)
          ((and (equal? (car exp) 'applic) (equal? (caadr exp) 'lambda-simple) (null? (cadadr exp)) (null? (caddr exp)))
            (remove-applic-lambda-nil (changingApplicLambdaNil exp))) 
          (else (cons (if (list? (car exp)) (remove-applic-lambda-nil (car exp)) (car exp)) (remove-applic-lambda-nil (cdr exp))))
      )
  )
)



;;;;;;;;;;;;;;;annotating Variables with their Lexical address;;;;;;;;;


(define pvarLstMaker
  (lambda (exp) ;assuming is a lambda
    (letrec ((pvars (cond ((equal? (car exp) 'lambda-var) (list (cadr exp)))
              ((equal? (car exp) 'lambda-opt) `(,@(cadr exp) ,(caddr exp))) 
              (else (cadr exp))))
        (loop (lambda (var rest num)
          (if (null? rest) (list `(pvar ,var ,num))
            (cons `(pvar ,var ,num) (loop (car rest) (cdr rest) (+ num 1))))
          )))
      (if (null? pvars) '()
      (loop (car pvars) (cdr pvars) 0)))
      ))

(define getPvarLocation
  (lambda (var pvarsLst)
    (letrec ((loop (lambda (pvar restPvars)
      (if (equal? var (cadr pvar))
        (caddr pvar)
        (loop (car restPvars) (cdr restPvars))
        ))))
    (loop (car pvarsLst) (cdr pvarsLst)))))

(define bvarLstMaker
  (lambda (currentPvars oldPvars oldBvars) ;assuming in a lambda and already has pvars list, pvars are the given pvars, and potentialbvars are the oldPvars
    (letrec ((loopOldPvars (lambda (var rest)
          (cond 
            ((ormap (lambda (pvar) (equal? (cadr var) (cadr pvar))) currentPvars)
              (if (null? rest) rest
                (loopOldPvars (car rest) (cdr rest))))
            (else 
              (let ((oldPvarLocation (getPvarLocation (cadr var) oldPvars)))
                (if (null? rest)
                  (list `(bvar ,(cadr var) 0 ,oldPvarLocation))
                  (cons `(bvar ,(cadr var) 0 ,oldPvarLocation) (loopOldPvars (car rest) (cdr rest))))))
            ;;;;compare to bvars! and attach to it + give them bigger number... 
          )))
        (loopOldBvars (lambda (var rest)
              (cond 
                ((ormap (lambda (pvar) (equal? (cadr var) (cadr pvar))) currentPvars)
                  (if (null? rest) rest
                    (loopOldBvars (car rest) (cdr rest))))
                (else 
                    (if (null? rest)
                      (list `(bvar ,(cadr var) ,(+ 1 (caddr var)) ,(cadddr var)))
                      (cons `(bvar ,(cadr var) ,(+ 1 (caddr var)) ,(cadddr var)) (loopOldBvars (car rest) (cdr rest))))))
              )))
      (cond (( and (null? oldPvars) (null? oldBvars)) '())
        ((null? oldBvars) (loopOldPvars (car oldPvars) (cdr oldPvars)))
        ((null? oldPvars) (loopOldBvars (car oldBvars) (cdr oldBvars)))
        (else `(,@(loopOldPvars (car oldPvars) (cdr oldPvars)) ,@(loopOldBvars (car oldBvars) (cdr oldBvars))))))
      ))

(define findNewVar
  (lambda (var pvars bvars)
    (letrec ((getNewVar (lambda (newvar rest)
          (if (equal? var (cadr newvar)) newvar
            (getNewVar (car rest) (cdr rest)))))
        (findVar (lambda (pvars bvars)
          (cond 
            ((ormap (lambda (pvar) (equal? var (cadr pvar))) pvars)
              (getNewVar (car pvars) (cdr pvars)))
            ((ormap (lambda (bvar) (equal? var (cadr bvar))) bvars)
              (getNewVar (car bvars) (cdr bvars)))
            (else `(fvar ,var))
          )
      )))
    (findVar pvars bvars))))


(define switchVars
  (lambda (exp pvars bvars) ;no lambda, only body
    (cond 
      ((not (list? exp)) exp)
      ((null? exp) exp)
      ((or (equal? (car exp) 'lambda-simple) (equal? (car exp) 'lambda-opt) (equal? (car exp) 'lambda-var))
        (peFindLambdas exp pvars bvars))
      ((equal? (car exp) 'var)
        (let ((replacement (findNewVar (cadr exp) pvars bvars)))
          replacement))
      (else `(,(switchVars (car exp) pvars bvars) ,@(switchVars (cdr exp) pvars bvars))))
  ))

(define peFindLambdas
  (lambda (exp2 oldPvars oldBvars)
      (cond 
        ((null? exp2) exp2)
        ((not (list? exp2)) exp2)
        ((equal? (car exp2) 'var)
          (let ((replacement (findNewVar (cadr exp2) oldPvars oldBvars)))
            replacement))
        ((or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-opt) (equal? (car exp2) 'lambda-var))
          (let* 
            ((pvars (pvarLstMaker exp2))
            (bvars (bvarLstMaker pvars oldPvars oldBvars)))
            (if (or (equal? (car exp2) 'lambda-simple) (equal? (car exp2) 'lambda-var)) 
                `(,(car exp2) ,(cadr exp2) ,(switchVars (caddr exp2) pvars bvars))
              `(,(car exp2) ,(cadr exp2) ,(caddr exp2) ,(switchVars (cadddr exp2) pvars bvars)))))
        (else `(,(peFindLambdas (car exp2) oldPvars oldBvars) ,@(peFindLambdas (cdr exp2) oldPvars oldBvars))))))


(define pe->lex-pe
  (lambda (exp)
      (peFindLambdas exp '() '())
      ))





;;;;;;;;;;;;;;;;;;;;;  Annotating tail calls ;;;;;;;;;;;;;;;;;;;;


(define annotate-tc
  (lambda (exp)
    (letrec ((loop
                (lambda (expr tail?)
                    (cond
                      ((not (list? expr)) expr)
                      ((null? expr) expr)
                      ((equal? (car expr) 'lambda-simple) (list 'lambda-simple (cadr expr) (loop (caddr expr) #t))) 
                      ((equal? (car expr) 'lambda-opt) (list 'lambda-opt (cadr expr) (caddr expr) (loop (cadddr expr) #t))) 
                      ((equal? (car expr) 'lambda-var) (list 'lambda-var (cadr expr) (loop (caddr expr) #t)))
                      ((equal? (car expr) 'if3) 
                              (list 'if3 (loop (cadr expr) #f) (loop (caddr expr) tail?) (loop (cadddr expr) tail?)))

                      ((equal? (car expr) 'seq) `(seq (,@(map (lambda (seqExp) (loop seqExp #f)) (reverse (cdr (reverse (cadr expr))))) ,(loop (car (reverse (cadr expr))) tail?))))

                      ((equal? (car expr) 'or) `(or (,@(map (lambda (orExp) (loop orExp #f)) (reverse (cdr (reverse (cadr expr))))) ,(loop (car (reverse (cadr expr) )) tail?))))
                      ((or (equal? (car expr) 'box-set)(equal? (car expr) 'set))  `(,(car expr) ,(cadr expr) ,(loop (caddr expr) #f)))
                      ((and (equal? (car expr) 'applic) (equal? (cadr expr) '(fvar set))) 
                            `(,(if tail? 'tc-applic 'applic) ,(cadr expr) ,(list (caaddr expr) (loop (cadr (caddr expr)) #f))))
                      ((and (equal? (car expr) 'applic) (equal? (cadr expr) '(fvar box-set))) 
                            `(,(if tail? 'tc-applic 'applic) ,(cadr expr) ,(list (caaddr expr) (loop (cadr (caddr expr)) #f))))
                      ((equal? (car expr) 'applic) 
                        (if tail?
                          (list 'tc-applic (loop (cadr expr) #f) (loop (caddr expr) #f))
                          (list 'applic (loop (cadr expr) #f) (loop (caddr expr) #f))
                        )
                      )
                      (else (cons (loop (car expr) tail?) (loop (cdr expr) tail?))) 
                    )
                    )))
       (loop exp #f))
  ))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; homeWork4;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; consts table ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define T_VOID  937610)
(define T_NIL   722689)
(define T_BOOL  741553)
(define T_CHAR  181048)
(define T_INTEGER   945311)
(define T_STRING  799345)
(define T_SYMBOL  368031)
(define T_PAIR  885397)
(define T_VECTOR  335728)
(define T_CLOSURE   276405)


(define const_table '())
(define address 10)


(define initConstTable
  (lambda ()
    (set! const_table 
      `(,@const_table 
        (,address ,(void) ,T_VOID)
      ))
      (set! address (+ address 1))
      (set! const_table 
      `(,@const_table 
        (,address () ,T_NIL)
      ))
      (set! address (+ address 1))
      (set! const_table 
      `(,@const_table 
        (,address ,#f ,T_BOOL)
      ))
      (set! address (+ address 1))
      (set! const_table 
      `(,@const_table 
        (,address ,#t ,T_BOOL)
      ))
      (set! address (+ address 1))
    )
  )

(define getConstAddress
  (lambda (const)
    (letrec ((loop 
            (lambda (const_table)
              (cond 
                ((null? const_table) #f)
                ((equal? (cadar const_table) const) (caar const_table))
                (else (loop (cdr const_table)))
              )
            )
    ))
    (loop const_table)
    )
  )
)

(define addToConstTable
  (lambda (const)
    (let ((cVar (cadr const)))
    (cond
      ((char? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_CHAR ,(char->integer cVar)))))
          (set! address (+ address 2)))
      ((number? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_INTEGER ,cVar))))
          (set! address (+ address 2)))
      ((string? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_STRING ,(string-length cVar) ,@(map char->integer (string->list cVar))))))
          (set! address (+ address 2 (string-length cVar))))
      ((symbol? cVar)
          (addToConstTable `(const ,(symbol->string cVar)))
          (set! const_table `(,@const_table (,address ,cVar (,T_SYMBOL ,(getConstAddress (symbol->string cVar))))))
          (set! address (+ address 2)))
      ((pair? cVar)
          (addToConstTable `(const ,(car cVar)))
          (addToConstTable `(const ,(cdr cVar))) 
          (set! const_table `(,@const_table (,address ,cVar (,T_PAIR ,(getConstAddress (car cVar)) ,(getConstAddress (cdr cVar))))))
          (set! address (+ address 3)))
      ((vector? cVar)
          (map (lambda (c) (addToConstTable `(const ,c))) (vector->list cVar))
          (set! const_table `(,@const_table (,address ,cVar (,T_VECTOR ,(length (vector->list cVar)) ,@(map getConstAddress (vector->list cVar))))))
          (set! address (+ address 2 (length (vector->list cVar)))))

  )))
)

;(initConstTable)
;(addToConstTable `(const ,(vector 1 'a)))
;(display const_table)
;(getConstAddress (vector 1 'a))


(define file->string
  (lambda (in-file)
    (let ((in-port (open-input-file in-file)))
          (letrec ((run
            (lambda ()
              (let ((ch (read-char in-port)))
                (if (eof-object? ch)
                    (begin
                      (close-input-port in-port)
                      '())
                    (cons ch (run)))))))
      (list->string
        (run))))))



(define string->schemeList 
  (lambda (str)
    (letrec ((str-maker 
                (lambda (sexprLst stringExp)
                  (let* ((parsedExp (test-string <sexpr> stringExp))
                          (exp (cadar parsedExp))
                          (restStr (cadadr parsedExp)))
                          (if (and (equal? (caar parsedExp) 'match) 
                                    (not (null? exp)))
                              (if (equal? (string-length restStr) 0)
                                `(,@sexprLst ,exp)
                                (str-maker `(,@sexprLst ,exp) (cadadr parsedExp)))
                               sexprLst)
                  )
                  )))
    (str-maker '() str))))
   
(define total-evaluation 
  (lambda (sexprLst)
    (let* 
      ((parsed (map parse sexprLst))
      (noNestedDefines (map eliminate-nested-defines parsed))
      (noLambdaNil (map remove-applic-lambda-nil noNestedDefines))
      (boxedExps (map box-set noLambdaNil))
      (lexedExps (map pe->lex-pe boxedExps))
      (noTailCalls (map annotate-tc lexedExps))
      )
      noTailCalls)))


(define create-table 
  (lambda (exp2 varType)
    (letrec (
      (table '())
      (loop 
      (lambda (exp)
        (cond 
          ((not (list? exp)) (void))
          ((null? exp) (void))
          ((equal? (car exp) varType) (set! table `(,@table ,exp)))
          (else (begin (loop (car exp)) (loop (cdr exp))))))))
    (begin (loop exp2) table)
    ))
    )


(define code-gen
  (lambda (parsedEvaledSexpr constant-table free-var-table)
    parsedEvaledSexpr
    ))



(define compile-scheme-file
  (lambda (scheme_source_file cisc_target_file)
    (let* ((stringFile (file->string scheme_source_file))
          (sexprLst (string->schemeList stringFile))
          (parsedEvaledSexpr (total-evaluation sexprLst))
          (constant-list (create-table parsedEvaledSexpr 'const)) ;need to call the table creator
         ; (free-var-table (create-table parsedEvaledSexpr 'fvar)) ;need to check if is correct - not sure this is even the global variable table...
          ;;add prolog and epilog to the code then write to file
          )
            (initConstTable)
            (code-gen parsedEvaledSexpr constant-table free-var-table);code-gen needs to be created

     ;(write ciscStr (open-output-file cisc_target_file)) ;writes to the output file
     ;(display ciscStr)
      )
    ))


(compile-scheme-file "test-files/test1.scm" "test-files/foo.c")