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
							(error writtenVars "not a valid code")))
					)
				(remwwHelper (deleteWrites writtenVars (cadar reversedCode)) (cdr reversedCode) (list (car reversedCode))))
			(error code "not a valid code")))
	)

(define deleteWrites
	(lambda (writtenVars readlist)
		(if (null? readlist)
			writtenVars
			(deleteWrites (remove (car readlist) writtenVars) (cdr readlist))
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


