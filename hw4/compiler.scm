
(load "hw123.scm")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; homeWork4;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; common ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define nl (list->string  (list #\newline)))
 
(define remove_duplicate
  (lambda (lst)
    (letrec ((loop 
      (lambda (lst1 lst2)
      (if (null? lst1) lst2
          (if (member (car lst1) lst2)
              (loop (cdr lst1) lst2)
              (loop (cdr lst1) `(,@lst2 ,(car lst1)))
          )
      )))
    ) (loop lst (list))
  )))

(define create-list-of-certain-type
  (lambda (exp2 varType)
    (letrec (
      (table '())
      (loop 
      (lambda (exp)
        (cond 
          ((not (list? exp)) (void))
          ((null? exp) (void))
          ((equal? (car exp) varType) (set! table `(,@table ,(cadr exp))))
          (else (begin (loop (car exp)) (loop (cdr exp))))))))
    (begin (loop exp2) table)
    ))
    )

(define address 10)

(define labelNum 0)
(define labelNumberInString 
  (lambda ()
        (set! labelNum (+ labelNum 1))
          (number->string labelNum)
  ))

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


(define initConstTable
  (lambda ()
    (set! const_table `(,@const_table (,address ,(void) ,T_VOID)))
    (set! address (+ address 1))
    (set! const_table `(,@const_table (,address () ,T_NIL)))
    (set! address (+ address 1))
    (set! const_table `(,@const_table (,address ,#f ,T_BOOL)))
    (set! address (+ address 2))
    (set! const_table `(,@const_table (,address ,#t ,T_BOOL)))
    (set! address (+ address 2))
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
    (loop const_table))))



(define addToConstTable
  (lambda (const)
    (let ((cVar const))
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
          (set! const_table `(,@const_table (,address ,cVar (,T_SYMBOL ,(string-length (symbol->string cVar)) ,@(map char->integer (string->list (symbol->string cVar)))))))
          (set! address (+ address 2 (string-length (symbol->string cVar)))))
      ((pair? cVar)
          (addToConstTable (car cVar))
          (addToConstTable (cdr cVar))
          (set! const_table `(,@const_table (,address ,cVar (,T_PAIR ,(getConstAddress (car cVar)) ,(getConstAddress (cdr cVar))))))
          (set! address (+ address 3)))
      ((vector? cVar)
          (map (lambda (c) (addToConstTable c)) (vector->list cVar))
          (set! const_table `(,@const_table (,address ,cVar (,T_VECTOR ,(length (vector->list cVar)) ,@(map getConstAddress (vector->list cVar))))))
          (set! address (+ address 2 (length (vector->list cVar)))))

  )))
)


(define load-void (lambda (idx) (string-append "MOV(IND(" (number->string idx) "), IMM(T_VOID));" nl)))
(define load-nil (lambda (idx) (string-append "MOV(IND(" (number->string idx) "), IMM(T_NIL));" nl)))
(define load-bool 
  (lambda (idx) 
    (if (equal? idx 12)
      (string-append "MOV(IND(" (number->string idx) "), IMM(T_BOOL));" nl 
      "MOV(IND(" (number->string (+ idx 1)) "), IMM(0));" nl )
       (string-append "MOV(IND(" (number->string idx) "), IMM(T_BOOL));" nl 
      "MOV(IND(" (number->string (+ idx 1)) "), IMM(1));" nl )     
    )))

(define load-char (lambda (idx val) 
	(string-append "MOV(IND(" (number->string idx) "), IMM(T_CHAR));" nl
				   "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string (car val)) "));" nl)))

(define load-int (lambda (idx val) 
	(string-append "MOV(IND(" (number->string idx) "), IMM(T_INTEGER));" nl
				   "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string val) "));" nl)))

(define load-string-chars
	(lambda (idx chars)
		(if (null? chars) ""
			(let ((c (number->string (car chars))))
				(string-append "MOV(IND(" (number->string idx) "), IMM("c"));" nl
					(load-string-chars (+ idx 1) (cdr chars)))))))

(define load-string 
	(lambda (idx val) 
		(let (
			(len (car val))
			(chars (cdr val)))
				(string-append "MOV(IND(" (number->string idx) "), IMM(T_STRING));" nl
							   "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string len) "));" nl
							   (load-string-chars (+ idx 2) chars)))))

(define load-symbol 
	(lambda (idx val) 
    (let (
      (len (car val))
      (chars (cdr val)))
        (string-append "MOV(IND(" (number->string idx) "), IMM(T_SYMBOL));" nl
                 "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string len) "));" nl
                 (load-string-chars (+ idx 2) chars)))))

(define load-pair 
	(lambda (idx val) 
		(string-append "MOV(IND(" (number->string idx) "), IMM(T_PAIR));" nl
					   "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string (car val)) "));" nl
					   "MOV(IND(" (number->string (+ idx 2)) "), IMM(" (number->string (cadr val)) "));" nl)))

(define load-vector 
	(lambda (idx val) 
		(let (
			(len (car val))
			(chars (cdr val)))
				(string-append "MOV(IND(" (number->string idx) "), IMM(T_VECTOR));" nl
							   "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string len) "));" nl
							   (load-string-chars (+ idx 2) chars)))))

(define initiate-consts
	(lambda (consts)
		(if (not (null? consts))
			(let* ((const-exp (car consts))
				(idx (car const-exp))
				(var (cadr const-exp))
				(type (caddr const-exp))
				(rest (cdr consts)))
					(cond 
						((equal? type T_VOID) (string-append (load-void idx) (initiate-consts rest)))
						((equal? type T_NIL) (string-append (load-nil idx) (initiate-consts rest)))
						((equal? type T_BOOL) (string-append (load-bool idx) (initiate-consts rest)))
						((equal? (car type) T_CHAR) (string-append (load-char idx (cdr type)) (initiate-consts rest)))
						((equal? (car type) T_INTEGER) (string-append (load-int idx (cadr type)) (initiate-consts rest)))
						((equal? (car type) T_STRING) (string-append (load-string idx (cdr type)) (initiate-consts rest)))
						((equal? (car type) T_SYMBOL) (string-append (load-symbol idx (cdr type)) (initiate-consts rest)))
						((equal? (car type) T_PAIR) (string-append (load-pair idx (cdr type)) (initiate-consts rest)))
						((equal? (car type) T_VECTOR) (string-append (load-vector idx (cdr type)) (initiate-consts rest)))
						(else "")
						)
				)
			""
			)
		))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; global table ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define global_table '())
(define saveProcedures
  '(+ - * / < > = number? integer? boolean? symbol? char? null? pair? string? zero? vector? procedure? 
      char->integer integer->char string-length string-ref string-set! make-string 
      vector-length vector-ref vector-set! make-vector cons car cdr set-cdr! set-car! list vector apply length symbol->string
      string->symbol eq?)
)



(define load-fvar-symbol 
  (lambda (idx len val) 
        (string-append "MOV(IND(" (number->string idx) "), IMM(T_SYMBOL));" nl
                 "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string len) "));" nl
                 (load-string-chars (+ idx 2) val))))


(define initiate-fvar
  (lambda (fvarList)
    (if (not (null? fvarList))
      (let* ((fvar-exp (car fvarList))
        (idx (car fvar-exp))
        (var (cadr fvar-exp))
        (type (caddr fvar-exp))
        (rest (cdr fvarList)))
      (string-append (load-symbol idx (cdr type)) (initiate-fvar rest)))
      ;  (string-append (load-fvar-symbol idx (string-length (symbol->string var)) (map char->integer (string->list (symbol->string var)))) (initiate-fvar rest)))
      ""
      )
    ))



(define addLstToGlobalTable
  (lambda (fvarList)
    (letrec ((loop 
      (lambda (lst) 
        (cond 
        ((null? lst) (void))
        ((not(getGlobalVarAddress (car lst)))
           (set! global_table `(,@global_table (,address ,(car lst) (,T_SYMBOL ,(string-length (symbol->string (car lst))) ,@(map char->integer (string->list (symbol->string (car lst))))))))
           (set! address (+ address 2 (string-length (symbol->string (car lst)))))
           (loop (cdr lst)))
        (else (loop (cdr lst)))
        )
      )))
    (loop fvarList))))



