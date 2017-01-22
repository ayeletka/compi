;; PAATTERN MATCHER ;;;;;;;

;;; pattern-matcher.scm
;;; The pattern-matching package
;;;
;;; Programmer: Mayer Goldberg, 2014

(define match
  (letrec ((match
	    (lambda (pat e ret-vals ret-fail)
	      (cond ((and (pair? pat) (pair? e))
		     (match (car pat) (car e)
			    (lambda (vals-car)
			      (match (cdr pat) (cdr e)
				     (lambda (vals-cdr)
				       (ret-vals
					(append vals-car vals-cdr)))
				     ret-fail))
			    ret-fail))
		    ((and (vector? pat) (vector? e)
			  (= (vector-length pat) (vector-length e))
			  (match (vector->list pat) (vector->list e)
				 ret-vals ret-fail)))
		    ((procedure? pat)
		     (let ((v (pat e)))
		       (if v (ret-vals v) (ret-fail))))
		    ((equal? pat e) (ret-vals '()))
		    (else (ret-fail))))))
    (lambda (pat e ret-with ret-fail)
      (match pat e
	     (lambda (vals) (apply ret-with vals))
	     ret-fail))))

(define ?
  (lambda (name . guards)
    (let ((guard?
	   (lambda (e)
	     (andmap 
	      (lambda (g?) (g? e))
	      guards))))
      (lambda (value)
	(if (guard? value)
	    (list value)
	    #f)))))

(define _ (? 'dont-care))

;;; composing patterns

(define pattern-rule
  (lambda (pat handler)
    (lambda (e failure)
      (match pat e handler failure))))

(define compose-patterns
  (letrec ((match-nothing
	    (lambda (e failure)
	      (failure)))
	   (loop
	    (lambda (s)
	      (if (null? s)
		  match-nothing
		  (let ((match-rest
			 (loop (cdr s)))
			(match-first (car s)))
		    (lambda (e failure)
		      (match-first e
		       (lambda ()
			 (match-rest e failure)))))))))
    (lambda patterns
      (loop patterns))))




;;; PAATTERN MATCHER ;;;;;;;

; **** QQ from assignment page .... ****
(define expand-qq
  (lambda (e)
    (cond ((unquote? e) (cadr e))
	  ((unquote-splicing? e)
	   (error 'expand-qq "unquote-splicing here makes no sense!"))
	  ((pair? e)
	   (let ((a (car e))
		 (b (cdr e)))
	     (cond ((unquote-splicing? a) `(append ,(cadr a) ,(expand-qq b)))
		   ((unquote-splicing? b) `(cons ,(expand-qq a) ,(cadr b)))
		   (else `(cons ,(expand-qq a) ,(expand-qq b))))))
	  ((vector? e) `(list->vector ,(expand-qq (vector->list e))))
	  ((or (null? e) (symbol? e)) `',e)
	  (else e))))

(define ^quote?
  (lambda (tag)
    (lambda (e)
      (and (pair? e)
	   (eq? (car e) tag)
	   (pair? (cdr e))
	   (null? (cddr e))))))

(define unquote? (^quote? 'unquote))
(define unquote-splicing? (^quote? 'unquote-splicing))

(define quasiquote?
	(lambda (q) 
		(and (pair? q) (eq? 'quasiquote (car q)))
	)
)

; *** Till here take from assignment page .... ***

; **** LETREC from assignment page .... ****

(define with (lambda (s f) (apply f s)))

(define Ym
  (lambda fs
    (let ((ms (map
		(lambda (fi)
		  (lambda ms
		    (apply fi (map (lambda (mi)
				     (lambda args
				       (apply (apply mi ms) args))) ms))))
		fs)))
      (apply (car ms) ms))))

;(print-gensym #f)

(define expand-letrec
  (lambda (letrec-expr)
    (with letrec-expr
      (lambda (_letrec ribs . exprs)

	(let* ((fs (map car ribs))
	       (lambda-exprs (map cdr ribs))
	       (nu (gensym))
	       (nu+fs `(,nu ,@fs))
	       (body-f `(lambda ,nu+fs ,@exprs))
	       (hofs
		(map (lambda (lambda-expr) `(lambda ,nu+fs ,@lambda-expr))
		  lambda-exprs)))
	  `(Ym ,body-f ,@hofs))))))

; **************************


;; ***** Reserved word given from assignment page ****
(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set!))
;; ***************************************************

(define res-word?
	(lambda (word)
		(member word *reserved-words*)
	)
)

(define notEmptylist?
	(lambda (chList)
		(if (eq? chList '())
			#f
			#t
		)
	)
)

(define nonEmptyPairs?
	(lambda (pair)
		(cond 
			((null? pair) #f)
			((not (pair? pair)) #f)
			((null? (cdr pair)) #f)
			((not (null? (cddr pair))) #f)
			(else (and (not (null? (car pair))) (var? (car pair)) (not (null? (cdr pair)))))
		)
	)
)

(define listOfPairsOnly?
	(lambda (chList)
		(if (null? chList)
			#t 
			(andmap nonEmptyPairs? chList)
		)
	)
)

(define beginify
  	(lambda (e)
    	(cond 	((null? e) (void))
	  			((null? (cdr e)) (car e))
	  			(else `(begin ,@e))
	    )
  )
)

(define void?
	(lambda(var)
		(eq? var (void))
	)
)

(define var?
	(lambda(var)
		(and (symbol? var) (not (res-word? var)))
	)
)

(define simple-const?
	(lambda (c)
		( or (boolean? c) (char? c) (number? c) (string? c) (void? c) )
	)
)

(define create_three_state_if
	(lambda (test do_if_true do_if_false)
		`(if3 ,(parse test) ,(parse do_if_true) ,(parse do_if_false))
	)
)

(define create_two_state_if
	(lambda (test do_if_true)
		`(if3 ,(parse test) ,(parse do_if_true) ,(parse (void)))
	)
)

(define get-dot
	(lambda (iList state)
		(if (eq? state 'after)
			; **** DIT ****
			(if (pair? iList)
				(get-dot (cdr iList) state)
				iList
			)
			; *** DIF ****
			(if (pair? iList)
				(cons (car iList) (get-dot (cdr iList) state))
				'()
			)
		)
	)
)

(define app?
	(lambda (app)
		(if (list? app)
			(if (res-word? (car app)) 
				#f 
				#t
			)
			#f
		)
	)
)

(define and?
	(lambda (andList)
		(if (list? andList)
			(if (eq? (car andList) ('and)) 
				#f 
				#t
			)
			#f
		)
	)
)

(define and->if
	(lambda (andList)
		(cond 
			((null? andList) #t)
			((null? (cdr andList)) (car andList))
			(else `(if ,(car andList) ,(and->if (cdr andList)) #f))
		)
	)
)

(define expand-or
	(lambda (orList)
		(cond
			((null? orList) (parse #f))
			((= 1 (length orList)) (parse (car orList)))
			(else `(or ,(map parse orList)))
		)
	)
)

(define cond->if 
	(lambda (cList)
		(let* (
				(firstCond   	(car cList))
				(firstCondTest 	(car firstCond))
				(firstCondDIT 	(if (null? (cdr firstCond)) firstCondTest (beginify (cdr firstCond))))
				(restOfConds 	(cdr cList))
			 )
			(if (notEmptylist? restOfConds)
				; *** case it's not the last cond ... 
				`(if ,firstCondTest ,firstCondDIT ,(cond->if restOfConds))
				; *** it's the last cond so it can be else ... 
				(if (eq? 'else firstCondTest) 
					firstCondDIT
					`(if ,firstCondTest ,firstCondDIT) 
				)
			)
		)
	)
)

(define expand-let
	(lambda (vars body)
		(let ( 
				(keys (map car vars))
			  	(values (map cadr vars))
			 )
			`((lambda ,keys ,@body) ,@values)
		)
	)
)

(define parse
  	(let ((run
	 	(compose-patterns
	  		
	 		; ** VAR Rule ... ****
	 		(pattern-rule
	 			(? 'c var?)
	 			(lambda (c) 
	 				`(var ,c)))

			;; ** CONST Rules ... *** 
	  		(pattern-rule
	   			(? 'c simple-const?)
	   			(lambda (c) `(const ,c)))
	  
	  		(pattern-rule
	   			`(quote ,(? 'c))
	   			 (lambda (c) `(const ,c)))

	  		; *** QUASIQUOTED EXPRESSIONS Rules .... *****
	 		(pattern-rule
	 			`(quasiquote ,(? 'q) . ,(? 'a null?))
	 			(lambda (q a) 
	 				(parse (expand-qq q))
	 			)
	 		)

	  		; *** IF Rules .... ****
	  		(pattern-rule
	  			`(if ,(? 'test) ,(? 'do_if_true) ,(? 'do_if_false))
	  			 create_three_state_if
	  		)

	  		(pattern-rule
	  			`(if ,(? 'test) ,(? 'do_if_true))
	  			 create_two_state_if
	  		)

	  		; ****** SEQUENCES Rules ... ******
	  		(pattern-rule
	  			`(begin . ,(? 'exprs) )
	  			 (lambda (exprs)
	  			 	(if (null? exprs) 
	  			 		(parse (void))
	  			 		`(seq ,(map parse exprs))
	  			 	)
	  			 ) 
	  		)

	  		;*** LAMBDA SIMPLE Rule .... *****
	  		(pattern-rule
	  			`(lambda ,(? 'args list?) ,(? 'body) . ,(? 'bodyRest list?))
	  			 (lambda (args body bodyRest)
	  			 	`(lambda-simple ,args ,(parse (beginify (cons body bodyRest))))
	  			 )
	  		)
			
			;*** LAMBDA OPT Rule .... *****
	  		(pattern-rule
	  			`(lambda ,(? 'args pair?) ,(? 'body) . ,(? 'bodyRest list?))
	  			 (lambda (args body bodyRest)
	  			 	`(lambda-opt ,(get-dot args 'before) ,(get-dot args 'after) ,(parse (beginify (cons body bodyRest))))
	  			 )
	  		)

			;*** LAMBDA VARIADIC Rule .... *****
	  		(pattern-rule
	  			`(lambda ,(? 'args var?) ,(? 'body) . ,(? 'bodyRest list?))
	  			 (lambda (args body bodyRest)
	  			 	`(lambda-variadic ,args ,(parse (beginify (cons body bodyRest))))
	  			 )
	  		)

			;*** REGULAR DEFINE Rule .... *****
	  		(pattern-rule
	  			`(define ,(? 'key var?) ,(? 'value))
	  			 (lambda (key value)
	  			 	`(define ,(parse key) ,(parse value))
	  			 )
	  		)

			;*** MIT DEFINE Rule .... *****
	  		(pattern-rule
	  			`(define ,(? 'keyPlusArgs pair?) ,(? 'body) . ,(? 'bodyRest list?))
	  			 (lambda (keyPlusArgs body bodyRest)
	  			 	(let ( (lambdaBody (cons body bodyRest)) )
	  			 		(parse `(define ,(car keyPlusArgs) (lambda ,(cdr keyPlusArgs) ,@lambdaBody)))
	  			 	)
	  			 )
	  		)

	  		;*** APPLICATION Rule .... *****
	  		(pattern-rule
	  			`,(? 'app app?)
	  			 (lambda (app)
	  			 	`(applic ,(parse (car app)) ,(map parse (cdr app)))
	  			 )
	  		)

	  		;**** AND Rules .... ***
	  		(pattern-rule
	   			`(and . ,(? 'andList))
	   			(lambda (andList)
	     			(parse (and->if andList))
	     		)
	     	)

	     	;**** OR Rules .... ***
	  		(pattern-rule
	   			`(or . ,(? 'orList))
	   			(lambda (orList)
	     			(expand-or orList)
	     		)
	     	)

	     	; ***** COND Rules ..... ***
			(pattern-rule
	   			`(cond ,(? 'firstCondList notEmptylist?) . ,(? 'restCondList list?))
	   			 (lambda (firstCondList restCondList)
	     			(parse (cond->if (cons firstCondList restCondList)))
	     		)
	     	)

	     	; ***** LET Rules ..... ***
			(pattern-rule
	   			`(let ,(? 'vars listOfPairsOnly?) ,(? 'body) . ,(? 'restOfBody))
	   			 (lambda (vars body restOfBody)
	     			(parse (expand-let vars (cons body restOfBody)))
	     		)
	     	)


	  		; **** LET* Rules .... ***
	  		(pattern-rule
	   			`(let* () ,(? 'expr) . ,(? 'exprs list?))
	   			(lambda (expr exprs)
	     			(parse (beginify (cons expr exprs)))
	     		)
	     	)

	     	(pattern-rule
	   			`(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
	   			(lambda (var val rest exprs)
	     			(parse `(let ((,var ,val)) (let* ,rest . ,exprs)))
	   			)
	     	)

	     	; **** LETREC Rules .... ***
	     	(pattern-rule
	   			`(letrec ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
	   			(lambda (var val rest exprs)
	   				(parse (expand-letrec `(letrec ((,var ,val) . ,rest) .,exprs )))
	   			)
	     	)

	     	(pattern-rule
	   			`(letrec () ,(? 'expr) . ,(? 'exprs list?))
	   			(lambda (expr exprs)
	     			(parse (beginify (cons expr exprs)))
	     		)
	     	)

	 
	  ;; add more rules here
	    )))
    (lambda (e)
      (run e
	   (lambda ()
	     (error 'parse
		    (format "I can't recognize this: ~s" e)))))))
		    
		    
;;;;;;;;; assignment 3 -  Annotating variables with their lexical address ;;;;;;

;; Matrix functions .... ;;
;; The form : ( (pvars ..) (bvars 0...) .... (bvars n))

(define is-free-var? 
  (lambda (var varsMatrix)
    (if 
        (list? (member var (apply append varsMatrix)))
        #f
        #t
    )))

(define find-major
  (lambda (var varsMatrix)
      (find-major-help var varsMatrix 0) 
  ))

(define find-major-help
  (lambda (var varsMatrix major)
      (let (
              (firstList (car varsMatrix))
            )
        (if 
            (list? (member var firstList)) 
            major
            (find-major-help var (cdr varsMatrix) (+ major 1))
        ))))

(define find-minor
  (lambda (var varsMatrix)
    (let ((major (find-major var varsMatrix)))
      (find-minor-help var (list-ref varsMatrix major) 0)
    )))

(define find-minor-help
  (lambda (var minorList minor)
    (if (eq? var (car minorList))
         minor
         (find-minor-help var (cdr minorList) (+ minor 1))
    )))

(define tag-pe? (lambda (check real) (eq? check real)))

(define pe->lex-pe (lambda (pe) (pe->lex-pe-help pe '())))

(define pe->lex-pe-define 
  (lambda (pe varsMatrix)
    (let (
          (name (cadadr pe))
          (body (caddr pe))
          )
      `(define (fvar ,name) ,(pe->lex-pe-help body varsMatrix)))
    )) 

(define pe->lex-pe-var 
  (lambda (pe varsMatrix)
    (let (
          (varName (cadr pe))
          )
     (cond 
       ((is-free-var? varName varsMatrix) `(fvar ,varName))
       (else (let (
                   (major (find-major varName varsMatrix))
                   (minor (find-minor varName varsMatrix)))
              (if (= major 0)
                  `(pvar ,varName ,minor)
                  `(bvar ,varName ,(- major 1) ,minor)
              )
       ))
     ) 
  )))

(define pe->lex-pe-if 
  (lambda (pe varsMatrix)
    (let (
          (test (cadr pe))
          (dit (caddr pe))
          (dif (cadddr pe))
          )
      `(if3 ,(pe->lex-pe-help test varsMatrix) ,(pe->lex-pe-help dit varsMatrix) ,(pe->lex-pe-help dif varsMatrix))
  )))

(define pe->lex-pe-applic 
  (lambda (pe varsMatrix)
    (let (
          (app     (cadr pe))
          (appVars (caddr pe))
          )
      `(applic ,(pe->lex-pe-help app varsMatrix) ,(map (lambda (x) (pe->lex-pe-help x varsMatrix)) appVars)) 

  )))

(define pe->lex-pe-tc-applic 
  (lambda (pe varsMatrix)
    (let (
          (app     (cadr pe))
          (appVars (caddr pe))
          )
      `(tc-applic ,(pe->lex-pe-help app varsMatrix) ,(map (lambda (x) (pe->lex-pe-help x varsMatrix)) appVars)) 

  )))
  
(define pe->lex-pe-or 
  (lambda (pe varsMatrix)
    (let (
          (orVars (cadr pe))
          )
      `(or ,(map (lambda (x) (pe->lex-pe-help x varsMatrix)) orVars)) 
  )))

(define pe->lex-pe-seq 
  (lambda (pe varsMatrix)
    (let (
          (seqVars (cadr pe))
          )
      `(seq ,(map (lambda (x) (pe->lex-pe-help x varsMatrix)) seqVars)) 
  )))

(define pe->lex-pe-lambda-simple 
  (lambda (pe varsMatrix)
    (let* (
          (params (cadr pe))
          (body   (caddr pe))
          (newMatrix (cons params varsMatrix))
          )
      `(lambda-simple ,params ,(pe->lex-pe-help body newMatrix)) 
  )))

(define pe->lex-pe-lambda-opt 
  (lambda (pe varsMatrix)
    (let* (
          (params (cadr pe))
          (opt    (caddr pe))
          (body   (cadddr pe))
          (newMatrix (cons (append params (list opt)) varsMatrix))
          )
      `(lambda-opt ,params ,opt ,(pe->lex-pe-help body newMatrix)) 
  )))

(define pe->lex-pe-lambda-variadic 
  (lambda (pe varsMatrix)
    (let* (
          (params (cadr pe))
          (body   (caddr pe))
          (newMatrix (cons (list params) varsMatrix))
          )
      `(lambda-variadic ,params ,(pe->lex-pe-help body newMatrix)) 
  )))

(define pe->lex-pe-help
  (lambda (pe varsMatrix)
    (let ((tag (if (null? pe) '() (car pe))))
    (cond
      ((null? tag) tag)
      ((tag-pe? 'const tag) pe)
      ((tag-pe? 'define tag) (pe->lex-pe-define pe varsMatrix))
      ((tag-pe? 'var tag) (pe->lex-pe-var pe varsMatrix))
      ((tag-pe? 'if3 tag) (pe->lex-pe-if pe varsMatrix))
      ((tag-pe? 'applic tag) (pe->lex-pe-applic pe varsMatrix))
      ((tag-pe? 'tc-applic tag) (pe->lex-pe-tc-applic pe varsMatrix))
      ((tag-pe? 'or tag) (pe->lex-pe-or pe varsMatrix))
      ((tag-pe? 'seq tag) (pe->lex-pe-seq pe varsMatrix))
      ((tag-pe? 'lambda-simple tag) (pe->lex-pe-lambda-simple pe varsMatrix))
      ((tag-pe? 'lambda-opt tag) (pe->lex-pe-lambda-opt pe varsMatrix))
      ((tag-pe? 'lambda-variadic tag) (pe->lex-pe-lambda-variadic pe varsMatrix))
      (else (error 'pe->lex-pe (format "Cant recognized parsed expression.")))
    )
)))



;;; Assignment 3 part 4. Annotating tail calls.

(define annotate-tc 
  (lambda (exp) 
    (annotate-tc-help exp #f)
  ))

(define annotate-tc-if
  (lambda (pe in-tp?)
    (let (
           (test (cadr pe))
           (dit  (caddr pe))
           (dif  (cadddr pe))
         )
      `(if3 ,(annotate-tc-help test #f) ,(annotate-tc-help dit in-tp?) ,(annotate-tc-help dif in-tp?))
  )))

(define false-expect-last
  (lambda (exp in-tp?)
   (cond
    ((null? exp) '())
    ((null? (cdr exp)) (list (annotate-tc-help (car exp) in-tp?)))
    (else 
      (let (
            (first (annotate-tc-help (car exp) #f))
            (rest  (false-expect-last (cdr exp) in-tp?))
            )
       (cons first rest)
    ))
)))

(define annotate-tc-or
  (lambda (pe in-tp?)
      `(or ,(false-expect-last (cadr pe) in-tp?))
  ))

(define annotate-tc-seq
  (lambda (pe in-tp?)
      `(seq ,(false-expect-last (cadr pe) in-tp?))
  ))

(define annotate-tc-define
  (lambda (pe in-tp?)
    (let (
          (var  (cadr pe))
          (exp  (caddr pe))
         )
      `(define ,var ,(annotate-tc-help exp #f))
  )))

(define annotate-tc-applic
  (lambda (pe in-tp?)
    (let (
          (app      (cadr pe))
          (appVars  (caddr pe))
          (tag      (if (eq? in-tp? #t) 'tc-applic 'applic))
         )
      `(,tag ,(annotate-tc-help app #f) ,(map (lambda (exp) (annotate-tc-help exp #f)) appVars))
  )))

(define annotate-tc-lambda-simple 
  (lambda (pe in-tp?)
    (let* (
          (params (cadr pe))
          (body   (caddr pe))
          )
      `(lambda-simple ,params ,(annotate-tc-help body #t))
  )))

(define annotate-tc-lambda-opt 
  (lambda (pe in-tp?)
    (let* (
          (params (cadr pe))
          (opt    (caddr pe))
          (body   (cadddr pe))
          )
      `(lambda-opt ,params ,opt ,(annotate-tc-help body #t))
  )))

(define annotate-tc-lambda-variadic 
  (lambda (pe in-tp?)
    (let* (
          (params (cadr pe))
          (body   (caddr pe))
          )
      `(lambda-variadic ,params ,(annotate-tc-help body #t))
  )))

(define annotate-tc-help 
  (lambda (pe in-tp?) 
    (let ((tag (if (null? pe) '() (car pe))))
      (cond
       ((null? tag) tag)
       ((tag-pe? 'const tag) pe)
       ((tag-pe? 'define tag) (annotate-tc-define pe in-tp?))
       ((tag-pe? 'var tag) pe)
	   ((tag-pe? 'fvar tag) pe)
	   ((tag-pe? 'bvar tag) pe)
	   ((tag-pe? 'pvar tag) pe)
       ((tag-pe? 'if3 tag) (annotate-tc-if pe in-tp?))
       ((tag-pe? 'applic tag) (annotate-tc-applic pe in-tp?))
       ((tag-pe? 'or tag) (annotate-tc-or pe in-tp?))
       ((tag-pe? 'seq tag) (annotate-tc-seq pe in-tp?))
       ((tag-pe? 'lambda-simple tag) (annotate-tc-lambda-simple pe in-tp?))
       ((tag-pe? 'lambda-opt tag) (annotate-tc-lambda-opt pe in-tp?))
       ((tag-pe? 'lambda-variadic tag) (annotate-tc-lambda-variadic pe in-tp?))
       (else (error 'annotate-tc-help (format "Cant recognized parsed expression. : ~a" pe)))
       )
     )
  ))



;; PROJECT !!!!!!!

;; SCANNER READER PART ;;;

(define getListOfSexprs
  (lambda (port accList)
   (let ((next (read port)))
     (if (eof-object? next)
       (begin (close-input-port port) accList )
       (getListOfSexprs port (append accList (list next)))  
     ))))

(define readSexprs
  (lambda (inputFileName)
	    (let ((port (open-input-file inputFileName)))
      (getListOfSexprs port '()) 	   
	     )))

(define readSexprsFromString
  (lambda (inputString)
	    (let ((port (open-input-string inputString)))
      (getListOfSexprs port '()) 	   
 )))


(define writeStringToFile
	(lambda (outputFileName strToWrite)
		(let ((port (open-output-file outputFileName)))
			(begin (display strToWrite port) (close-output-port port))
)))


;;;;;;;;;;;;;;;;; CODE GEN ;;;;;;

(define ^^label
	(lambda (name)
		(let ((n 0))
			(lambda ()
				(set! n (+ n 1))
				(string-append name
					(number->string n)
)))))

(define ^label-if3else 				(^^label "L_if3_else"))
(define ^label-if3exit 				(^^label "L_if3_exit"))
(define ^label-or-exit 				(^^label "L_or_exit"))
(define ^label-closure-start 		(^^label "L_closure_start"))
(define ^label-closure-body	 		(^^label "L_closure_body"))
(define ^label-closure-end   		(^^label "L_closure_end"))
(define ^label-params-loop   		(^^label "L_params_loop"))
(define ^label-env-loop      		(^^label "L_env_loop"))
(define ^label-params-loop-exit   	(^^label "L_params_loop_exit"))
(define ^label-env-loop-exit   		(^^label "L_env_loop_exit"))
(define ^label-tc-copy-loop			(^^label "L_tc_copy"))
(define ^label-tc-copy-loop-exit  	(^^label "L_tc_copy_exit"))
(define ^label-opt-copy-loop		(^^label "L_opt_copy"))
(define ^label-opt-copy-loop-exit  	(^^label "L_opt_copy_exit"))
(define ^label-opt-copy-loop2		(^^label "L_opt_2copy"))
(define ^label-opt-copy-loop-exit2  (^^label "L_opt_2copy_exit"))
(define ^label-var-copy-loop		(^^label "L_var_copy"))
(define ^label-var-copy-loop-exit  	(^^label "L_var_copy_exit"))
(define ^label-var-copy-loop2		(^^label "L_var_2copy"))
(define ^label-var-copy-loop-exit2  (^^label "L_var_2copy_exit"))
(define ^label-var-copy-loop3		(^^label "L_var_3copy"))
(define ^label-var-copy-loop-exit3  (^^label "L_var_3copy_exit"))
(define ^label-sim-copy-loop		(^^label "L_sim_copy"))
(define ^label-sim-copy-loop-exit  	(^^label "L_sim_copy_exit"))



(define nl (list->string (list #\newline)))

(define codegen-if3
	(lambda (sexp envL paramL)
		(let* (
			(test 			(cadr sexp)) 	
			(do-if-true 	(caddr sexp)) 	
			(do-if-false	(cadddr sexp)) 	
			(code-test (code-gen test envL paramL))
			(code-dit (code-gen do-if-true envL paramL))
			(code-dif (code-gen do-if-false envL paramL))
			(label-else (^label-if3else))
			(label-exit (^label-if3exit))
			)
				(string-append
					"/* I am in the if exp */" nl
					code-test nl ; when run, the result of the test will be in R0
					"CMP(R0, SOB_FALSE);" nl
					"JUMP_EQ(" label-else ");" nl
					code-dit nl
					"JUMP(" label-exit ");" nl
					label-else ":" nl
					code-dif nl
					label-exit ":" nl)
)))

(define codegen-or
	(lambda (e envL paramL)
		(let* 	(
					(oldList		(cadr e))
					(compList		(map (map-code-gen envL paramL) oldList))
					(exit_label		(^label-or-exit))
				)
				(letrec ((recFunc 
							(lambda (comp)
								( string-append
									(car comp) nl
									"CMP(R0, SOB_FALSE);" nl
									"JUMP_NE(" exit_label ");" nl
									(if 
										(null? (cdr comp))
										(string-append exit_label ":" nl)
										(recFunc (cdr comp))
									)
								))))
							
					(recFunc compList)
				))))
					
(define codegen-seq
	(lambda (e envL paramL)
		(let* 	(
					(oldList		(cadr e))
					(compList		(map (map-code-gen envL paramL) oldList))
				)
				(letrec ((recFunc 
							(lambda (comp)
								( string-append
									(car comp) nl
									(if 
										(null? (cdr comp))
										""
										(recFunc (cdr comp))
									)
								))))
							
					(recFunc compList)
				))))

(define malloc-call
	(lambda(num)
		(string-append
				"PUSH(IMM(" (number->string num) "));" nl		
				"CALL(MALLOC);" nl
				"DROP(IMM(1));"	nl
)))

(define code-gen-lambda
	(lambda (e envL paramsL)
		(let 	(
					(label-start 			(^label-closure-start))
			  		(label-body 			(^label-closure-body))
			  		(label-end 				(^label-closure-end))
			  		(label-params-loop 		(^label-params-loop))
			  		(label-params-loop-exit	(^label-params-loop-exit))
			  		(label-env-loop 		(^label-env-loop))
			  		(label-env-loop-exit	(^label-env-loop-exit))
				)

			(string-append 
				"/* Calling malloc with 3 for closure, env and body. */" nl
				(malloc-call 3)			;   3 for: T_CLOSURE, ENV, CLOSURE_CODE
				"/* R10 will hold the adress of the malloc */" nl
				"MOV(R10,R0);"	nl 		; 	R10 hols the main adress.
				"/* putting T_Closure at place 0 */" nl
				"MOV(INDD(R10,0), IMM(T_CLOSURE));" nl
				"/* call malloc with |env| + 1 */"		nl	
				(malloc-call (+ 1 envL))
				"/* R2 will hold the new env adress */" nl
				"MOV(R2,R0);"	nl 		; 	R2 hols the env address.
				"/* R3 get the old env adress */"
				"MOV(R3, FPARG(0));" nl 	; clone the env
				"/* cloning the env .. */" nl
				"/* R4 is i, R5 is j" nl
				"for(i=1,j=0; j<" (number->string envL) "; j++, i++)" nl
				"MOV(INDD(R2,IMM(i)), INDD(R3,IMM(j));" nl
				"*/" nl
				"MOV(R4, IMM(1));" nl
				"MOV(R5, IMM(0));" nl
				label-env-loop ":" nl
				"CMP(R5,IMM(" (number->string envL) "));" nl
				"JUMP_GE(" label-env-loop-exit ");" nl
				"MOV(INDD(R2,R4), INDD(R3,R5));" nl
				"INCR(R4);" nl
				"INCR(R5);" nl
				"JUMP(" label-env-loop ");" nl
				label-env-loop-exit ": " nl
				"/* Now cloning the parameters if nedded ... */" nl
				"/* calling malloc with params length ... */"	nl
				(malloc-call paramsL) nl
				"/* R3 hold the new parametes adress .. */" nl
				"MOV(R3, R0);" nl 
				"/*for loop for clone ... */" nl
				"/*" nl
				"for(i=0; i<" (number->string paramsL) "; i++) {" nl
				"MOV(INDD(R3,IMM(i)), FPARG(2 + i));" nl
				"} */" nl
				"/* R5 = 2*/" nl
				"MOV(INDD(R2,0), R3);" nl
				"MOV(R5, IMM(2));" nl
				"MOV(R6, IMM(0));" nl
				label-params-loop ":" nl
				"CMP(R5,IMM(" (number->string (+ 2 paramsL)) "));" nl
				"JUMP_GE(" label-params-loop-exit ");" nl
				"MOV(INDD(R3,R6), FPARG(R5));" nl
				"/* the new env R2[0] = new parameters */" nl
				"INCR(R5);" nl
				"INCR(R6);" nl
				"JUMP(" label-params-loop ");" nl
				label-params-loop-exit ": " nl
				"/* finish copy parameters */" nl
				"/* new struct at 1 = new env */" nl
				"MOV(INDD(R10,1),R2);" nl
				"/* appending body ...*/" nl
				"MOV(INDD(R10,IMM(2)), LABEL(" label-body "));" nl
				"MOV(R0,R10);" nl
				"JUMP(" label-end  ");" nl
				label-body ":" nl
				"PUSH(FP);" nl
				"MOV(FP,SP);" nl
				(cond 
					((eq? (car e) 'lambda-simple) (create-lambda-simple-body e envL paramsL))
					((eq? (car e) 'lambda-opt) (create-lambda-opt-body e envL paramsL))
					((eq? (car e) 'lambda-variadic) (create-lambda-variadic-body e envL paramsL))
					(else "It's can't happen ... ")
				)
				nl
				"POP(FP);" nl
				"RETURN;" nl
				"/* LABEL END LAMBDA */" nl
				label-end ":" nl

			)
		)


)) 	

(define create-lambda-simple-body
	(lambda (e envL paramsL)
		(string-append
			"/* In lambda body ... */" nl
			"MOV(R1, FPARG(1));" nl
			"CMP(R1, IMM(" (number->string (length (cadr e))) "));" nl
			"JUMP_NE(ERROR);" nl
			"/* Call code gen ... */" nl
			(code-gen  (caddr e) (+ 1 envL) (length (cadr e)))
			"/* retrun from code gen .. */" nl
)))




(define create-lambda-opt-body
	(lambda (e envL paramsL)
		(let* (
				(argLength 			(length (cadr e)))
				(body 				(cadddr e))
				(label-copy 		(^label-opt-copy-loop))
				(label-copy-exit 	(^label-opt-copy-loop-exit))
				(label-copy2 		(^label-opt-copy-loop2))
				(label-copy-exit2 	(^label-opt-copy-loop-exit2))
			  )
		(string-append
			"/* In lambda opt body ... */" nl

			"POP(R1);" nl ; old fp
			"POP(R2);" nl ; ret addr
			"POP(R3);" nl ; env
			"POP(R4);" nl ; number of arg;

			(malloc-call argLength)

			"MOV(R5, R0);" nl ; R5 is the new malloc for args ... 
			"MOV(R6, IMM(0));" nl ;R6 is the running index

			label-copy ":" nl
			"CMP(R6, IMM(" (number->string argLength) "));" nl
			"JUMP_EQ(" label-copy-exit ");" nl
			"POP(R7);" nl
			"MOV(INDD(R5,R6), R7);" nl
			"ADD(R6, IMM(1));" nl
			"JUMP(" label-copy ");" nl
			label-copy-exit ":" nl

			"MOV(R7, R4);" nl
			"SUB(R7, IMM(" (number->string argLength) "));" nl ; R7 is the number of optional args ...

			"PUSH(R7);" nl
			"PUSH(IMM(0));" nl
			"CALL(LIST);" nl
			"DROP(IMM(1));" nl
			"POP(R7);" nl
			"DROP(R7);" nl ; remove all the optional args from list ... 
			"MOV(R8, R0);" nl ; R8 is the new optional arg list ...

			; starting insert to stack ... 
			"PUSH(R8);" nl

			"MOV(R6, IMM(" (number->string (- argLength 1)) "));" nl ;R6 is the running index

			label-copy2 ":" nl
			"CMP(R6, IMM(-1));" nl
			"JUMP_EQ(" label-copy-exit2 ");" nl
			"PUSH(INDD(R5,R6));" nl
			"SUB(R6, IMM(1));" nl
			"JUMP(" label-copy2 ");" nl
			label-copy-exit2 ":" nl

			"PUSH(IMM(" (number->string (+ 1 argLength))  "));" nl
			"PUSH(R3);" nl
			"PUSH(R2);" nl
			"PUSH(R1);" nl
			"MOV(FP, SP);" nl

			(code-gen  body (+ 1 envL)  (+ 1 argLength))			
))))


(define create-lambda-variadic-body
	(lambda (e envL paramsL)
		(let* (
				(body 				(caddr e))
				(label-copy 		(^label-var-copy-loop))
				(label-copy-exit 	(^label-var-copy-loop-exit))
				(label-copy2 		(^label-var-copy-loop2))
				(label-copy-exit2 	(^label-var-copy-loop-exit2))
				(label-copy3 		(^label-var-copy-loop3))
				(label-copy-exit3 	(^label-var-copy-loop-exit3))
			  )
		(string-append
			"/* In lambda var body ... */" nl
			
			"POP(R1);" nl ; old fp
			"POP(R2);" nl ; ret addr
			"POP(R3);" nl ; env
			"POP(R4);" nl ; number of arg;

			
			"PUSH(R4);" nl
			"PUSH(IMM(0));" nl
			"CALL(LIST);" nl
			"DROP(IMM(1));" nl
			"POP(R4);" nl
			"DROP(R4);" nl

			"PUSH(R0);" nl
			"PUSH(1);" nl
			"PUSH(R3);" nl
			"PUSH(R2);" nl
			"PUSH(R1);" nl
			"MOV(FP, SP);" nl

			(code-gen  body (+ 1 envL)  1)
))))


;;;;;;; APPLIC ;;;;;;;;;;;


(define push-applic-params 
	(lambda (reversedParamsList length)
		(if 
			(= length 0)
			""
			(string-append
				(car reversedParamsList) nl
				"PUSH(R0);" nl
				(push-applic-params (cdr reversedParamsList) (- length 1))
			))))


(define codegen-applic 
	(lambda (exp envL paramsL)
			(let* 	( 	
						(func 				(cadr exp))
						(paramsList			(caddr exp))
						(compParams 		(map (map-code-gen envL paramsL) paramsList))
						(compFunction 		(code-gen func envL paramsL))
					)
					(string-append
						"/* push params reverse order. */" nl
						(push-applic-params (reverse compParams) (length paramsList))
						"/* push number of args. */" nl
						"PUSH(IMM(" (number->string (length paramsList)) "));" nl
						compFunction
						"CMP(INDD(R0,0), IMM(T_CLOSURE));" nl
						"JUMP_NE(ERROR);" nl
						"PUSH(INDD(R0,IMM(1)));" nl		; push the closure environment
						"CALLA(INDD(R0,IMM(2)));" nl			
						"/* move to R5 number of args .. to know how to drop from stack. */" nl
						"MOV(R5,STARG(IMM(0)));" nl			
						"/* add r5 env, numOfArg */" nl
						"ADD(R5, IMM(2));" nl		
						"DROP(R5);"  nl				
				))))


(define codegen-tc-applic
	(lambda (exp envL paramsL)
			(let* 	( 	
						(func 				(cadr exp))
						(paramsList			(caddr exp))
						(compParams 		(map (map-code-gen envL paramsL) paramsList))
						(compFunction 		(code-gen func envL paramsL))
						(starg_off			(+ 1 (length paramsList))) ;; first object in the sp stack offset.
						(number_of_copy		(+ 3 (length paramsList))) ;ret env number of args
						(loop-label			(^label-tc-copy-loop))
						(loop-label-exit	(^label-tc-copy-loop-exit))
					)
					(string-append
						"/* In codegen-tc-applis */" nl
						
						"/* push params reverse order. */" nl
						(push-applic-params (reverse compParams) (length paramsList))
						
						"/* push number of args. */" nl
						"PUSH(IMM(" (number->string (length paramsList)) "));" nl
						
						"/* add function code ... */" nl
						compFunction
						"CMP(INDD(R0,0),IMM(T_CLOSURE));" nl
						"JUMP_NE(ERROR);" nl
						
						"/* push env ... */" nl
						"PUSH(INDD(R0,1));" nl				
						
						"/*  Push the return address from current frame */" nl
						"PUSH(FPARG(-1));" nl
						
						"/* R8 hold the old fp */" nl
						"MOV(R8,FPARG(-2));" nl
						"/* R12 hold the old num of arg */" nl
						"MOV(R12,FPARG(1));" nl 
						"/* R13 hold the new num of arg */" nl
						"MOV(R13,STARG(1));" nl 
						
						"/* R6 will old the STARG offset */" nl
						"MOV(R6, IMM(" (number->string starg_off) "));" nl
						
						"/* R5 will old the FPARG offset */" nl
						"MOV(R5, R12);" nl
						"ADD(R5, IMM(1));" nl

						"/* R4 is the running index */" nl
						"MOV(R4, IMM(0));" nl
						
						loop-label ":" nl
						"CMP(R4, IMM(" (number->string number_of_copy) "));" nl
						"JUMP_EQ(" loop-label-exit ");" nl
						"MOV(FPARG(R5), STARG(R6));" nl
						"SUB(R6, IMM(1));" nl
						"SUB(R5, IMM(1));" nl
						"ADD(R4, IMM(1));" nl
						"JUMP(" loop-label ");" nl
						loop-label-exit ":" nl
						"MOV(R9, R13);" nl											
						"SUB(R9, IMM(1));" nl
						"SUB(R9, R12);" nl
						"MOV(SP, FP);" nl
						"ADD(SP, R9);" nl
						"MOV(FP, R8);" nl
						"JUMPA(INDD(R0, 2));" nl					
						
	))))

;;;;;;; END OF APPLIC ;;;;;;;;;;


;;;;;; VARS 
(define codegen-pvar
	(lambda (e envL paramsL)
		
		(string-append
			"/* in pvar */" nl
			"MOV(R0, FPARG(" (number->string (+ 2 (get-major e))) "));" nl )
))

(define codegen-bvar
	(lambda (e envL paramsL)
		(string-append
			"/* in bvar */" nl
			"MOV(R1,FPARG(LOC_ENV));" nl
			"MOV(R2,INDD(R1,IMM(" (number->string (get-major e)) ")));" nl
			"MOV(R3,INDD(R2,IMM(" (number->string (get-minor e)) ")));" nl
			"MOV(R0,R3);" nl
)))

(define codegen-fvar
	(lambda (e envL paramsL)
		(let*  (
				(freeVarSym 				(cadr e))
				(freeVarEntry     			(getEntryFromSymbolTable freeVarSym))
				(freeVarBucketValueAddr 	(+ 4 (car freeVarEntry)))
		       )
		(string-append
			"/* in fvar */" nl
			"MOV(R1, IMM(" (number->string freeVarBucketValueAddr) "));" nl
			"MOV(R2,INDD(R1,0));" nl
			"MOV(R0,R2);" nl
))))

(define get-name
	(lambda (v)
		(cadr v)
))
(define get-major
	(lambda (v)
		(caddr v)
))
(define get-minor
	(lambda (v)
		(cadddr v)
))

(define map-code-gen
	(lambda (envL paramsL)
		(lambda (e)
			(code-gen e envL paramsL)
)))




;;;;; CONSTS PART ;;;;;;;;;

(define ^^GlobalCounter
	(lambda (initval)
		(let ((n initval))
			(lambda (enum)
				(if (= enum 0)
					n
					(begin
						(set! n (+ n enum))
						n
					)
)))))

(define ^^GlobalTable
	(lambda ()
		(let ((lst (list)))
			(lambda (newL)
				(if (eq? newL 0)
					lst
					(begin
						(set! lst (append lst newL))
						lst
					)
)))))

(define freeMem 	(^^GlobalCounter 10))
(define g_consTable (^^GlobalTable))


(define string->listOfAscii
	(lambda (str)
		(let* (
				(listOfChars 	(string->list str))
				(listOfAscii	(map char->integer listOfChars))
			  )
			listOfAscii
)))

(define t_void 		937610)
(define t_nil 		722689)
(define t_bool 		741553)
(define t_char 		181048)
(define t_integer 	945311)
(define t_string 	799345)
(define t_symbol 	368031)
(define t_pair 		885397)
(define t_vector 	335728)
(define t_closure 	276405)


(define foo
 	(lambda (e)
 		(cond
 			((or (char? e) (number? e) (string? e) (void? e) (null? e) (boolean? e)) `(,e))
 			((pair? e)
 				`(,e ,@(foo (car e)) ,@(foo (cdr e))))
 			((vector? e)
 				`(,e ,@(apply append
 							(map foo
 								(vector->list e)))))
 			((symbol? e)
 				`(,e ,@(foo (symbol->string e))))
 )))

(define getAllValuesByKey
	(lambda (key sexprs)
		(map cadr (filter (lambda (element) (and (pair? element) (eq? key (car element)))) (apply append (map foo sexprs))))
))

(define flatten
	(lambda (var)
  		(cond ((null? var) '())
        	((pair? var) (append (flatten (car var)) (flatten (cdr var))))
        	(else (list var))
    )))


(define existInConstTable? 
	(lambda (const accConstTable)
		(if (symbol? const) (existInSymbolTable? const (g_symbolsTable 0))
		(if 
			(null? accConstTable)
			#f
			(let* (
					(nextConst  	(car accConstTable))
					(nextConstVal  	(cadr nextConst))
					(restConsts 	(cdr accConstTable))
				  )

					(if 
						(equal? nextConstVal const)
						nextConst
						(existInConstTable? const restConsts)
					)
				)
			))))
; PreCond : entry exist.
(define getEntryFromConstTable
	(lambda (const)
		(let ((accConstTable (g_consTable 0)))
			(existInConstTable? const accConstTable)
		)
))

(define getEntryAddrFromConstTable
	(lambda (const)
		(let ((accConstTable (g_consTable 0)))
			(car (existInConstTable? const accConstTable))
		)
))

(define getEntryValuesFromConstTable
	(lambda (const)
		(let ((accConstTable (g_consTable 0)))
			(caddr (existInConstTable? const accConstTable))
		)
))

(define createNewTableEntryIfNotAlreadyExist
	(lambda (element)
		(let ((constTable (g_consTable 0)))
			(if 
				(not (existInConstTable? element constTable))
				(createNewTableEntry element)
			)
		)
))

(define createPairEntry
	(lambda (pairElement)
		(let* (
				(carEntry 		(existInConstTable? (car pairElement) (g_consTable 0)))
				(cdrEntry 		(existInConstTable? (cdr pairElement) (g_consTable 0)))
				(carEntryAddr	(car carEntry))
				(cdrEntryAddr	(car cdrEntry))
				(oldFM			(freeMem 0))
				(newFM			(freeMem 3))
				(newConstsEntry (list `(,oldFM ,pairElement (,t_pair ,carEntryAddr ,cdrEntryAddr))))
			)
			(g_consTable newConstsEntry)
)))


(define createVectorEntry
	(lambda (vecElement)
		(let* (
				(vecLength 				(vector-length vecElement))
				(vecConstsElements 		(map (lambda (x) (getEntryAddrFromConstTable x)) (vector->list vecElement)))
				(oldFM					(freeMem 0))
				(newFM					(freeMem (+ 2 vecLength)))
				(newConstsEntry (list `(,oldFM ,vecElement (,t_vector ,vecLength ,@vecConstsElements))))
			)
			(begin 
				(g_consTable newConstsEntry)
			)
)))


(define createNewTableEntry
	(lambda (newConst)
		(cond 
			((number? newConst)
				(let* (
						(oldFM			(freeMem 0))
						(newFM			(freeMem 2))
						(newConstsEntry (list `(,oldFM ,newConst (,t_integer ,newConst))))
					 )
					(g_consTable newConstsEntry)
				)
			)
			((char? newConst)
				(let* (
						(oldFM			(freeMem 0))
						(newFM			(freeMem 2))
						(newConstsEntry (list `(,oldFM ,newConst (,t_char ,(char->integer newConst)))))
					 )
					(g_consTable newConstsEntry)
				)
			)
			((string? newConst)
				(let* (
						(newConstLength	(string-length newConst))
						(oldFM			(freeMem 0))
						(newFM			(freeMem (+ 2 newConstLength)))
						(listOfChars	(string->listOfAscii newConst))
						(newConstsEntry (list `(,oldFM ,newConst (,t_string ,newConstLength ,@listOfChars))))
					 )
					(g_consTable newConstsEntry)
				)
			)
			((symbol? newConst) '())
			
			((pair? newConst)
				(let* (
						(afterFoo					(foo newConst))
						(afterFooRemovePairs 		(filter (lambda (var) (not (pair? var))) afterFoo))
						(flattenVars				(flatten afterFoo))
						(pairsList  				(filter pair? afterFoo))
					 )
					(begin 
						(map createNewTableEntryIfNotAlreadyExist flattenVars)
						(map createNewTableEntryIfNotAlreadyExist afterFooRemovePairs)
						(map createPairEntry pairsList)
					)
				)
			)
			((vector? newConst)
				(let* (
						(afterFoo					(foo newConst))
						(afterFooRemoveVectors 		(filter (lambda (var) (not (vector? var))) afterFoo))
						(flattenVars				(flatten afterFooRemoveVectors))
						(vectorList  				(filter vector? afterFoo))
					 )
					(begin
						(map createNewTableEntryIfNotAlreadyExist flattenVars) 
						(map createNewTableEntryIfNotAlreadyExist afterFooRemoveVectors)
						(map createVectorEntry vectorList)
						)
				)
			)
			(else (error 'createConstEntry "Cant recognize const type!."))
		)
))



(define createConstsTableHelper 
	(lambda (consts)
		(if 
			(null? consts) 
			(g_consTable 0)
			
			(let(
					(nextConst  (car consts))
					(restConsts (cdr consts))
				)
				(cond
					((existInConstTable? nextConst (g_consTable 0)) (createConstsTableHelper restConsts))
					(else 	(let* (
									(newEntry 		(createNewTableEntry nextConst))
								  )
								(createConstsTableHelper restConsts)
							)
					)))

)))

(define preDefinedConstsTable
	(lambda ()
		`(
			(1 ,(void) (,t_void))
			(2 () (,t_nil))
			(3 #f (,t_bool 0))
			(5 #t (,t_bool 1))
)))

(define createConstsTable 
	(lambda (consts)
		(let ((preDefinedConst (g_consTable (preDefinedConstsTable))))
			(createConstsTableHelper consts)
		)
))


(define constsTableCompiled
	(lambda ()
		(let (
				(constsTable (g_consTable 0))
			 )
			(letrec ( 	(writeRecFunc
							(lambda (addr lst)
								(if (null? lst)
									""
									(string-append
										"MOV(IND(IMM(" (number->string addr) ")), IMM(" (number->string (car lst)) "));" nl
										(writeRecFunc (+ 1 addr) (cdr lst))
								))))

						(recFunc
							(lambda (currTable)
								(if 
									(null? currTable)
									""
									(let* (
											(entry 		(car currTable))
											(entryAddr 	(car entry))
											(entrylst 	(caddr entry))
										 )
										(string-append
											(writeRecFunc entryAddr entrylst)
											(recFunc (cdr currTable))
											)))
								))
					)
					(recFunc constsTable)
			)
		)))


(define codegen-const 
	(lambda (sexp envL paramL)
		(let* (
				(const 	    (cadr sexp))
				(constsAddr (if (symbol? const) (begin (car (getEntryFromSymbolTable const))) (getEntryAddrFromConstTable const)))
			  )
			(string-append
				"/* In consts .. */" nl 
				"MOV(R0,IMM(" (number->string constsAddr)  "));"
			)
	)))

;;;;;; TILL HERE CONSTS PART

;; SYMBOL TABLE PART ;;;;;

(define g_symbolsTable (^^GlobalTable))
(define g_symbolsTableStartAddr (^^GlobalCounter 0))

(define removeDup
	(lambda (chList newList)
		(cond
			((null? chList) newList)
			((member (car chList) newList) (removeDup (cdr chList) newList))
			(else (removeDup (cdr chList) (cons (car chList) newList)))
)))

(define buildInProcString
	(string-append
"
(define map
  ((lambda (y) 
     ((lambda (map1) 
	((lambda (maplist) 
	   (lambda (f . s) 
	     (maplist f s))) 
	 (y (lambda (maplist) 
	      (lambda (f s) 
		(if (null? (car s)) '() 
		    (cons (apply f (map1 car s)) 
			  (maplist f (map1 cdr s))))))))) 
      (y (lambda (map1) 
	   (lambda (f s) 
	     (if (null? s) '() 
		 (cons (f (car s)) 
		       (map1 f (cdr s))))))))) 
   (lambda (f) 
     ((lambda (x) 
	(f (lambda (y z)
	     ((x x) y z))))
      (lambda (x) 
	(f (lambda (y z)
	     ((x x) y z))))))))


(define Ym
  (lambda fs
    (let ((ms (map
		(lambda (fi)
		  (lambda ms
		    (apply fi (map (lambda (mi)
				     (lambda args
				       (apply (apply mi ms) args))) ms))))
		fs)))
      (apply (car ms) ms)))) 
      

(define bin+ (lambda (x y) (+ x y)))
(define bin- (lambda (x y) (- x y)))
(define bin* (lambda (x y) (* x y)))
(define bin/ (lambda (x y) (/ x y)))
(define bin<? (lambda (x y) (< x y)))
(define bin>? (lambda (x y) (> x y)))
(define bin=? (lambda (x y) (= x y)))

(define bin<=? (lambda (a b) (not (bin>? a b))))
(define bin>=? (lambda (a b) (not (bin<? a b))))


(define add1 (lambda (n) (bin+ n 1))) 
(define sub1 (lambda (n) (bin- n 1)))


(define not (lambda (x) (if x #f #t)))

(define ormap
  (lambda (f . s)
    (letrec ((loop
	      (lambda (s)
		(and (pair? (car s))
		     (or (apply f (map car s))
			 (loop (map cdr s)))))))
      (loop s))))

(define andmap
  (lambda (f . s)
    (letrec ((loop
	      (lambda (s)
		(or (null? (car s))
		    (and (apply f (map car s))
			 (loop (map cdr s)))))))
      (loop s))))
      

(define order
  (lambda (<)
    (letrec ((loop
	      (lambda (a s)
		(or (null? s)
		    (and (< a (car s))
			 (loop (car s) (cdr s)))))))
      (lambda (a . s)
	(loop a s)))))


(define <= (order bin<=?))
(define >= (order bin>=?))

(define <>
  (letrec ((loop
	    (lambda (a s)
	      (or (null? s)
		  (and (andmap (lambda (b) (not (= a b))) s)
		       (loop (car s) (cdr s)))))))
    (lambda s
      (loop (car s) (cdr s)))))


(define foldr
  (lambda (binop final s)
    (letrec ((loop
	      (lambda (s)
		(if (null? s) final
		    (binop (car s) (loop (cdr s)))))))
      (loop s))))

(define compose
  (let ((binary-compose
	 (lambda (f g)
	   (lambda (x)
	     (f (g x))))))
    (lambda s
      (foldr binary-compose (lambda (x) x) s))))

(define caar (compose car car))
(define cadr (compose car cdr))
(define cdar (compose cdr car))
(define cddr (compose cdr cdr))
(define caaar (compose car caar))
(define caadr (compose car cadr))
(define cadar (compose car cdar))
(define caddr (compose car cddr))
(define cdaar (compose cdr caar))
(define cdadr (compose cdr cadr))
(define cddar (compose cdr cdar))
(define cdddr (compose cdr cddr))
(define caaaar (compose car caaar))
(define caaadr (compose car caadr))
(define caadar (compose car cadar))
(define caaddr (compose car caddr))
(define cadaar (compose car cdaar))
(define cadadr (compose car cdadr))
(define caddar (compose car cddar))
(define cadddr (compose car cdddr))
(define cdaaar (compose cdr caaar))
(define cdaadr (compose cdr caadr))
(define cdadar (compose cdr cadar))
(define cdaddr (compose cdr caddr))
(define cddaar (compose cdr cdaar))
(define cddadr (compose cdr cdadr))
(define cdddar (compose cdr cddar))
(define cddddr (compose cdr cdddr))

(define ^variadic-right-from-binary
  (lambda (binary-op base-value)
    (letrec ((op-list
	      (lambda (s)
		(if (null? s) base-value
		    (binary-op (car s) (op-list (cdr s)))))))
      (lambda args
	(op-list args)))))

(define ^variadic-left-from-binary
  (lambda (binary-op base-value)
    (letrec ((op-list
	      (lambda (acc s)
		(if (null? s) acc
		    (op-list (binary-op acc (car s)) (cdr s))))))
      (lambda args
	(if (null? args) base-value
	    (op-list (car args) (cdr args)))))))

(define ^char-op
  (lambda (int-op)
    (lambda (ch1 ch2)
      (int-op (char->integer ch1) (char->integer ch2)))))


(define char=? (order (^char-op bin=?)))
(define char<=? (order (^char-op bin<=?)))
(define char<? (order (^char-op bin<?)))
(define char>=? (order (^char-op bin>=?)))
(define char>? (order (^char-op bin>?)))

(define char-uppercase?
  (lambda (ch)
    (and (char<=? #\\A ch)
	 (char<=? ch #\\Z))))

(define char-lowercase?
  (lambda (ch)
    (and (char<=? #\\a ch)
	 (char<=? ch #\\z))))

(define char-upcase
  (let ((char-aA (- (char->integer #\\a) (char->integer #\\A))))
    (lambda (ch)
      (if (char-lowercase? ch)
	  (integer->char
	   (- (char->integer ch) char-aA))
	  ch))))

(define char-downcase
  (let ((char-aA (- (char->integer #\\a) (char->integer #\\A))))
    (lambda (ch)
      (if (char-uppercase? ch)
	  (integer->char
	   (+ (char->integer ch) char-aA))
	  ch))))

(define char-ci<=?
  (order
   (lambda (ch1 ch2)
     (char<=? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci<?
  (order
   (lambda (ch1 ch2)
     (char<? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci=?
  (order
   (lambda (ch1 ch2)
     (char=? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci>?
  (order
   (lambda (ch1 ch2)
     (char>? (char-upcase ch1) (char-upcase ch2)))))

(define char-ci>=?
  (order
   (lambda (ch1 ch2)
     (char>=? (char-upcase ch1) (char-upcase ch2)))))

(define string-upcase
  (lambda (string)
    (list->string
     (map char-upcase (string->list string)))))

(define string-downcase
  (lambda (string)
    (list->string
     (map char-downcase (string->list string)))))

(define even?
  (lambda (n)
    (zero? (remainder n 2))))

(define odd?
  (lambda (n)
    (not (zero? (remainder n 2)))))

(define length
  (lambda (s)
    (if (null? s) 0
	(add1 (length (cdr s))))))

(define list (lambda args args))

(define list-ref
  (lambda (s i)
    (if (zero? i) (car s)
	(list-ref (cdr s) (- i 1)))))

(define list?
  (lambda (e)
    (or (null? e)
	(and (pair? e)
	     (list? (cdr e))))))

(define member?
  (lambda (a s)
    (ormap (lambda (b) (eq? a b)) s)))

(define negative? (lambda (n) (< n 0)))

(define positive? (lambda (n) (> n 0)))

(define vector (lambda args (list->vector args)))


(define string->list
  (letrec ((loop
	    (lambda (str n s)
	      (if (= n -1) s
		  (loop str
			(- n 1)
			(cons (string-ref str n) s))))))
    (lambda (str)
      (loop str (- (string-length str) 1) '()))))

(define binary-string=?
  (lambda (str1 str2)
    (let ((n1 (string-length str1))
	  (n2 (string-length str2)))
      (and (= n1 n2)
	   (let ((s1 (string->list str1))
		 (s2 (string->list str2)))
	     (andmap char=? s1 s2))))))

(define binary-string<?
  (lambda (str1 str2)
    (letrec ((loop
	      (lambda (s1 s2)
		(cond ((null? s1) (pair? s2))
		      ((null? s2) #f)
		      ((char=? (car s1) (car s2))
		       (loop (cdr s1) (cdr s2)))
		      (else (char<? (car s1) (car s2)))))))
      (loop (string->list str1)
	    (string->list str2)))))

(define binary-string>? (lambda (str1 str2) (binary-string<? str2 str1)))

(define binary-string<=?
  (lambda (str1 str2) (not (binary-string>? str1 str2))))

(define binary-string>=?
  (lambda (str1 str2) (not (binary-string<? str1 str2))))

(define string=? (order binary-string=?))
(define string<? (order binary-string<?))
(define string>? (order binary-string>?))
(define string<=? (order binary-string<=?))
(define string>=? (order binary-string>=?))

(define vector->list
  (letrec ((loop
	    (lambda (v n s)
	      (if (= n -1) s
		  (loop v
			(- n 1)
			(cons (vector-ref v n) s))))))
    (lambda (v)
      (loop v (- (vector-length v) 1) '()))))

(define list->string
  (lambda (s)
    (let* ((n (length s))
	   (str (make-string n)))
      (letrec ((loop
		(lambda (s i)
		  (if (= i n) str
		      (begin
			(string-set! str i (car s))
			(loop (cdr s) (+ i 1)))))))
	(loop s 0)))))

(define list->vector
  (lambda (s)
    (let* ((n (length s))
	   (v (make-vector n)))
      (letrec ((loop
		(lambda (s i)
		  (if (= i n) v
		      (begin
			(vector-set! v i (car s))
			(loop (cdr s) (+ i 1)))))))
	(loop s 0)))))

(define member
  (lambda (a s)
    (cond ((null? s) #f)
	  ((equal? (car s) a) s)
	  (else (member a (cdr s))))))

;;; this procedure is defined as an abstraction over assoc/assq,
;;; with the potential to define assoc over new and interesting
;;; predicates...

(define equal?
  (let ((void-object (if #f #f)))
    (letrec ((equal?
	      (lambda (a b)
		(cond
		 ;; bool
		 ((and (boolean? a) (boolean? b))
		  (boolean=? a b))
		 ;; char
		 ((and (char? a) (char? b)) (char=? a b))
		 ;; nil
		 ((null? a) (null? b))
		 ;; number
		 ((and (number? a) (number? b)) (= a b))
		 ;; pair
		 ((and (pair? a) (pair? b))
		  (and (equal? (car a) (car b))
		       (equal? (cdr a) (cdr b))))
		 ;; string
		 ((and (string? a) (string? b)) (string=? a b))
		 ;; symbol
		 ((and (symbol? a) (symbol? b)) (eq? a b))
		 ;; vector
		 ((and (vector? a) (vector? b)
		       (= (vector-length a) (vector-length b)))
		  (equal? (vector->list a) (vector->list b)))
		 ;; void
		 ((eq? a void-object) (eq? b void-object))
		 (else #f)))))
      equal?)))

(define ^associate
  (lambda (equal?)
    (letrec ((run
	      (lambda (a s)
		(cond ((null? s) #f)
		      ((equal? (caar s) a) (car s))
		      (else (run a (cdr s)))))))
      run)))

(define assoc (^associate equal?))

(define assq (^associate eq?))

(define boolean=?
  (lambda (a b)
    (if (and (boolean? a) (boolean? b))
	(if a b (not b))
	#f ; should have generated an error message!
	)))


(define void
  (let ((void-object
	 (if #f #f)))
    (lambda () void-object)))

(define void?
  (let ((void-object (void)))
    (lambda (x) (eq? x void-object))))

(define string-append
  (lambda s
    (list->string (apply append (map string->list s)))))

(define vector-append
  (lambda s
    (list->vector (apply append (map vector->list s)))))

(define append
  (letrec ((app2
	    (lambda (s1 s2)
	      (if (null? s1) s2
		  (cons (car s1)
		   (app2 (cdr s1) s2)))))
	   (appl
	    (lambda (s1 s)
	      (if (null? s) s1
		  (app2 s1 (appl (car s) (cdr s)))))))
    (lambda s
      (if (null? s) '()
	  (appl (car s) (cdr s))))))

(define reverse
  (letrec ((loop
	    (lambda (s r)
	      (if (null? s) r
		  (loop (cdr s) (cons (car s) r))))))
    (lambda (s)
      (loop s '()))))

(define string-reverse
  (compose
   list->string
   reverse
   string->list))

(define list-ref
  (lambda (s i)
    (if (zero? i) (car s)
	(list-ref (cdr s) (- i 1)))))

(define list-set!
  (lambda (s i x)
    (if (zero? i) (set-car! s x)
	(list-set! (cdr s) (- i 1) x))))

(define max
  (let ((binary-max (lambda (a b) (if (> a b) a b))))
    (lambda (a . s)
      (foldr binary-max a s))))

(define min
  (let ((binary-min (lambda (a b) (if (< a b) a b))))
    (lambda (a . s)
      (foldr binary-min a s))))

"))


(define buildInProcList
	'(number? integer? boolean? char? null? pair? string? symbol? zero? vector? procedure? 
	    + - * / < > = char->integer integer->char string-length string-ref string-set! make-string 
	    vector-length vector-ref vector-set! make-vector cons car cdr list vector apply length symbol->string
	    string->symbol eq? set-cdr! set-car!)
)


(define createSymbolTable
	(lambda (symbols)
		(if 
			(null? symbols) 
			(g_symbolsTable 0)
			
			(let* (
					(nextSym  (car symbols))
					(restSyms (cdr symbols))
					(newEntry 		(createNewSymbolTableEntry nextSym))
				  )
				(begin 
					(g_symbolsTable newEntry)
					(createSymbolTable restSyms)							
				)
						
		))))

(define createNewSymbolTableEntry
	(lambda (sym)
		(let* 
			(
				(oldFm 				(freeMem 0))
				(newFm 				(freeMem 5))
				(stringObjAddr  	(getEntryAddrFromConstTable (symbol->string sym)))
				(newEntry 	(list `(,oldFm ,sym ,t_symbol ,(+ 3 oldFm) ,newFm ,stringObjAddr)))
			)
			newEntry
	)))

;; always exist!!!
(define existInSymbolTable? 
	(lambda (sym accSymTable)
		(if 
			(null? accSymTable)
			#f
			(let* (
					(nextSymEntry   (car accSymTable))
					(nextSymName  	(cadr nextSymEntry))
					(restSyms    	(cdr accSymTable))
				  )
				(if 
					(equal? nextSymName sym)
					nextSymEntry
					(existInSymbolTable? sym restSyms)
				)
			))))

; PreCond : entry exist.
(define getEntryFromSymbolTable
	(lambda (sym)
		(let ((accSymTable (g_symbolsTable 0)))
			(existInSymbolTable? sym accSymTable)
		)
))

(define getEntryBucketAddrFromSymbolTable
	(lambda (sym)
		(let ((accSymTable (g_symbolsTable 0)))
			(cadddr (existInSymbolTable? sym accSymTable))
		)
))

(define symbolTableCompiled
	(lambda ()
		(let (
				(symTable (g_symbolsTable 0))
			 )
			(letrec (
						(recFunc
							(lambda (currTable symAddr)
								(if 
									(null? currTable)
									(string-append
										"MOV(INDD(" (number->string symAddr) ", 2), 2);" nl
									)
									(let* (
											(entry 					(car currTable))
											(symAddr  				(car entry))
											(sym 					(cadr entry))
											(symbolTag 				(caddr entry))
											(bucketAddr 			(cadddr entry))
											(nextNodeAddr   		(cadddr (cdr entry)))
											(pointerToString  		(cadddr (cddr entry)))
											(initValInR0   			(putInitSymValueInR0 sym))
										 )
										(string-append
											"MOV(INDD(" (number->string symAddr) ", 0), IMM(" (number->string symbolTag)  "));" nl
											"MOV(INDD(" (number->string symAddr) ", 1), IMM(" (number->string bucketAddr) "));" nl
											"MOV(INDD(" (number->string symAddr) ", 2), IMM(" (number->string nextNodeAddr) "));" nl
											"MOV(INDD(" (number->string symAddr) ", 3), IMM(" (number->string pointerToString) "));" nl
											initValInR0
											"MOV(INDD(" (number->string symAddr) ", 4), R0);" nl
											(recFunc (cdr currTable) symAddr)
											)))
								))
					)
					(recFunc symTable (g_symbolsTableStartAddr 0))
			)
		)))

(define putInitSymValueInR0
	(lambda (sym)
		(string-append
			(cond
				((eq? sym 'number? ) (createClosureCodeFromLableName "IS_NUMBER"))
				((eq? sym 'integer? ) (createClosureCodeFromLableName "IS_INTEGER"))
				((eq? sym 'boolean? ) (createClosureCodeFromLableName "IS_BOOLEAN"))
				((eq? sym 'char? ) (createClosureCodeFromLableName "IS_CHAR"))
				((eq? sym 'null? ) (createClosureCodeFromLableName "IS_NULL"))
				((eq? sym 'pair? ) (createClosureCodeFromLableName "IS_PAIR"))
				((eq? sym 'string? ) (createClosureCodeFromLableName "IS_STRING"))
				((eq? sym 'symbol? ) (createClosureCodeFromLableName "IS_SYMBOL"))
				((eq? sym 'vector? ) (createClosureCodeFromLableName "IS_VECTOR"))
				((eq? sym 'procedure? ) (createClosureCodeFromLableName "IS_PROCEDURE"))
				((eq? sym 'zero? ) (createClosureCodeFromLableName "IS_ZERO_MY"))
				((eq? sym '+ ) (createClosureCodeFromLableName "VARIADIC_PLUS"))
				((eq? sym '* ) (createClosureCodeFromLableName "VARIADIC_MUL"))
				((eq? sym '/ ) (createClosureCodeFromLableName "VARIADIC_DIV"))
				((eq? sym '- ) (createClosureCodeFromLableName "VARIADIC_MINUS"))
				((eq? sym '= ) (createClosureCodeFromLableName "VARIADIC_EQUAL"))
				((eq? sym '> ) (createClosureCodeFromLableName "VARIADIC_GT"))
				((eq? sym '< ) (createClosureCodeFromLableName "VARIADIC_LT"))
				((eq? sym 'char->integer ) (createClosureCodeFromLableName "CHAR_TO_INTEGER"))
				((eq? sym 'integer->char ) (createClosureCodeFromLableName "INTEGER_TO_CHAR"))
				((eq? sym 'remainder ) (createClosureCodeFromLableName "REMAINDER"))
				((eq? sym 'string-length ) (createClosureCodeFromLableName "STRING_LENGTH"))
				((eq? sym 'string-ref ) (createClosureCodeFromLableName "STRING_REF"))
				((eq? sym 'string-set! ) (createClosureCodeFromLableName "STRING_SET"))
				((eq? sym 'make-string ) (createClosureCodeFromLableName "MAKE_STRING"))
				((eq? sym 'vector-length ) (createClosureCodeFromLableName "VECTOR_LENGTH"))
				((eq? sym 'vector-ref ) (createClosureCodeFromLableName "VECTOR_REF"))
				((eq? sym 'vector-set! ) (createClosureCodeFromLableName "VECTOR_SET"))
				((eq? sym 'make-vector ) (createClosureCodeFromLableName "MAKE_VECTOR"))
				((eq? sym 'cons ) (createClosureCodeFromLableName "CONS"))
				((eq? sym 'car ) (createClosureCodeFromLableName "CAR"))
				((eq? sym 'cdr ) (createClosureCodeFromLableName "CDR"))
				((eq? sym 'set-car! ) (createClosureCodeFromLableName "SET_CAR"))
				((eq? sym 'set-cdr! ) (createClosureCodeFromLableName "SET_CDR"))
				;((eq? sym 'vector ) (createClosureCodeFromLableName "VECTOR"))
				;((eq? sym 'list ) (createClosureCodeFromLableName "LIST"))
				((eq? sym 'apply ) (createClosureCodeFromLableName "APPLY_TC"))
				;((eq? sym 'length ) (createClosureCodeFromLableName "LENGTH"))
				((eq? sym 'symbol->string ) (createClosureCodeFromLableName "SYMBOL_TO_STRING"))
				((eq? sym 'string->symbol ) (createClosureCodeFromLableName "STRING_TO_SYMBOL"))
				((eq? sym 'eq? ) (createClosureCodeFromLableName "EQ"))
				(else "MOV(R0, 0);")
			)
		)
))

(define createClosureCodeFromLableName
	(lambda (labelName)
		(string-append
			"PUSH(LABEL(" labelName "));" nl
			"PUSH(IMM(0));" nl 
			"CALL(MAKE_SOB_CLOSURE);" nl
			"DROP(IMM(2));" nl
	)))


(define codegen-define
	(lambda (sexp envL paramL)
		(let* (
				(freeVar 					(cadr sexp))
				(freeVarSym 				(cadr freeVar))
				(freeVarEntry     			(getEntryFromSymbolTable freeVarSym))
				(freeVarBucketValueAddr 	(+ 4 (car freeVarEntry)))
				(newValue   				(caddr sexp))
				(newValueCompiled   		(code-gen newValue envL paramL))
				
			  )
			(string-append
				"/* In Define .. */" nl 
				newValueCompiled nl
				"MOV(ADDR(" (number->string freeVarBucketValueAddr) "), R0);" nl
				"MOV(R0, SOB_VOID);" nl
			)
	)))

;; TILL HERE SYMNOL TABLE PART ;;;;;

(define getInputFileSexpsCompiledCode
	(lambda (sexps)
		(let* (
				(parsedSexps			(map parse sexps))
				(lexParesedSexprs		(map pe->lex-pe parsedSexps))
				(at-lexParesedSexprs	(map annotate-tc lexParesedSexprs))
			  )
			  (letrec ( (recFunc
			  				(lambda (sexps)
			  					(if
			  						(null? sexps)
			  						nl
			  						(string-append
			  							(code-gen (car sexps) 0 0) nl
			  							"CALL(PRINT_R0);" nl
			  							(recFunc (cdr sexps))
			  						)
			  						)))


			  		  )
			  		(recFunc at-lexParesedSexprs)
			  )
		)


))

(define compile-scheme-file
	(lambda (inputFileName outputFileName)
		(let* 	(
					(sexps 							(readSexprs inputFileName))
					(buildInProcSexprs				(readSexprsFromString buildInProcString))
					(allSexprs						(append buildInProcSexprs sexps))
					(parsedSexps					(map parse allSexprs))
					(lexParesedSexprs				(map pe->lex-pe parsedSexps))
					(at-lexParesedSexprs			(map annotate-tc lexParesedSexprs))
					(consts 						(getAllValuesByKey 'const at-lexParesedSexprs))
					(freeVars 						(getAllValuesByKey 'fvar at-lexParesedSexprs))
					(allSymbolsInConsts 			(filter symbol? consts))
					(needToBeInConstsTable			consts)
					(needToBeInSymbolTable			(append buildInProcList freeVars allSymbolsInConsts (filter symbol? (apply append (map foo consts)))))
					(needToBeInConstsTableRDup		(removeDup needToBeInConstsTable '()))
					(needToBeInSymbolTableRDup		(removeDup needToBeInSymbolTable '()))
					(allSymbolStringsThatCanAppear  (map symbol->string needToBeInSymbolTableRDup))
			 	)
				
				(begin 
					(createConstsTable allSymbolStringsThatCanAppear)
					(g_symbolsTableStartAddr (freeMem 20))
					(createSymbolTable needToBeInSymbolTableRDup)
					(freeMem 20)
					(createConstsTable needToBeInConstsTableRDup)
					(let* 
						(
							(startS 		(start-string))
							(consTableS 	(constsTableCompiled))
							(symbolTableS 	(symbolTableCompiled))
							(codeS 			(getInputFileSexpsCompiledCode allSexprs))
						)
						(begin
							(writeStringToFile outputFileName (string-append startS consTableS symbolTableS codeS end-string))
						)

					)

				)
)))

(define code-gen
	(lambda (sexp envL paramL)
		(let ((tag (if (null? sexp) '() (car sexp))))
			(cond
				((tag-pe? 'if3 tag) 			(codegen-if3 sexp envL paramL))
				((tag-pe? 'or tag)  			(codegen-or sexp envL paramL))
				((tag-pe? 'seq tag)  			(codegen-seq sexp envL paramL))
				((tag-pe? 'lambda-simple tag)	(code-gen-lambda sexp envL paramL))
				((tag-pe? 'lambda-opt tag)		(code-gen-lambda sexp envL paramL))
				((tag-pe? 'lambda-variadic tag)	(code-gen-lambda sexp envL paramL))
				((tag-pe? 'applic tag)			(codegen-applic sexp envL paramL))
				((tag-pe? 'tc-applic tag)		(codegen-tc-applic sexp envL paramL))
				((tag-pe? 'pvar tag)			(codegen-pvar sexp envL paramL))
				((tag-pe? 'bvar tag)			(codegen-bvar sexp envL paramL))
				((tag-pe? 'fvar tag)			(codegen-fvar sexp envL paramL))
				((tag-pe? 'const tag)			(codegen-const sexp envL paramL))
				((tag-pe? 'define tag)			(codegen-define sexp envL paramL))
				(else (error 'codegen "Code Geb Error!."))

	))))


(define start-string 
	(lambda ()
	(string-append 
		"#include <stdio.h>" nl
        "#include <stdlib.h>" nl
        "#include \"arch/cisc.h\"" nl
        "int main() {" nl
        		"#define SOB_TRUE 5" nl
        		"#define SOB_FALSE 3" nl
        		"#define SOB_NIL 2" 	nl
        		"#define SOB_VOID 1"	nl
        		"#define LOC_ENV 0"		nl
            	"#define LOC_NUM_ARGS 1" nl
            	"#define SYM_TAB_START " (number->string (g_symbolsTableStartAddr 0)) " " nl
             	"START_MACHINE;" nl
                "JUMP(LETS_START);" nl
                "#include \"arch/char.lib\"" nl
                "#include \"arch/io.lib\"" nl
                "#include \"arch/scheme.lib\"" nl
                "#include \"arch/math.lib\"" nl
                "#include \"arch/string.lib\"" nl
                "#include \"arch/system.lib\"" nl
                "#include \"arch/project_proc.lib\"" nl
                "ERROR:" nl
                "HALT;" nl
                "LETS_START:" nl
                "PUSH(0);" nl
                "PUSH(0);" nl
                "PUSH(0);" nl
                "PUSH(FP);"  nl
                "MOV(FP, SP);" nl
                "MOV(IND(0), IMM(" (number->string (freeMem 20)) "));" nl

		)))


(define end-string
	(string-append 
		"POP(FP);" nl
		"DROP(IMM(3));" nl
		"STOP_MACHINE;" nl
         "HALT;" nl
		"}" nl
		))


(compile-scheme-file "test2-lambda.scm" "foo.c")