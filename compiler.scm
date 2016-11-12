(load "pc.scm")
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


 (test-string <Boolean> "#t")
  (test-string <Boolean> "#F")
