
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

(define address 0)

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
(define T_FRAC   234097)
(define T_STRING  799345)
(define T_SYMBOL  368031)
(define T_PAIR  885397)
(define T_VECTOR  335728)
(define T_CLOSURE   276405)
(define T_UNDEFINED 999999)


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
      ((integer? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_INTEGER ,cVar))))
          (set! address (+ address 2)))
      ((number? cVar)
          (set! const_table `(,@const_table (,address ,cVar (,T_FRAC ,(numerator cVar) ,(denominator cVar)))))
          (set! address (+ address 3)))
      ((char? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_CHAR ,(char->integer cVar)))))
          (set! address (+ address 2)))
      ((string? cVar) 
          (set! const_table `(,@const_table (,address ,cVar (,T_STRING ,(string-length cVar) ,@(map char->integer (string->list cVar))))))
          (set! address (+ address 2 (string-length cVar))))
      ((symbol? cVar)
          (addToConstTable (symbol->string cVar))
          ;(set! const_table `(,@const_table (,address ,cVar (,T_SYMBOL ,(string-length (symbol->string cVar)) ,@(map char->integer (string->list (symbol->string cVar)))))))
          (set! const_table `(,@const_table (,address ,cVar (,T_SYMBOL ,(getConstAddress (symbol->string cVar))))))
          ;(set! address (+ address 2 (string-length (symbol->string cVar)))))
          (set! address (+ address 2)))
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
    (if (equal? idx 180000002)
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

(define load-frac (lambda (idx val)
  (string-append "MOV(IND(" (number->string idx) "), IMM(T_FRAC));" nl
        "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string (car val)) "));" nl
    "MOV(IND(" (number->string (+ idx 2)) "), IMM(" (number->string (cadr val)) "));" nl
    )))

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
      (stringIND (car val)))
      ;(len (car val))
      ;(chars (cdr val)))
        ;(string-append "MOV(IND(" (number->string idx) "), IMM(T_SYMBOL));" nl
         ;        "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string len) "));" nl
          ;       (load-string-chars (+ idx 2) chars)))))
          (string-append "MOV(IND(" (number->string idx) "), IMM(T_SYMBOL));" nl
                 "MOV(IND(" (number->string (+ idx 1)) "), IMM(" (number->string stringIND) "));" nl
                 ))))

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
            ((equal? (car type) T_FRAC) (string-append (load-frac idx (cdr type)) (initiate-consts rest)))
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



