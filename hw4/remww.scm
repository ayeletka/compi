(define remww 
	(lambda (code) 
		(if (list? code)
			(let*
				(
					(reversedCode (reverse code))
					(writtenVars 

						(if 
							(and (list? (car reversedCode)) (list? (caddar reversedCode)))
							(caddar reversedCode)
							(error "not a valid code")))
					)
				(remwwHelper writtenVars (cdr reversedCode) (car reversedCode)))
			(error "not a valid code")))
	)

(define deleteWrites
	(lambda (writtenVars writeList)
		(if (null? writeList)
			writtenVars
			(deleteWrites (remove (car writeList) writtenVars) (cdr writeList))
			)
		)
	)

(define remwwHelper 
	(lambda (writtenVars oldCode newCode)
		(if (null? oldCode) newCode
			(let* (
				(codeLine (car oldCode))		
				(writeList (caddr codeLine))
				(readlist (cadr codeLine))
				)
			(cond 
				((null? readlist) (remwwHelper writtenVars (cdr oldCode) newCode))
				((null? writeList) (remwwHelper writtenVars (cdr oldCode) newCode))
				((andmap (lambda (var) (member var writtenVars)) writeList)
					(remwwHelper writtenVars (cdr oldCode) newCode))
				(else (remwwHelper (deleteWrites `(,@writeList ,@writtenVars) readlist)
						(cdr oldCode)
						`(,(car oldCode) ,@newCode))))
				))
		))

 (remww '((g46494 (6 1) (6))
(g46495 (3 6 0) (0 4))
(g46496 (1) (3))
(g46497 (5 0 6) (4 2))
(g46498 (7 1 3) ())
(g46499 (7) ())
(g46500 (0 1) ())
(g46501 (4 7) (7))
(g46502 (5 7 0) ())
(g46503 (5 2 0) (6 2))
(g46504 (6 4 5) (0))
(g46505 (1 2) (1))
(g46506 (6 2 7 5) (7))
(g46507 (1) ())
(g46508 (1) ())
(g46509 (0 3 2) (5 0))
(g46510 (3 6) (4))
))