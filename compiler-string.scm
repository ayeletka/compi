(load "/home/shugs/Documents/compiler/t1/pc.scm")

(define <digit-0-9>
  (range #\0 #\9))

(define <digit-1-9>
  (range #\1 #\9))




(define <Boolean>
	(new (*parser (char #\#))
		 (*parser (char #\T))
		 		 (*caten 2)

		 (*parser (char #\#))
		 (*parser (char #\t))
		 		 (*caten 2)
		 		 (*disj 2) 
		 		 (*pack-with 
		 		 	(lambda(a b)
		 		 		#t))

		 (*parser (char #\#))
		 (*parser (char #\F))
		 		 (*caten 2)

		 (*parser (char #\#))
		 (*parser (char #\f))
		 		 (*caten 2)
		 		 (*disj 2) 
		 		 (*pack-with 
		 		 	(lambda(a b)
		 		 		#f))
		 (*disj 2)

		 
	done))


 ;(test-string <Boolean> "#t")
 ;(test-string <Boolean> "#F")

;;;;;;;;;;;;;;;;;;String;;;;;;;;;;;;;;;

(define <StringVisibleChar>
    (new
        (*parser (range #\! #\~))
        (*pack
            (lambda (a) a))
        done))

;(test-string <StringVisibleChar> "t")        

(define ^<meta-char>
    (lambda (str ch)
        (new (*parser (word str))
            (*pack (lambda (_) ch))
            done)))
        

(define <StringMetaChar>
    (new
        (*parser (^<meta-char> "\\\\" #\\))
        (*parser (^<meta-char> "\\\"" #\"))
        (*parser (^<meta-char> "\\n" #\n))
        (*parser (^<meta-char> "\\t" #\t))
        (*parser (^<meta-char> "\\f" #\f))
        (*parser (^<meta-char> "\\r" #\r))
        (*disj 6)
        done))

;(test-string <StringMetaChar> "\\n")

(define <HexChar>
    (new 
        (*parser <StringVisibleChar>)
        done))

(define <StringHexChar>
    (new
        (*parser (^<meta-char> "\\x" #\x))
        (*parser <HexChar>) *star
        (*parser (char #\;))
        (*caten 3)
        done))

(define <StringChar>
    (new
        (*parser <StringMetaChar>)
        ;(*parser <StringHexChar>)
        (*parser <StringVisibleChar>)
        
        (*parser (char #\"))
        (*parser (char #\\))
        (*disj 2)
        
        *diff
        (*disj 2)
        ;(*disj 3)
        
        done))

;(test-string <StringChar> "\"\"")



(define <String>
	(new 
            (*parser (char #\"))
            (*parser <StringChar>) *star
            (*parser (char #\"))
            (*caten 3)
            (*pack-with
                (lambda (open-delim chars close-delim)
                    (list->string chars)))
            done))
            
(test-string <String> "\"marryabc;\"")