(define load-fvar
  (lambda (idx var val) 
    (cond 
      ((equal? var '+) (string-append (closureFromLabelMaker "PLUS") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '-) (string-append (closureFromLabelMaker "MINUS") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '/) (string-append (closureFromLabelMaker "DIVIDE") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '*) (string-append (closureFromLabelMaker "MULTIPLY") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '=) (string-append (closureFromLabelMaker "EQUAL") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '<) (string-append (closureFromLabelMaker "LOWER") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var '>) (string-append (closureFromLabelMaker "GREATER") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'boolean?) (string-append (closureFromLabelMaker "IS_BOOLEAN") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'char?) (string-append (closureFromLabelMaker "IS_CHAR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'integer?) (string-append (closureFromLabelMaker "IS_INT") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'null?) (string-append (closureFromLabelMaker "IS_NULL") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'pair?) (string-append (closureFromLabelMaker "IS_PAIR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'number?) (string-append (closureFromLabelMaker "IS_NUM") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'string?) (string-append (closureFromLabelMaker "IS_STRING") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'rational?) (string-append (closureFromLabelMaker "IS_NUM") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'vector?) (string-append (closureFromLabelMaker "IS_VECTOR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'procedure?) (string-append (closureFromLabelMaker "IS_PROC") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'symbol?) (string-append (closureFromLabelMaker "IS_SYMBOL") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'symbol->string) (string-append (closureFromLabelMaker "SYMBOL_2_STRING") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'string->symbol) (string-append (closureFromLabelMaker "STRING_2_SYMBOL") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'eq?) (string-append (closureFromLabelMaker "CHECK_EQ_OBJECT") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'car) (string-append (closureFromLabelMaker "CAR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'cdr) (string-append (closureFromLabelMaker "CDR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'cons) (string-append (closureFromLabelMaker "CONS") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'denominator) (string-append (closureFromLabelMaker "DENOMINATOR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'numerator) (string-append (closureFromLabelMaker "NUMERATOR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'zero?) (string-append (closureFromLabelMaker "OURS_IS_ZERO") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'char->integer) (string-append (closureFromLabelMaker "CHAR_2_INTEGER") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      ((equal? var 'integer->char) (string-append (closureFromLabelMaker "INTEGER_2_CHAR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'not) (string-append (closureFromLabelMaker "NOT") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'set-car!) (string-append (closureFromLabelMaker "SET_CAR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'set-cdr!) (string-append (closureFromLabelMaker "SET_CDR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'vector-set!) (string-append (closureFromLabelMaker "VECTOR_SET") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'vector-ref) (string-append (closureFromLabelMaker "VECTOR_REF") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'vector-length) (string-append (closureFromLabelMaker "VECTOR_LENGTH") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'make-vector) (string-append (closureFromLabelMaker "MAKE_VECTOR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
       ((equal? var 'vector) (string-append (closureFromLabelMaker "VECTOR") (string-append 
                  "MOV(IND(" (number->string idx) "), R0);" nl )))
      
      

      ;((equal? var 'cons) (string-append (closureFromLabelMaker "CONS") (string-append 
      ;            "MOV(IND(" (number->string idx) "), R0);" nl )))
      ;((equal? var 'list) (string-append (closureFromLabelMaker "LIST") (string-append 
      ;            "MOV(IND(" (number->string idx) "), R0);" nl )))
      (else
        (string-append 
                  "MOV(IND(" (number->string idx) "), IMM(" (number->string val) "));" nl
                 )))))


(define initiate-fvar
  (lambda (fvarList)
    (if (not (null? fvarList))
      (let* ((fvar-exp (car fvarList))
        (idx (car fvar-exp))
        (var (cadr fvar-exp))
        (type (caddr fvar-exp))
        (rest (cdr fvarList)))
        (string-append (load-fvar idx var type) (initiate-fvar rest)))
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
          ((not (getGlobalVarAddress (car lst)))
               (set! global_table `(,@global_table (,address ,(car lst) ,T_UNDEFINED)))
                  (set! address (+ address 1 ))
                  (loop (cdr lst)))
          (else (loop (cdr lst)))
        )
      )))
    (loop fvarList))))

(define closureFromLabelMaker
  (lambda (label)
    (string-append
      "PUSH(LABEL(" label "));" nl
      "PUSH(IMM(0));" nl 
      "CALL(MAKE_SOB_CLOSURE);" nl
      "DROP(IMM(2));" nl
  )))

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;symbol (string) linked list;;;;;;;;;;;;;

(define symbolLinkedList '())
(define symbStartAdd 50000)
(define lastSymbAdd '())

(define getAllSymbolStrings
  (lambda ()
    (letrec ((stringAddresses '())
      (loop (lambda (c_table)
              (if (null? c_table)
                stringAddresses
                (let ((e (car c_table)))
                  (if (and (list? (caddr e)) (equal? (caaddr e) T_SYMBOL))
                    (begin (set! stringAddresses `(,@stringAddresses ,(car e)))
                        (loop (cdr c_table)))
                    (loop (cdr c_table))
                  )
                )))))
    (loop const_table)
)))


(define load-symb
  (lambda (symb)
    (string-append 
      "MOV(IND("(number->string (car symb))"), IMM("(number->string (cadr symb))"));" nl
      )
    ))

(define load-last-symb
  (lambda (symb)
    (string-append 
      "MOV(IND("(number->string (car symb))"), IMM(0));" nl
      )
    ))

(define buildSchemeList
  (lambda (symbs)
    (if (not (null? symbs)) 
      (begin 
        (set! symbolLinkedList `(,@symbolLinkedList ,(list symbStartAdd (car symbs))))
        (set! symbolLinkedList `(,@symbolLinkedList ,(list (+ symbStartAdd 1) (+ symbStartAdd 2))))
        (set! symbStartAdd (+ symbStartAdd 2))
        (buildSchemeList (cdr symbs))
        )
    symbolLinkedList
)))

(define loadSymbolStrings
  (lambda (symbsList)
  (if (null? (cdr symbsList))
    (load-last-symb (car symbsList))
    (string-append
      (load-symb (car symbsList))
      (loadSymbolStrings (cdr symbsList))
      )
    )
  ))

(define buildLinkedList
  (lambda ()
    (let* ((allSymbolStrings (getAllSymbolStrings))
          (symbsList (buildSchemeList allSymbolStrings)))
    "")))