(define getGlobalVarAddress
  (lambda (var)
    (letrec ((loop 
            (lambda (global_table)
              (cond 
                ((null? global_table) #f)
                ((equal? (cadar global_table) var) (caar global_table))
                (else (loop (cdr global_table)))
              )
            )
    ))
    (loop global_table))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; generate ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



(define codeGenOnAllSexps
  (lambda (sexps)
        (letrec ((loop
                (lambda (exps)
                  (if (null? exps)
                      ""
                      (string-append
                        (code-gen (car exps) 0 0) nl
                        ;"PUSH(R0);" nl
                        "CALL(PRINT_R0);" nl nl
                       ; "SHOW(\"\", R0);" nl
                        (loop (cdr exps))
                    )))))
            (loop sexps)
        )))

(define code-gen
  (lambda (sexpr envLevel numberOfParams )
        (newline)
    (display ":::::")

    (display sexpr)
    (newline)
      (cond
        ((null? sexpr) (list))
        ((equal? (car sexpr) 'const) (code-gen-const sexpr envLevel numberOfParams))
        ((equal? (car sexpr) 'fvar) (code-gen-fvar sexpr envLevel numberOfParams))
        ((equal?  (car sexpr) 'if3) (code-gen-if sexpr envLevel numberOfParams))
        ((equal?  (car sexpr) 'or) (code-gen-or sexpr envLevel numberOfParams))
        ((equal?  (car sexpr) 'applic) (code-gen-applic sexpr envLevel numberOfParams))
        (else (error 'code-gen "Code-gen didn't recognize the type of the sexpr"))
    )))

(define code-gen-const
(lambda (const envLevel numberOfParams)
          (string-append 
           "/*const*/" nl
           "MOV(R0," (number->string (getConstAddress (cadr const)))");" nl
           )))

(define code-gen-fvar
  (lambda (fvar envLevel numberOfParams)
    (string-append
      "/*fvar */" nl
      "MOV(R0," (number->string (getGlobalVarAddress (cadr fvar)))");" nl
                "SHOW(\"\", R0);" nl

)))


(define code-gen-if
  (lambda (ifExp envLevel numberOfParams)
    (let* ( 
      (code-gen-test (code-gen (cadr ifExp) envLevel numberOfParams))
      (code-gen-do-if-true (code-gen (caddr ifExp) envLevel numberOfParams))
      (code-gen-do-if-false (code-gen (cadddr ifExp) envLevel numberOfParams))
      (labelElse (string-append "labelElse" (labelNumberInString)))
      (labelIfExit (string-append "labelIfExit" (labelNumberInString)))
      )
        (string-append
          "/*ifExp*/" nl
          code-gen-test nl
         ; "SHOW(\"\",R0)" nl
          "CMP(R0, FALSE);" nl
          "JUMP_EQ("labelElse");" nl
          code-gen-do-if-true nl
          "JUMP("labelIfExit");" nl
          labelElse":" nl
          code-gen-do-if-false nl
          labelIfExit":" nl)
)))


(define code-gen-or
  (lambda (orExp envLevel numberOfParams)
        (letrec (
          (lableOrExit (string-append "lableOrExit" (labelNumberInString)))
          (loop 
              (lambda (exprs)
                (string-append
                  (car exprs) nl
                  "CMP(R0, FALSE);" nl
                  "JUMP_NE("lableOrExit");" nl
                  (if 
                    (null? (cdr exprs))
                    (string-append lableOrExit":" nl)
                    (loop (cdr exprs))
                  )
                ))))
              
          (loop (map (lambda (exp) (code-gen exp envLevel numberOfParams)) (cadr orExp)))
        )))

;;;;;; TODO: 
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

;;;;;; TODO: 
(define code-gen-applic 
  (lambda (applicExp envLevel numberOfParams)
      (let*   (   
            (paramsList     (caddr applicExp))
            (compParams     (map (lambda (exp) (code-gen exp envLevel numberOfParams)) paramsList))
            (compFunction     (code-gen (cadr applicExp) envLevel numberOfParams))
          )
          nl(display compFunction)nl

          (string-append
            "/* push params reverse order. */" nl
            (push-applic-params (reverse compParams) (length paramsList))
            "/* push number of args. */" nl
            "PUSH(IMM(" (number->string (length paramsList)) "));" nl
            compFunction
            "PUSH(R0);" nl   ; push the closure environment
            "CALL(R0);" nl      
            "/* move to R5 number of args .. to know how to drop from stack. */" nl
            "MOV(R5,STARG(IMM(0)));" nl     
           ; "/* add r5 env, numOfArg */" nl
            "ADD(R5, IMM(2));" nl   
            "DROP(R5);"  nl       
        ))))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; compile-scheme-file ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


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
                          (exp (if (equal? parsedExp '(failed with report:)) '() (cadar parsedExp)))
                          (restStr (if (equal? parsedExp '(failed with report:)) '() (cadadr parsedExp))))	
                          (if (and (not (null? exp)) (equal? (caar parsedExp) 'match))
                              (if (equal? (string-length restStr) 0)
                                `(,@sexprLst ,exp)
                                (str-maker `(,@sexprLst ,exp) (cadadr parsedExp)))
                               sexprLst)
                  ))))
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

(define prolog
	(string-append
		"/* final compilar project" nl
		"Programmers: Ayelet Kalderon & Avishag Daniely */" nl nl

		"#include <stdio.h>" nl
		"#include <stdlib.h>" nl nl

		"/* change to 0 for no debug info to be printed: */" nl
		"#define DO_SHOW 1" nl nl
    "#define FALSE 12 " nl nl
    "#define TRUE 14 " nl nl

		"#include \"arch/cisc.h\"" nl nl

		"int main()" nl
		"{" nl
  		" START_MACHINE;" nl nl

  		" JUMP(CONTINUE);" nl nl

		"#include \"arch/char.lib\"" nl
		"#include \"arch/io.lib\"" nl
		"#include \"arch/math.lib\"" nl
		"#include \"arch/string.lib\"" nl
		"#include \"arch/system.lib\"" nl
		"#include \"arch/scheme.lib\""nl 
    "#include \"arch/ours.lib\"" nl nl

 		"CONTINUE:" nl
		)
	)

(define epilog 
	(string-append
		;print to stdout
		"PROG_ENDING: " nl
		"  STOP_MACHINE;"nl
		"  return 0;" nl
        "}" nl
		)

	)


(define compile-scheme-file
  (lambda (scheme_source_file cisc_target_file)
    (let* (
    	  (out-port (if (file-exists? cisc_target_file) (begin (delete-file cisc_target_file) (open-output-file cisc_target_file))
            		(open-output-file cisc_target_file)))
    	  (stringFile (file->string scheme_source_file))
          (sexprLst (string->schemeList stringFile))
          (parsedEvaledSexpr (total-evaluation sexprLst))
          (constant-list (remove_duplicate (create-list-of-certain-type parsedEvaledSexpr 'const))) ;need to call the table creator
          (fvar-list (create-list-of-certain-type parsedEvaledSexpr 'fvar))
          ;;add prolog and epilog to the code then write to file
          )
  
        ;make const table
            (initConstTable)
            (map addToConstTable constant-list)

            ;make global table
            (addLstToGlobalTable (append saveProcedures fvar-list))
            (display const_table)
    (newline)
  
            ;create cisc code
            (let ((cisc-exp (string-append
            					prolog nl
            					"/* ----------initiating const table---------- */" nl
            					(initiate-consts const_table) nl
                      (initiate-fvar global_table) nl
            					(codeGenOnAllSexps parsedEvaledSexpr) nl
            					epilog
            					)))
            	(display cisc-exp out-port)
            	)
            (close-output-port out-port))))



(compile-scheme-file "test-files/test1.scm" "foo.c")