(define code-gen-symb-list
  (lambda (symbsList)
      (if (null? symbsList) 
        (string-append 
          "/* ----------initiating symbols string linked list---------- */" nl
          "MOV(IND("(number->string symbStartAdd)"), IMM(0));" nl)
            (string-append 
              "/* ----------initiating symbols string linked list---------- */" nl
            (loadSymbolStrings symbsList)
            )
)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; generate ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



(define codeGenOnAllSexps
  (lambda (sexps)
        (letrec ((loop
                (lambda (exps)
                  (if (null? exps)
                      ""
                      (string-append
                        (code-gen (car exps) 0 0) nl
                        ;"INFO;" nl
                        "CALL(PRINT_R0);" nl nl
                       ; "SHOW(\"\", R0);" nl
                        (loop (cdr exps))
                    )))))
            (loop sexps)
        )))

(define code-gen
  (lambda (sexpr envLevel paramsLevel)
    ;(newline)
    ;(display ":::::")
    ;(display sexpr)
    ;(newline)
      (cond
        ((null? sexpr) (list))
        ((equal? (car sexpr) 'const) (code-gen-const sexpr envLevel paramsLevel))
        ((equal? (car sexpr) 'fvar) (code-gen-fvar sexpr envLevel paramsLevel))
        ((equal? (car sexpr) 'pvar) (code-gen-pvar (cdr sexpr) envLevel paramsLevel))
        ((equal? (car sexpr) 'bvar) (code-gen-bvar (cdr sexpr) envLevel paramsLevel))
        ((equal? (car sexpr) 'set) (code-gen-set (cdr sexpr) envLevel paramsLevel))
        ((equal? (car sexpr) 'box-set) (code-gen-box-set (cdr sexpr) envLevel paramsLevel));need to check
        ((equal? (car sexpr) 'box-get) (code-gen-box-get (cdr sexpr) envLevel paramsLevel));need to check
        ((equal? (car sexpr) 'box) (code-gen-box (cdr sexpr) envLevel paramsLevel));need to check
        ((equal? (car sexpr) 'def) (code-gen-def (cdr sexpr) envLevel paramsLevel))
        ((equal?  (car sexpr) 'if3) (code-gen-if sexpr envLevel paramsLevel))
        ((equal?  (car sexpr) 'or) (code-gen-or sexpr envLevel paramsLevel))
        ((equal? (car sexpr) 'seq) (code-gen-seq (cadr sexpr) envLevel paramsLevel))
        ((equal?  (car sexpr) 'applic) (code-gen-applic sexpr envLevel paramsLevel))
        ((equal?  (car sexpr) 'lambda-simple) (code-gen-lambda sexpr envLevel paramsLevel))
        ((equal?  (car sexpr) 'lambda-opt) (code-gen-lambda sexpr envLevel paramsLevel)) 
        ((equal?  (car sexpr) 'lambda-var) (code-gen-lambda sexpr envLevel paramsLevel))
        ((equal? (car sexpr) 'tc-applic) (code-gen-tc-applic sexpr envLevel paramsLevel))
        (else (error 'code-gen "Code-gen didn't recognize the type of the sexpr"))
    )))

(define code-gen-def
  (lambda (defVar envLevel paramsLevel)
    (let (
      (varAddress (getGlobalVarAddress (cadar defVar)))
      (e (cadr defVar))
      )
    ;(display varAddress)
    (string-append 
    "/* define */"nl
    (code-gen e envLevel paramsLevel) nl
    "MOV(IND(IMM("(number->string varAddress)")),IMM(R0));" nl
    "MOV(R0, IMM(T_VOID));"nl
    ))
))


(define code-gen-const
(lambda (const envLevel paramsLevel)
  ;(display (number->string (getConstAddress (cadr const))))
          (string-append 
           "/*const*/" nl
           "MOV(R0, IMM(" (number->string (getConstAddress (cadr const)))"));" nl
           )))

(define code-gen-fvar
  (lambda (fvar envLevel paramsLevel)
    (string-append
      "/*fvar */" nl
      "MOV(R0, IND(" (number->string (getGlobalVarAddress (cadr fvar)))"));" nl
                ;"SHOW(\"\", R0);" nl

)))

(define code-gen-pvar
  (lambda (pvar envLevel paramsLevel)
    (let ((var (car pvar))
          (mindex (cadr pvar)))
    (string-append
      "/* pvar */" nl
      "MOV(R10, IMM("(number->string mindex)"));" nl
      "ADD(R10,IMM(2));" nl
      "MOV(R0, FPARG(R10));" nl
      )))) 

(define code-gen-bvar
  (lambda (bvar envLevel paramsLevel)
    (let ((var (car bvar))
          (mjrdex (cadr bvar))
          (mindex (caddr bvar)))
    (string-append
      "/* bvar */" nl
      "MOV(R0, FPARG(IMM(0)));" nl
      "MOV(R0,INDD(R0,"(number->string mjrdex) "));" nl
      "MOV(R0,INDD(R0,"(number->string mindex) "));" nl
      )))) 


;;also done for bvar, but not sure that it works, had no idea how to check this
(define code-gen-box
  (lambda (setvar envLevel paramsLevel)
    (if (equal? (caar setvar) 'pvar)
    (let ((mindex (caddar setvar)))
    (string-append
      "/* box-pvar */" nl
      "MOV(R10, IMM("(number->string mindex)"));" nl
      "ADD(R10,IMM(2));" nl
      (malloc 1) nl
      "MOV(IND(R0),FPARG(R10));" nl
      ))
    (let (
          (mjrdex (caddar setvar))
          (mindex (car (cdddar setvar))))
    (string-append
      "/* box-bvar */" nl
      "MOV(R1, FPARG(IMM(0)));" nl
      "ADD(R1,INDD(R1,IMM("(number->string mjrdex)")));" nl
      (malloc 1) nl
      "MOV(IND(R0),INDD(R1,IMM("(number->string mindex)")));" nl
      ))
    )))


;;also done for bvar, but not sure that it works, had no idea how to check this
(define code-gen-set
  (lambda (setvar envLevel paramsLevel)
    (cond ((equal? (caar setvar) 'pvar)
    (let ((e (cadr setvar))
          (mindex (caddar setvar)))
    (string-append
      "/* set-pvar */" nl
      (code-gen e envLevel paramsLevel) nl
      "MOV(R10, IMM("(number->string mindex)"));" nl
      "ADD(R10,IMM(2));" nl
      "MOV(FPARG(R10),R0);" nl
      "MOV(R0,IMM(T_VOID));" nl
      )))
    ((equal? (caar setvar) 'bvar)
    (let ((e (cadr setvar))
          (mjrdex (caddar setvar))
          (mindex (car (cdddar setvar))))
    (string-append
      "/* set-bvar */" nl
      (code-gen e envLevel paramsLevel) nl
      "MOV(R1, FPARG(IMM(0)));" nl
      "MOV(R1,INDD(R1,IMM("(number->string mjrdex)")));" nl
      "MOV(INDD(R1,IMM("(number->string mindex)")),R0);" nl
      "MOV(R0,IMM(T_VOID));" nl
      )))
    (else
    (let (
      (varAddress (getGlobalVarAddress (cadar setvar)))
      (e (cadr setvar))
      )
    (string-append 
    "/* define */"nl
    (code-gen e envLevel paramsLevel) nl
    "MOV(IND(IMM("(number->string varAddress)")),IMM(R0));" nl
    "MOV(R0, IMM(T_VOID));"nl
    )))
    )))

;need to check once box and box-set are done
(define code-gen-box-get
  (lambda (setvar envLevel paramsLevel)
    (if (equal? (caar setvar) 'pvar)
    (let (;(e (cadr setvar))
          (mindex (caddar setvar)))
    (string-append
      "/* box-get-pvar */" nl
      ;(code-gen e envLevel paramsLevel) nl
      "MOV(R10, IMM("(number->string mindex)"));" nl
      "ADD(R10,IMM(2));" nl
      "MOV(R0,IND(FPARG(R10)));" nl
      ;"INFO;" nl 
      ))
    (let (;(e (cadr setvar))
          (mjrdex (caddar setvar))
          (mindex (car (cdddar setvar))))
    (string-append
      "/* box-get-bvar */" nl
      ;(code-gen e envLevel paramsLevel) nl
      "MOV(R1, FPARG(IMM(0)));" nl
      "MOV(R1,INDD(R1,IMM("(number->string mjrdex)")));" nl
      "MOV(R1,INDD(R1,IMM("(number->string mindex)")));" nl
      "MOV(R0,IND(R1));" nl
      ;"INFO;" nl
      ))
    ))) 

(define code-gen-box-set
  (lambda (setvar envLevel paramsLevel)
    (if (equal? (caar setvar) 'pvar)
    (let ((e (cadr setvar))
          (mindex (caddar setvar)))
    (string-append
      "/* box-set-pvar */" nl
      (code-gen e envLevel paramsLevel) nl
      "MOV(R10, IMM("(number->string mindex)"));" nl
      "ADD(R10,IMM(2));" nl
      "MOV(IND(R10),R0);" nl
      ))
    (let ((e (cadr setvar))
          (mjrdex (caddar setvar))
          (mindex (car (cdddar setvar))))
    (string-append
      "/* box-set-bvar */" nl
      (code-gen e envLevel paramsLevel) nl
      "MOV(R1, FPARG(IMM(0)));" nl
      "MOV(R1,INDD(R1,IMM("(number->string mjrdex)")));" nl
      ;"INFO;" nl
      "MOV(R1,INDD(R1,IMM("(number->string mindex)")));" nl
      "MOV(IND(R1),R0);" nl
      ;"INFO;" nl
      ))
    )))

(define code-gen-if
  (lambda (ifExp envLevel paramsLevel)
    (let* ( 
      (code-gen-test (code-gen (cadr ifExp) envLevel paramsLevel))
      (code-gen-do-if-true (code-gen (caddr ifExp) envLevel paramsLevel))
      (code-gen-do-if-false (code-gen (cadddr ifExp) envLevel paramsLevel))
      (labelElse (string-append "labelElse" (labelNumberInString)))
      (labelIfExit (string-append "labelIfExit" (labelNumberInString)))
      )
        (string-append
          "/*ifExp*/" nl
          code-gen-test nl
         ; "SHOW(\"\",R0)" nl
         ;"INFO;" nl
          "CMP(R0, FALSE);" nl
          "JUMP_EQ("labelElse");" nl
          code-gen-do-if-true nl
          "JUMP("labelIfExit");" nl
          labelElse":" nl
          code-gen-do-if-false nl
          labelIfExit":" nl)
)))


(define code-gen-or
  (lambda (orExp envLevel paramsLevel)
        (letrec (
          (lableOrExit (string-append "lableOrExit" (labelNumberInString)))
          (loop 
              (lambda (exprs)
                (string-append
                  "/* or */" nl nl
                  (car exprs) nl
                  "CMP(R0, FALSE);" nl
                  "JUMP_NE("lableOrExit");" nl
                  (if 
                    (null? (cdr exprs))
                    (string-append lableOrExit":" nl)
                    (loop (cdr exprs))
                  )
                ))))
              
          (loop (map (lambda (exp) (code-gen exp envLevel paramsLevel)) (cadr orExp)))
        )))

(define code-gen-seq
  (lambda (seqExp envLevel paramsLevel)
    (if (null? seqExp) ""
        (string-append
          (code-gen (car seqExp) envLevel paramsLevel)
          (code-gen-seq (cdr seqExp) envLevel paramsLevel)))
  ))


(define push-params-reverse-order
  (lambda (reversedLst length)
    (if 
      (= length 0)
      ""
      (string-append
        (car reversedLst) nl
        "PUSH(R0);" nl
        (push-params-reverse-order (cdr reversedLst) (- length 1))
      ))))

(define code-gen-applic 
  (lambda (applicExp envLevel paramsLevel)
      (let*   (   
            (paramsList     (caddr applicExp))
            (compParams     (map (lambda (exp) (code-gen exp envLevel paramsLevel)) paramsList))
            (compFunction     (code-gen (cadr applicExp) envLevel paramsLevel))
          )
          (string-append
            "/* applic */" nl nl
            "/* push T_NIL for empty lambda var and opt */" nl
            "MOV(R0,IMM("(number->string (getConstAddress '()))"));" nl
            "PUSH(R0);" nl
            "/* push params in reverse order. */" nl
            (push-params-reverse-order (reverse compParams) (length paramsList))
            "/* push number of arguments */" nl
            "PUSH(IMM(" (number->string (length paramsList)) "));" nl
            compFunction
            "CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));" nl
            "JUMP_NE(ERROR);" nl
            "PUSH(INDD(R0,IMM(1)));" nl   ; push the closure environment
            "CALLA(INDD(R0,IMM(2)));" nl  ;call the func code
            "/* move number of args to R5, this is the amount to drop from stack. */" nl
            ;"MOV(R5,STARG(IMM(0)));" nl     
           ; "/* add r5 env, numOfArg and + 1 for T_NILL*/" nl
            ;"ADD(R5, IMM(3));" nl   
            ;"DROP(R5);"  nl    
            "DROP(1);" nl ;drop env
            "POP(R1);" nl ;pop num of args
            "INCR(R1);" nl ;add 1 for T_NILL
            "DROP(R1);" nl ;drop all args
        ))))





;;;;;; TODO: 
(define code-gen-tc-applic 
  (lambda (applicExp envLevel paramsLevel)
      (let*   (   
            (paramsList     (caddr applicExp))
            (compParams     (map (lambda (exp) (code-gen exp envLevel paramsLevel)) paramsList))
            (compFunction     (code-gen (cadr applicExp) envLevel paramsLevel))
            (parameterLoopLabel (string-append "closureParameterLoopLabel" (labelNumberInString)))
            (parameterLoopEndLabel (string-append "closureParameterLoopEndLabel" (labelNumberInString)))
            (endLabel (string-append "endLabel" (labelNumberInString)))
            (greaterLabel (string-append "greaterLabel" (labelNumberInString)))

            (equalLabel (string-append "equalLabel" (labelNumberInString)))
          )
          (string-append
            "/* tc-applic */" nl nl
            "/* push T_NIL for empty lambda var and opt */" nl
            "MOV(R0,IMM("(number->string (getConstAddress '()))"));" nl
            "PUSH(R0);" nl
            "/* push params in reverse order. */" nl
            (push-params-reverse-order (reverse compParams) (length paramsList))
            "/* push number of arguments */" nl
            "PUSH(IMM(" (number->string (length paramsList)) "));" nl
            compFunction
            "CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));" nl
            "JUMP_NE(ERROR);" nl
            "PUSH(INDD(R0,IMM(1)));" nl   ; push the closure environment

            nl 
            "/*tc-applic specific code starts here */" nl
            
            "PUSH(FPARG(-1));" nl ; push old ret   
            "MOV(R1,FPARG(-2));" nl ;R1 <- old fp
            "PUSH(R1);" nl ; push old fp
            "MOV(R2, FPARG(1));" nl ;R2 <- old num of arguments
            "INCR(R2);" nl ; increase since we also have a null arg

            "MOV(R3, R2);" nl ;R3 <- old num of arguments with T_NIL
            "INCR(R3);" nl
            "ADD(R2,IMM(4));" nl ;R2 <- number of old frame boxes
            "MOV(R4,STARG(2));" nl ;R4 <- hold new num of arguments
            "ADD(R4,IMM(3));" nl ;increase since we also have a null arg
            "MOV(R5, R4);" nl ;R5 <-will hold size of new frame
            "ADD(R5,IMM(2));" nl

           
            "/* loop over frame, R6 <- running indx */" nl
            "MOV(R6, IMM(0));" nl
            parameterLoopLabel ":" nl
            "CMP(R6, R5);" nl
            "JUMP_EQ(" parameterLoopEndLabel ");" nl
            "MOV(FPARG(R3), STARG(R4));" nl
            "DECR(R4);" nl
            "DECR(R3);" nl
            "INCR(R6);" nl
            "JUMP(" parameterLoopLabel ");" nl
            parameterLoopEndLabel ":" nl
            "CMP(R5,R2);" nl
            "JUMP_GE("greaterLabel");" nl
            "DROP(R5);" nl
            "SUB(R2,R5);" nl
            "DROP(R2);" nl
            "DROP(1);"
            "JUMP("endLabel");" nl
            greaterLabel ":" nl
            "CMP(R5,R2);" nl
            "JUMP_EQ("equalLabel");" nl
            "MOV(R7,R5);" nl
            "SUB(R5,R2);" nl
            "SUB(R7,R5);" nl
            "DROP(R7);" nl
            "DROP(1);"
            "JUMP("endLabel");" nl
            equalLabel ":" nl
            "DROP(R5);" nl
            "DROP(1);"
            endLabel ":" nl
            "MOV(FP, R1);" nl
            "JUMPA(INDD(R0, 2));" nl nl
        ))))



(define malloc
  (lambda(int)
    (string-append
        "PUSH(IMM(" (number->string int) "));" nl   
        "CALL(MALLOC);" nl
        "DROP(IMM(1));" nl
  )))

(define code-gen-lambda 
  (lambda (sexpr envLevel paramsLevel)
    (let (
      (bodyLabel (string-append "closureBodyLabel" (labelNumberInString)))
      (endLabel (string-append "closureEndLabel" (labelNumberInString)))
      (parameterLoopLabel (string-append "closureParameterLoopLabel" (labelNumberInString)))
      (parameterLoopEndLabel (string-append "closureParameterLoopEndLabel" (labelNumberInString)))
      (envLoopLabel (string-append "closureEnvLoopLabel" (labelNumberInString)))
      (envLoopEndLabel (string-append "closureEnvLoopEndLabel" (labelNumberInString)))  
     )
    (string-append
        "/* get old env address, put in R8 */" nl
        "MOV(R8, FPARG(0));" nl
        
        "/* make room for new env */" nl
        (malloc (+ 1 envLevel))

        "/* put new env in R9 */" nl
        "MOV(R9,R0);" nl

        "/* clone the env */" nl
        "/* R10 is i, R11 is j */" nl
        "MOV(R10, IMM(0));" nl
        "MOV(R11, IMM(1));" nl
        envLoopLabel ":" nl
        "CMP(R10,IMM(" (number->string envLevel) "));" nl
        "JUMP_EQ(" envLoopEndLabel ");" nl
        "MOV(INDD(R9,R11), INDD(R8,R10));" nl
        "INCR(R10);" nl
        "INCR(R11);" nl
        "JUMP(" envLoopLabel ");" nl
        envLoopEndLabel ": " nl
        
        "MOV(R12, FPARG(1));" nl ;number of params in previous lambda
        "PUSH(R12);" nl
        "CALL(MALLOC);" nl
        "DROP(1);"

        "/* put old params in R9 */" nl
        "MOV(INDD(R9,0),R0);" nl;we add the space for number of params in the env

        "/* clone parameters from stack */" nl        
        "/* R10 is i, R11 is j */" nl
        "MOV(R10, IMM(0));" nl
        "MOV(R11, IMM(2));" nl
        parameterLoopLabel ":" nl
        "CMP(R10,R12);" nl
        "JUMP_EQ(" parameterLoopEndLabel ");" nl
        "MOV(R13,INDD(R9,IMM(0)));" nl
        "MOV(INDD(R13,R10), FPARG(R11));" nl
        "INCR(R10);" nl
        "INCR(R11);" nl
        "JUMP(" parameterLoopLabel ");" nl
        parameterLoopEndLabel ": " nl
        "MOV(INDD(R9,IMM(0)),R13);" nl ;check that this change made a differance 
        "/* Calling malloc for closure, env and body. */" nl
        (malloc 3)
        "/* put closure in R0 */" nl
        "MOV(INDD(R0,IMM(0))," (number->string T_CLOSURE) ");" nl
        "/* put env in R0 */" nl
        "MOV(INDD(R0,IMM(1)), R9);" nl

        "/* closure body ...*/" nl
        "MOV(INDD(R0,IMM(2)), LABEL(" bodyLabel "));" nl

        "JUMP(" endLabel  ");" nl
        bodyLabel ":" nl
        "PUSH(FP);" nl
        "MOV(FP,SP);" nl
        (cond 
          ((eq? (car sexpr) 'lambda-simple) (code-gen-lambda-simple-body sexpr envLevel paramsLevel))
          ((eq? (car sexpr) 'lambda-opt) (code-gen-lambda-opt-body sexpr envLevel paramsLevel)) ;not implemented yet
          (else (code-gen-lambda-var-body sexpr envLevel paramsLevel)) ;not implemented yet
        )
        nl
        "POP(FP);" nl
        "RETURN;" nl
        "/* LABEL END LAMBDA */" nl
        endLabel ":" nl
      )
    )))

(define code-gen-lambda-simple-body
  (lambda (sexpr envLevel paramsLevel)
    (let ((numberOfParams (length (cadr sexpr)))
          (body (caddr sexpr)))
    (string-append
      "/* lambda simple body */" nl
      "/* check if number of params is correct */" nl
      "MOV(R1, FPARG(1));" nl
      "CMP(R1, IMM(" (number->string numberOfParams) "));" nl
      "JUMP_NE(ERROR);" nl
      "/* code-gen on body */" nl
      (code-gen body (+ 1 envLevel) numberOfParams) nl
))))


(define code-gen-lambda-var-body
  (lambda (sexpr envLevel paramsLevel)
    (let (
      (body         (caddr sexpr))
      (parameterLoopEndLabel (string-append "closureParameterLoopEndLabel" (labelNumberInString)))
      (pushLoopLabel (string-append "closurePushLoopLabel" (labelNumberInString)))
      (EndLabel (string-append "EndLabel" (labelNumberInString)))
      (noParamsLabel (string-append "noParamsLabel" (labelNumberInString)))
     )
    (string-append
      "/* lambda var body */" nl
      "/* pop old fp */"nl
      "POP(R10);"nl
      "/* pop return address */"nl
      "POP(R11);"nl
      "/* pop env */"nl
      "POP(R12);"nl
      "/* pop number of arguments */"nl
      "POP(R13);"nl nl
      "/* no params */" nl
      "CMP(R13,IMM(0));" nl
      "JUMP_EQ("noParamsLabel");" nl
      "/* with params */" nl

      "MOV(R14,R13);" nl
      "MOV(R15,R13);" nl
      "MOV(R4, IMM(0));" nl
      "ADD(R15,IMM(1));" nl
      "ADD(R14,IMM(2));" nl
      pushLoopLabel ":" nl
      "CMP(R4,R13);"nl
      "JUMP_EQ("parameterLoopEndLabel");"nl
      "MOV(R1, FPARG(R14));" nl
      "PUSH(R1);" nl
      "MOV(R1, FPARG(R15));" nl
      "PUSH(R1);" nl
      "CALL(MAKE_SOB_PAIR);" nl
      "DROP(IMM(2));" nl
      "MOV(FPARG(R14),R0);" nl
      "INCR(R4);" nl
      "DECR(R15);" nl
      "JUMP("pushLoopLabel");"
      parameterLoopEndLabel ":" nl
      "DROP(R13);" nl
      "JUMP("EndLabel");" nl
      nl
      noParamsLabel ":" nl
      "MOV(R1, "(number->string (getConstAddress '()))")" nl
      "MOV(FPARG(IMM(1)),R1);" nl
      EndLabel ":" nl
      "PUSH(R13);" nl
      "PUSH(R12);" nl
      "PUSH(R11);" nl
      "PUSH(R10);" nl
      "MOV(FP, SP);" nl
      "/* code-gen on body */" nl
      (code-gen body (+ 1 envLevel) 1) nl
))))

(define code-gen-lambda-opt-body
  (lambda (sexpr envLevel paramsLevel)
    (let ((numberOfParams (length (cadr sexpr)))
          (body (cadddr sexpr))
          (loopLabel (string-append "optLambdaCopyLabel" (labelNumberInString)))
          (loopEndLabel (string-append "optLambdaCopyEndLabel" (labelNumberInString)))
          (pushLabel (string-append "optLambdaCopyLabel" (labelNumberInString)))
          (pushEndLabel (string-append "optLambdaCopyEndLabel" (labelNumberInString)))
          (EndLabel (string-append "EndLabel" (labelNumberInString)))
          (noParamsLabel (string-append "noParamsLabel" (labelNumberInString)))
          (parameterLoopEndLabel (string-append "closureParameterLoopEndLabel" (labelNumberInString)))
          (pushLoopLabel (string-append "closurePushLoopLabel" (labelNumberInString)))
          )
      (string-append
      "/* lambda var body */" nl
      "/* pop old fp */"nl
      "POP(R10);"nl
      "/* pop return address */"nl
      "POP(R11);"nl
      "/* pop env */"nl
      "POP(R12);"nl
      "/* pop number of arguments */"nl
      "POP(R13);"nl nl

      
      "MOV(R5,R13);" nl
      "ADD(R5, IMM("(number->string (* -1 numberOfParams))"));" nl
      "/* no params */" nl
      "CMP(R5,IMM(0));" nl
      "JUMP_EQ("noParamsLabel");" nl
      "/* with params */" nl
      "MOV(R14,R13);" nl
      "MOV(R15,R13);" nl
      "MOV(R4, IMM(0));" nl
      "ADD(R15,IMM(1));" nl
      "ADD(R14,IMM(2));" nl
      pushLoopLabel ":" nl
      "CMP(R4,R5);"nl
      "JUMP_EQ("parameterLoopEndLabel");"nl
      "MOV(R1, FPARG(R14));" nl
      "PUSH(R1);" nl
      "MOV(R1, FPARG(R15));" nl
      "PUSH(R1);" nl
      "CALL(MAKE_SOB_PAIR);" nl
      "DROP(IMM(2));" nl
      "MOV(FPARG(R14),R0);" nl
      ;"INFO;" nl
      "INCR(R4);" nl
      "DECR(R15);" nl
      "JUMP("pushLoopLabel");"
      parameterLoopEndLabel ":" nl
      ;"CALL(PRINT_R0);" nl 
      "MOV(R15, IMM("(number->string (+ 2 numberOfParams))"));" nl
      "MOV(FPARG(R15), FPARG(R14));" nl
      ;"INFO;" nl
      "JUMP("EndLabel");" nl
      nl
      noParamsLabel ":" nl
      "MOV(R1, "(number->string (getConstAddress '()))")" nl
      "MOV(FPARG(IMM(1)),R1);" nl
      EndLabel ":" nl
      "PUSH(R13);" nl
      "PUSH(R12);" nl
      "PUSH(R11);" nl
      "PUSH(R10);" nl
      "MOV(FP, SP);" nl
      "/* code-gen on body */" nl
      (code-gen body (+ 1 envLevel) numberOfParams)
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
    "#define SOB_NIL 2" nl nl
    "#define FALSE 2 " nl nl
    "#define TRUE 4 " nl nl
    "#define LOCAL_NUM_ARGS 1 " nl nl
    "#define LOCAL_ENV 0" nl nl
    "#define SYMTAB 50000" nl nl

		"#include \"arch/cisc.h\"" nl
    "#include \"arch/BenTest.h\"" nl nl

		"int main()" nl
		"{" nl
  		" START_MACHINE;" nl nl                      
      "PUSH(IMM("(number->string 100000)"));" nl
      "CALL(MALLOC);" nl
      "DROP(1);" nl
      "PUSH(IMM(0));" nl
      "PUSH(IMM(0));" nl
      "PUSH(LABEL(PROG_ENDING));" nl
      "PUSH(FP);" nl
      "MOV(FP,SP);" nl nl 

  		" JUMP(CONTINUE);" nl nl

		"#include \"arch/char.lib\"" nl
		"#include \"arch/io.lib\"" nl
		"#include \"arch/math.lib\"" nl
		"#include \"arch/string.lib\"" nl
		"#include \"arch/system.lib\"" nl
		"#include \"arch/scheme.lib\""nl 
    "#include \"arch/ours.lib\"" nl nl

    "ERROR:" nl
        "HALT;" nl nl

 		"CONTINUE:" nl
		)
	)

(define epilog 
	(string-append
		;print to stdout
		"PROG_ENDING: " nl
    "  MOV(SP,FP);" nl
    "  POP(FP);" nl
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
          (fvar-no-duplicates (remove_duplicate (append saveProcedures fvar-list)))
          ;;add prolog and epilog to the code then write to file
          )
   ; (display parsedEvaledSexpr)
        ;make const table
            (initConstTable)
            (map addToConstTable constant-list)

            ;make global table
            (addLstToGlobalTable fvar-no-duplicates)

            (buildLinkedList) nl
            ;(display const_table)
            (newline)
            ;create cisc code
            (let ((cisc-exp (string-append
            					prolog nl
            					"/* ----------initiating const table---------- */" nl
            					(initiate-consts const_table) nl
                      (initiate-fvar global_table) nl
                      (code-gen-symb-list symbolLinkedList) nl
            					(codeGenOnAllSexps parsedEvaledSexpr) nl
            					epilog
            					)))
            	(display cisc-exp out-port)
            	)
            (close-output-port out-port))))



(compile-scheme-file "test-files/torture0.scm" "foo.c")
