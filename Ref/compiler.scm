(load "pattern-matcher.scm")
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(print-graph #f) ; display circular structures
(print-gensym #f) ; print gensym as g1234
(case-sensitive #f) ; ditto
(print-brackets #f) ; do not use brackets when pretty-printing

(revert-interaction-semantics) ; allow builtins to be redefined

;;; fix bug in optimizer
(#%$sputprop 'append '*flags* 122)
(#%$sputprop 'append! '*flags* 34)
(#%$sputprop 'list* '*flags* 1250)
(#%$sputprop 'cons* '*flags* 1250)

;;; And just for good luck :-)
(define with (lambda (s f) (apply f s)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define *reserved-words*
  '(and begin cond define do else if lambda
    let let* letrec or quasiquote unquote 
    unquote-splicing quote set! applic))

(define *void-object* (void))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define simple-const?
  (lambda (e)
    (or (boolean? e) (char? e) (number? e) (string? e) (eq? e *void-object*) )))

(define var?
  (lambda (e)
    (and (symbol? e) 
         (not (member e *reserved-words*)))))

(define lambda-with-optional-arguments?
  (lambda (args)
    (and (not (list? args)) (pair? args) (not (null? (last-pair args))) )))

(define get-n-items
    (lambda (args num)
        (if (> num 0)
            (cons (car args) (get-n-items (cdr args) (- num 1)))
            '()))) ;'

(define count
  (lambda (args c)
    (if (eq? (car args) c)
        1
        (+ 1 (count (cdr args) c)))))
    
(define slice
    (lambda (args c)
       (get-n-items args (count args c))))

(define mit-style? 
  (lambda (var-mit-style)
    (or (and (list? var-mit-style) (>= (length var-mit-style) 2)) ;lambda-simple
        (lambda-with-optional-arguments? var-mit-style)   ;lambda-opt
        (symbol? var-mit-style)  ;lambda-variadic
    )))

(define peExpr->lambda
  (lambda (args body)
    `(lambda ,args ,body)))

(define func?
  (lambda (f)
    (and (list? f) (>= (length f) 1)
         (or (and (symbol? (car f)) (not (member (car f) *reserved-words*)))
             (and (list? (car f)) (not (member (caar f) *reserved-words*)))))))

(define proc?
  (lambda (p)
    (not (member p *reserved-words*))))

(define parse-rest
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (parse (car lst)) (parse-rest (cdr lst))))))
    
;;tal
(define beginify
  (lambda (body)
    (cond ((null? body) *void-object*)
          ((and (list? body) (= 1 (length body))) (car body))
          (else `(begin ,@body)))))
;tal
(define pairs-list?
  (lambda (lst)
    (cond ((null? lst) #t)
          ((list? lst) 
           (and (pair? (car lst)) (pairs-list? (cdr lst))))
          (else #f))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define parse
  (let ((run
	 (compose-patterns
      ;;const
      (pattern-rule
	   `(quote ,(? 'c))
	   (lambda (c) `(const ,c)))
	  (pattern-rule
	   (? 'c simple-const?)
	   (lambda (c) `(const ,c)))
      ;;variable    
	  (pattern-rule
	   (? 'v var?)
	   (lambda (v) (if (symbol? v)
                       `(var ,v)
                       `(var ,@v))))
      ;;if    
	  (pattern-rule
	   `(if ,(? 'test) ,(? 'dit))
	   (lambda (test dit)
	     `(if3 ,(parse test) ,(parse dit) (const ,*void-object*))))
	  (pattern-rule
	   `(if ,(? 'test) ,(? 'dit) ,(? 'dif))
	   (lambda (test dit dif)
	     `(if3 ,(parse test) ,(parse dit) ,(parse dif))))
	 
	  ;;lambda
          ;tal
      (pattern-rule
	   `(lambda ,(? 'args lambda-with-optional-arguments?)  .,(? 'implicit-sequence pair? list? ));pair? list?
	   (lambda (args body)
	    `(lambda-opt ,(slice args (car(last-pair args))) ,(cdr(last-pair args)) ,(parse (beginify body))))) ;;;;--->  `(begin body)
      (pattern-rule
	   `(lambda ,(? 'args list?)  .,(? 'implicit-sequence pair? list?))
	   (lambda (args body)
	     `(lambda-simple ,args ,(parse (beginify body)))))  ;;;;--->  `(begin body)
      (pattern-rule
	   `(lambda ,(? 'args symbol?)  .,(? 'implicit-sequence pair? list?))
	   (lambda (args body)
	     `(lambda-variadic ,args ,(parse (beginify body)))))  ;;;;--->  `(begin body)
      
      ;;define
      (pattern-rule
	   `(define ,(? 'var symbol?)  ,(? 'implicit-sequence))
	   (lambda (var definition)
	     `(define ,(parse var) ,(parse definition))))
      (pattern-rule
	   `(define ,(? 'var-mit-style mit-style?)  ,(? 'implicit-sequence))
	   (lambda (var definition)
	     `(define ,(parse (car var)) ,(parse (peExpr->lambda (cdr var) definition)))))
      ;;application
      (pattern-rule
	   ;(? 'func func?);
       `(,(? 'proc proc?) .,(? 'args))
	   (lambda (p args)
       `(applic ,(parse p) ,(parse-rest args))))
      ;;begin 
      ;;tal
      (pattern-rule
	   `(begin .,(? 'exprs list?))
	   (lambda (exps)
	    (cond ((null? exps) (parse `,*void-object*))
                  (else `(seq ,(parse-rest exps))))))
       ;;let
      ;;tal
      (pattern-rule
       `(let ,(? 'defs pairs-list?) .,(? 'exprs list? pair?))
       (lambda (defs exprs)
         (parse `((lambda ,(map car defs) .,exprs) .,(map cadr defs)))))
      ;; let*
	  (pattern-rule
	   `(let* () ,(? 'expr) . ,(? 'exprs list?))
	   (lambda (expr exprs)
	     (parse (beginify (cons expr exprs)))))
	  (pattern-rule
	   `(let* ((,(? 'var var?) ,(? 'val)) . ,(? 'rest)) . ,(? 'exprs))
	   (lambda (var val rest exprs)
	     (parse `(let ((,var ,val))
		       (let* ,rest . ,exprs)))))
      ;;letrec
      ;;tal
       (pattern-rule
       `(letrec  ,(? 'defs pairs-list?) .,(? 'exprs list? pair?))
       (lambda (defs exprs)
         (parse (expand-letrec `(letrec ,defs .,exprs) ))))
      ;and
      ;tal
      (pattern-rule
       `(and .,(? 'args list?))
       (lambda (args)
         (cond
           ((null? args) (parse '#t))
           ((null? (cdr args)) (parse `,(car args)))
           (else (parse `(if ,(car args) (and ,@(cdr args)) #f))))))
      ;cond
      ;tal
      (pattern-rule
       `(cond .,(? 'exprs pairs-list?))
       (lambda (exprs)
         (cond
           ((null? exprs) (parse `,*void-object*))
           ((and (eq? 'else (caar exprs))(null? (cdr exprs))) (parse `,(cadar exprs)))
           (else (parse `(if ,(caar exprs) ,(cadar exprs) (cond ,@(cdr exprs))))))))
      ;quasiquote
      ;tal
      (pattern-rule 
       `(,'quasiquote ,(? 'arg)) 
       (lambda (arg) (parse (expand-qq arg))))
      ;or
      (pattern-rule 
       `(or .,(? 'args list?))
       (lambda (args)
         (cond
           ((null? args) (parse '#f))
           ((null? (cdr args)) (parse `,(car args)))
           (else `(or ,(map parse args))))))      
	  )))
    (lambda (e)
      (run e
	   (lambda ()
	     (error 'parse
		    (format "I can't recognize this: ~s" e)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define find-pvar-index
  (lambda (var args res)
    (cond ((null? args) -1)
          ((and (symbol? args) (eq? args var)) res)
          ((and (list? args) (eq? (car args) var)) res)
          (else (find-pvar-index var (cdr args) (+ res 1))))))

(define find-bvar-2indexs 
  (lambda (var env major)
    (cond ((null? env) (cons -1 -1))
          ((and (pair? env) (pair? (car env))) 
                (let ((minor (find-pvar-index var (car env) 0)))
                  (if (>= minor 0) 
                      (cons major minor)
                      (find-bvar-2indexs var (cdr env) (+ major 1)))))
          ((pair? env) 
           (if (eq? (car env) var) 
               (cons major 0)
               (find-bvar-2indexs var (cdr env) (+ major 1)))))))

(define pe->lex-pe
  (lambda (pe)
    (letrec ((run 
              (lambda (pe args env)                        
                (if (null? pe) 
                    pe 
                    (cond 
                      ;const
                      ((and (list? pe) (eq? (car pe) 'const)) pe)
                      ((symbol? pe) pe)
                      ;variable
                      ((and (list? pe)  (eq? (car pe) 'var))    
                       (let ((pval (find-pvar-index (cadr pe) args 0)) 
                             (bval (find-bvar-2indexs (cadr pe) env 0)))
                         (if (>= pval 0) 
                             `(pvar ,(cadr pe) ,pval)
                             (if (and (>= (car bval) 0) (>= (cdr bval) 0))
                                 `(bvar ,(cadr pe) ,(car bval) ,(cdr bval))
                                 `(fvar ,(cadr pe))))))
                      ;lambda
                      ((and (list? pe) (eq? (car pe) 'lambda-simple))
                       (cons (car pe) (cons (cadr pe) (run (cddr pe) `(,@(cadr pe)) `(,args ,@env)))))                                        
                      ((and (list? pe) (eq? (car pe) 'lambda-opt))
                       (cons (car pe) (cons  (cadr pe) (cons (caddr pe) (run (cdddr pe) `(,@(cadr pe) ,(caddr pe)) `(,args ,@env))))))                                
                      ((and (list? pe) (eq? (car pe) 'lambda-variadic))
                       (cons (car pe) (cons (cadr pe) (run (cddr pe) `(,(cadr pe)) `(,args ,@env)))))                                        
                      ((and (list? pe) (eq? (car pe) 'define)) 
                      `(define (fvar ,(cadadr pe)) ,@(run (cddr pe) args env)))                                                                        
                      (else (cons (run (car pe) args env) (run (cdr pe) args env))))))))
      (run pe '() '()))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;---------------------------------------------------- annotate-tc --------------------------------------------------------------------;
(define annotate-tc
	(lambda (pe)
		(run pe #f)))
		
(define pe-seq
	(lambda (args tp?)
          (if (null? (cdr args)) 
              `(,(run (car args) tp?))
              `(,(run (car args) #f) ,@(pe-seq (cdr args) tp?)))))

(define run
  (lambda (pe tp?)
    ;(display "---------------------- annotate-tc ------------------->  ")(display pe)(display "\n")
    (cond
      ;const
      ((eq? (car pe) 'const) 
       ;;(display "add-to-const-table : 'const:  ")(display (cadr pe))(display "\n\n")
       (add-to-const-table (cadr pe)) 
       pe)
      ;var
      ((eq? (car pe) 'var) pe);;;;;;;;;;;;;;;
      ((or (eq? (car pe) 'pvar) (eq? (car pe) 'bvar)) pe)
      ((eq? (car pe) 'fvar)
       ;;(display "add-to-const-table : 'fvar:  ")(display (cadr pe))(display "\n\n")
       ;(add-to-const-table (cadr pe))
       pe)
      ;if
      ((eq? (car pe) 'if3) 
       (with pe
             (lambda (_ test dit dif)
               `(if3 ,(run test #f) ,(run dit tp?) ,(run dif tp?)))))
      ;lambda
      ((eq? (car pe) 'lambda-simple) `(lambda-simple ,(cadr pe) ,(run (caddr pe) #t)))
      ((eq? (car pe) 'lambda-opt) `(lambda-opt ,(cadr pe) ,(caddr pe) , (run (cadddr pe) #t))) 			
      ((eq? (car pe) 'lambda-variadic) `(lambda-variadic ,(cadr pe) , (run (caddr pe) #t)))
      ;applic
      ((eq? (car pe) 'applic)
       (if tp?
           `(tc-applic ,(run (cadr pe) #f) ,(map (lambda (x) (run x #f)) (caddr pe)))
           `(applic ,(run (cadr pe) #f) ,(map (lambda (x) (run x #f)) (caddr pe)))))
      ;define
      ((eq? (car pe) 'define) 
       ;(display "add-to-const-table : 'define:  ")(display (cadadr pe))(display "\n\n")
      ; (add-to-const-table (cadadr pe))
       `(define ,(cadr pe) ,(run (caddr pe) #f)))
      ;or
      ((eq? (car pe) 'or) `(or ,(map (lambda (x) (if (null? (cdr pe)) (run x tp?) (run x #f))) (cadr pe))))
      ;seq
      ((eq? (car pe) 'seq) `(seq ,(pe-seq (cadr pe) tp?)))
      
      (else (error 'annotate-tc_run
                   (format "I can't recognize this: ~s" pe))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;---------------------------------------------------- final compiler --------------------------------------------------------------------;

(define ^^label
  (lambda (name)
    (let ((n 0))
      (lambda ()
        (set! n (+ n 1))
        (string-append name
                       (number->string n))))))



;tal-edit
;if3
(define ^label-if3else (^^label "Lif3else"))
(define ^label-if3exit (^^label "Lif3exit"))
;or
(define ^label-orexit (^^label "Lorexit"))
;lambda-simple
(define ^label-closure-code (^^label "Llsccode"))
(define ^label-closure-exit (^^label "Llscexit"))
(define ^label-lambda-env (^^label "Llsenv"))
(define ^label-lambda-args (^^label "Llsargs"))
;applic
(define ^label-not-closure (^^label "Lanotclosure"))
(define ^label-applic-exit (^^label "Laexit"))
;tc-applic
(define ^label-tc-not-closure (^^label "Ltcanotclosure"))
(define ^label-tc-applic-exit (^^label "Ltcaexit"))
(define ^label-tc-applic-loop (^^label "Ltcaloop"))
(define ^label-tc-applic-loopexit (^^label "Ltcaloopexit"))
;lambda opt
(define ^label-opt-finish (^^label "Loptfinish"))
(define ^label-opt-optparams (^^label "Loptparams"))
(define ^label-opt-afterparams (^^label "Loptaparams"))

;fvar
(define ^label-fvar-exit (^^label "Lfvarexit"))
;next-codegen
(define ^label-next (^^label "Lnext"))
(define nl (list->string (list #\newline)))
(define NL (list->string (list #\newline)))

;---------------------------------------------
;---------------------------------------------------- create const table --------------------------------------------------------------------;
(define T_VOID 	937610)
(define T_NIL 	722689)
(define T_BOOL 	741553)
(define T_CHAR 	181048)
(define T_INTEGER 	945311)
(define T_STRING 	799345)
(define T_SYMBOL 	368031)
(define T_PAIR 	885397)
(define T_VECTOR 	335728)
(define T_CLOSURE 	276405)

(define const-table '())
(define fvar-table '())
(define address 20)

(define init-const-table
  (lambda ()
    (set! const-table (append const-table (list (list address *void-object* `(,T_VOID)))))
    (set! address (+ address 1))
    (set! const-table (append const-table (list (list address '() `(,T_NIL)))))
    (set! address (+ address 1))
    (set! const-table (append const-table (list (list address #f `(,T_BOOL 0)))))
    (set! address (+ address 2))
    (set! const-table (append const-table (list (list address #t `(,T_BOOL 1)))))
    (set! address (+ address 2))
    ""))
    
(define get-const-stack-addr
	(lambda (const c-table)
          (cond ((null? c-table) 0) 
                ((and (not(null? c-table)) (equal? const (cadar c-table))) (caar c-table))
                (else (get-const-stack-addr const (cdr c-table))))))

(define add-to-const-table
  (lambda (pe)
    ;(display "---------------------- add-to-const-table ------------------->  ")(display pe)(display "\n")
    (let ((addr (get-const-stack-addr pe const-table)))
      (if (eq? addr 0)
          (cond ((char? pe) 
                 (set! const-table (append const-table (list (list address pe (append `(,T_CHAR) (list (char->integer pe)))))))
                 (set! address (+ address 2)) "")
                ((number? pe)
                 (set! const-table (append const-table (list (list address pe (append `(,T_INTEGER) (list pe))))))
                 (set! address (+ address 2)) "")
                ((string? pe)
                 (set! const-table (append const-table (list (list address pe (append `(,T_STRING) (list (length (string->list pe))) (make-int-list (string->list pe)))))))
                 (set! address  (+ address 2 (length (string->list pe)))) "")
                ((symbol? pe);----------------------------; symbol==create-void????????????
                 (add-to-const-table (symbol->string pe))
                 (set! const-table (append const-table (list (list address pe (append `(,T_SYMBOL) (list (get-const-stack-addr (symbol->string pe) const-table)))))))
                 (set! address (+ address 2)) "")
                ((pair? pe)
                 ;(set-pair-consts pe)
                 (add-to-const-table (car pe))
                 (add-to-const-table (cdr pe))
                 (set! const-table (append const-table (list (list address pe (append `(,T_PAIR) (list (get-const-stack-addr (car pe) const-table) (get-const-stack-addr (cdr pe) const-table)))))))
                 (set! address (+ address 3)) "")
                ((vector? pe);---------------------------; like string (or like pair???) 
                 ;(set-pair-consts (vector->list pe))
                 (add-to-const-table (car (vector->list pe)))
                 (add-to-const-table (cdr (vector->list pe)))
                 (set! const-table (append const-table (list (list address pe (append `(,T_VECTOR) (list (vector-length pe)) (get-vec-consts pe 0))))))
                 (set! address  (+ address 2 (vector-length pe))) "")
                (else (error 'add-to-const-table (format "I can't recognize this: ~s" pe))))
          ""))))

;for T_STRING 
(define make-int-list
  (lambda (lst)
    (if (null? lst)
        '()
        (append (list (char->integer (car lst))) 
                (make-int-list (cdr lst))))))

;for T_PAIR 
(define set-pair-consts
  (lambda (pe)
    (let ((car-addr (get-const-stack-addr (car pe) const-table))
          (cdr-addr (get-const-stack-addr (cdr pe) const-table)))
      (cond ((and (eq? car-addr 0) (eq? cdr-addr 0))
             (add-to-const-table (car pe))
             (add-to-const-table (cdr pe))"")
            ((and (eq? car-addr 0) (not (eq? cdr-addr 0)))
             (add-to-const-table (car pe))"")
            ((and (not (eq? car-addr 0)) (eq? cdr-addr 0))
             (add-to-const-table (cdr pe))"")
            ((and (not (eq? car-addr 0)) (not (eq? cdr-addr 0)))"")
            (else (error 'set-pair-consts (format "I can't recognize this: ~s" pe)))))))

;for T_VECTOR 
(define get-vec-consts
  (lambda (vec n)
    (if (eq? n (vector-length vec))
        '()
        (append (list (get-const-stack-addr (vector-ref vec n) const-table))
                (get-vec-consts vec (+ n 1))))))
          

;(define sort 
 ; (lambda (e) 
 ;   (cond ((or (number? e) (string? e) (eq? *void-object* e) (null? e) (boolean? e)) `(,e)) 
  ;        ((pair? e) `(,e ,@(sort (car e)) ,@(sort (cdr e)))) 
   ;       ((vector? e) `(,e ,@(apply append (map sort (vector->list e))))) 
    ;      ((symbol? e) `(,e ,@(sort (symbol->string e)))) 
     ;     (else (error 'sort (format "I can't recognize this: ~s" e))))))
;-----------------------------------------------------------------
;---------------------------------------------------- load const table --------------------------------------------------------------------;

(define load-const-table2
  (lambda (c-list)
    (if (null? c-list)
        ""
        (string-append
         (insert-to-memory (car c-list))
         (load-const-table2 (cdr c-list))))))

;(define insert-to-memory
 ; (lambda (const-row)
  ;  (let* ((addr (car const-row))
   ;        (info (caddr const-row))
    ;       (len-info (length info)))
     ; )))
      



(define load-const-table
  (lambda (c-list)
    ;(display "load-const-table  ---------> ")(display 
    
      (if (not (null? c-list))
          (let* ((const-row (car c-list))
                 (addr (car const-row))  ;;1st col
                 (info (caddr const-row))) ;;3rd col
            (cond ((eq? (car info) T_VOID) (string-append "" (load-const-table (cdr c-list))))
                  ((eq? (car info) T_NIL) (string-append "" (load-const-table (cdr c-list))))
                  ((eq? (car info) T_BOOL) (string-append "" (load-const-table (cdr c-list))))
                  ((eq? (car info) T_CHAR) (string-append (create-char-obj addr (cadr info)) (load-const-table (cdr c-list))))
                  ((eq? (car info) T_INTEGER) (string-append (create-int-obj addr (cadr info)) (load-const-table (cdr c-list))))
                  ((eq? (car info) T_STRING) (string-append (create-string-obj addr (cadr info) (cddr info)) (load-const-table (cdr c-list))))
                  ((eq? (car info) T_SYMBOL) (string-append (create-symbol-obj addr (cadr info)) (load-const-table (cdr c-list))))
                  ((eq? (car info) T_PAIR) (string-append (create-pair-obj addr (cadr info) (caddr info)) (load-const-table (cdr c-list))))
                  ((eq? (car info) T_VECTOR) (string-append (create-vec-obj addr (cadr info) (cddr info)) (load-const-table (cdr c-list))))
                  ;((eq? (caar c-list) T_CLOSURE) (string-append (create-closure-obj) (load-const-table (cdr c-list))))
                  (else (error 'load-const-table (format "I can't recognize this: ~s" (car info))))))
          "")))
 
(define create-void-obj
  (lambda ()
    (string-append 
     "/*create void scheme object*/" nl
     "MOV("(number->string (get-const-stack-addr *void-object* const-table)) ",IMM(T_VOID));"
     ;"CALL(MAKE_SOB_VOID);"
    ;  
    ; "MOV(IND(20), IMM(T_VOID))" nl
    ; "#define SOB_VOID 20" nl
     nl nl)))

(define create-null-obj
  (lambda ()
    (string-append 
     "/*create null scheme object*/" nl
     "MOV("(number->string (get-const-stack-addr (list) const-table)) ",IMM(T_NIL));"
    ; "CALL(MAKE_SOB_NIL);"
    ; "MOV(IND(21), IMM(T_NIL));" nl
     ;"#define SOB_NIL 21" nl
     nl nl)))

(define create-boolean-obj
  (lambda (value)
   ; (let ((addr (get-const-stack-addr *void-object* const-table))
    (string-append 
     "/*create boolean scheme object*/" nl
   ;;;;;;;;;;;;;  "MOV("(number->string ) ",IMM(T_BOOL));"
    ; "PUSH(IMM(" (number->string value) "));" nl
     ;"CALL(MAKE_SOB_BOOL); " nl
     ;"DROP(1);" 
    ; "MOV(IND(22), IMM(T_BOOL))" nl
     ;"MOV(IND(23), IMM(0))" nl
      ;"#define SOB_FALSE 22" nl
    ; "MOV(IND(24), IMM(T_BOOL))" nl
     ;"MOV(IND(25), IMM(1))" nl
    
   ;  "#define SOB_TRUE 24" nl
     nl nl)))

(define create-char-obj
  (lambda (addr value)
    ;(let ((addr (get-const-stack-addr value const-table)))
      (string-append 
      ; "/*create char scheme object*/" nl
       "MOV(IND(" (number->string addr) "), IMM(T_CHAR));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string value) "));" nl nl)))
     ;"PUSH(IMM(" (number->string value) "));" nl
     ;"CALL(MAKE_SOB_CHAR); " nl
     ;"DROP(1);" nl nl)))

(define create-int-obj
  (lambda (addr value)
    ;(let ((addr (get-const-stack-addr value const-table)))
      (string-append 
      ; "/*create integer scheme object*/" nl
       "MOV(IND(" (number->string addr) "), IMM(T_INTEGER));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string value) "));" nl nl)))
    ; "PUSH(IMM(" (number->string value) "));" nl
    ; "CALL(MAKE_SOB_INTEGER); " nl
    ; "DROP(1);" nl nl)))

(define create-string-obj
  (lambda (addr size char-list)
    (letrec ((loop
              (lambda (addr2 lst)
                (if (null? lst)
                    ""
                    (string-append 
                     "MOV(IND(" (number->string addr2) "), IMM(" (number->string (car lst)) "));" nl
                     ;"PUSH(IMM(" (number->string (car lst)) "));" nl
                     (loop (+ addr2 1) (cdr lst)))))))
      (string-append 
      ; "/*create string scheme object*/" nl
       "MOV(IND(" (number->string addr) "), IMM(T_STRING));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string size) "));" nl
       (loop (+ addr 2) char-list) nl nl))))
    ;   "PUSH(IMM(" (number->string size) "));" nl
     ;  "CALL(MAKE_SOB_STRING); " nl
      ; "DROP(" (number->string (+ size 1)) ");" nl nl))))

(define create-symbol-obj;;;????????????????????????
  (lambda (addr value)
    (string-append 
    ; "/*create symbol scheme object*/" nl
     "MOV(IND(" (number->string addr) "), IMM(T_SYMBOL));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string value) "));" nl nl)))
  ;   "PUSH(SOB_NIL);" nl
   ;  "CALL(MAKE_SOB_SYMBOL); " nl
    ; "DROP(1);" nl nl)))

(define create-pair-obj
  (lambda (addr car-addr cdr-addr)
    (string-append 
     "MOV(IND(" (number->string addr) "), IMM(T_PAIR));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string car-addr) "));" nl
       "MOV(IND(" (number->string (+ addr 2)) "), IMM(" (number->string cdr-addr) "));" nl nl)))
     ;"/*create pair scheme object*/" nl
    ; "PUSH(IMM(" (number->string car-addr) "));" nl
    ; "PUSH(IMM(" (number->string cdr-addr) "));" nl
     ;"CALL(MAKE_SOB_PAIR); " nl
    ; "DROP(2);" nl nl)))

(define create-vec-obj 
  (lambda (addr size addr-list)
    (letrec ((loop
              (lambda (addr2 lst)
                (if (null? lst)
                    ""
                    (string-append 
                     "MOV(IND(" (number->string addr2) "), IMM(" (number->string (car lst)) "));" nl
                     ;"PUSH(IMM(" (number->string (car lst)) "));" nl
                     (loop (+ addr2 1) (cdr lst)))))))
      (string-append 
      ; "/*create vector scheme object*/" nl
       "MOV(IND(" (number->string addr) "), IMM(T_VECTOR));" nl
       "MOV(IND(" (number->string (+ addr 1)) "), IMM(" (number->string size) "));" nl
       (loop (+ addr 2) addr-list) nl nl))))
    
    
;-------------------------------------------------------------------------------------------------------
;---------------------------------------------------- built in procedures --------------------------------------------------------------------;
(define builtin-proc
  '(apply boolean? car cdr char->integer char? cons eq? integer?
          integer->char make-string make-vector null? number? pair? procedure?
          remainder set-car! set-cdr! string-length string-ref string-set! 
          string->symbol string? symbol? symbol->string vector-length 
          vector-ref vector-set! vector? zero? + - * / < > = ))

(define builtin-proc-labels
  '((apply "APPLY") (boolean? "IS_BOOLEAN") (car "CAR") (cdr "CDR") (char->integer "CHAR_TO_INT") (char? "IS_CHAR") (cons "CONS") (eq? "IS_EQ") (integer? "IS_INT")
          (integer->char "INT_TO_CHAR")  (make-string "MAKE_STRING") (make-vector "MAKE_VECTOR") (null? "IS_NULL") (number? "IS_NUMBER") (pair? "IS_PAIR") (procedure? "IS_PROC")
          (remainder "REMAINDER") (set-car! "SET_CAR") (set-cdr! "SET_CDR") (string-length "STRING_LENGTH") (string-ref "STRING_REF") (string-set! "STRING_SET") 
          (string->symbol "STRING_TO_SYMBOL") (string? "IS_STRING") (symbol? "IS_SYMBOL") (symbol->string "SYMBOL_TO_STRING") (vector-length "VECTOR_LENGTH") 
          (vector-ref "VECTOR_REF") (vector-set! "VECTOR_SET") (vector? "IS_VECTOR") (zero? "IS_ZERO") (+ "OP_PLUS") (- "OP_MINUS") (* "OP_MUL") (/ "OP_DIV") (< "OP_SMALLER")
          (> "OP_BIGGER") (= "OP_EQUAL")))

;(define add-builtin-proc-to-table
 ; (lambda (lst)
  ;  (if (null? lst)
   ;     ""
    ;    (string-append 
     ;    (add-to-const-table (car lst))
      ;   (add-builtin-proc-to-table (cdr lst))))))

;---------------------------------------------------------------------------------------------------
(define get-all-fvars
  (lambda (parsed-expr-list)
    (if (null? parsed-expr-list)
        ""
        (let ((fvar-list (take-if-fvar (car parsed-expr-list))))
          (add-to-fvar-table fvar-list)
          (get-all-fvars (cdr parsed-expr-list))))))
      
(define take-if-fvar
  (lambda (expr)
    ;(display "take-if-fvar-------------------: ")(display expr)(display "\n")
    
    (if (null? expr)
        '()
        (if (pair? (car expr))
                   (if (equal? 'fvar (caar expr))
                       (append (list (cadar expr)) (take-if-fvar (cdr expr)))
                       (append '() (take-if-fvar (car expr)) (take-if-fvar (cdr expr))))
            (append '() (take-if-fvar (cdr expr))))))) 

(define add-to-fvar-table
  (lambda (fvar-list)
    (if (null? fvar-list)
        ""
        (let ((addr (get-const-stack-addr (car fvar-list) fvar-table)))
          (if (eq? addr 0)
              (begin
                (set! fvar-table (append fvar-table (list (list address (car fvar-list)))))
                (set! address (+ address 1)) "")
              "")
          (add-to-fvar-table (cdr fvar-list))))))
 
;---------------------------------------------------- load symbol table --------------------------------------------------------------------;
(define take-if-symbol
  (lambda (lst)
    (if (eq? (caaddr lst) T_SYMBOL)
        #t
        #f)))

(define create-closure-obj
  (lambda (sym-data)
    (if (member (cadr sym-data) builtin-proc);only for built in procedures
        (string-append 
         "/*create closure scheme object for " (symbol->string (cadr sym-data)) " proc*/" nl
         "PUSH(LABEL(" (get-sym-label (cadr sym-data) builtin-proc-labels) "));" nl
         "PUSH(SOB_NIL);" nl
         "CALL(MAKE_SOB_CLOSURE);" nl
         "DROP(2);" nl
         "/*link the second cell in the bucket to the new closure*/" nl
         "PUSH(R0);" nl
         "MOV(R1," (number->string (car sym-data)) ");" nl ;R1 points to symbol address
         "MOV(R2,INDD(R1,1));" nl ;R2 points to bucket address
         "MOV(INDD(R2,1),R0); " nl 
         "POP(R0);" nl nl)
        "")))
;------------------------------------ new: -----------
(define load-bulitin-list
  (lambda (s-list)
    (if (null? s-list)
        ""
        (string-append
         (create-closure-bulitin (car s-list)) nl nl
         (load-bulitin-list (cdr s-list))))))

(define create-closure-bulitin
  (lambda (build-func) ; (apply "APPLY")
        (string-append 
         "/*create closure scheme object for " (symbol->string (car build-func)) " proc*/" nl
         "PUSH(LABEL(" (cadr build-func) ")); /*push the address for the function*/" nl 
         "PUSH(SOB_NIL); /*push the env*/" nl
         "CALL(MAKE_SOB_CLOSURE);" nl
         "DROP(2);" nl
         "/*link the second cell in the bucket to the new closure*/" nl
         "MOV(R1, IMM(" (number->string (get-const-stack-addr (car build-func) fvar-table)) "));" nl
         "MOV(IND(R1),IMM(R0));" nl 
        "")))

(define get-sym-label
  (lambda (sym lst)
    (if (null? lst)
        ""
        (if (equal? sym (caar lst))
            (cadar lst)
            (get-sym-label sym (cdr lst))))))

(define get-all-consts
  (lambda (pe)
    (cond ((not (pair? pe)) '())
          ((eq? (car pe) 'const) (list (cadr pe)))
          ((eq? (car pe) 'applic) (append (get-all-consts (cadr pe)) (get-all-consts (caddr pe))))
          ((eq? (car pe) 'lambda-simple) (get-all-consts (caddr pe)))
          ((eq? (car pe) 'lambda-variadic) (get-all-consts (caddr pe)))
          ((eq? (car pe) 'lambda-opt) (get-all-consts (cadddr pe)))
          ((eq? (car pe) 'if3) (append (get-all-consts (cadr pe)) (get-all-consts (caddr pe)) (get-all-consts (cadddr pe))))
          ((eq? (car pe) 'seq) (map (lambda (x) (get-all-consts x)) (cadr pe)))
          ((list? pe) (map (lambda (x) (get-all-consts x)) pe))
          (else '()))))








;--------------------------------------------------------
;---------------------------------------------------- compile scheme file --------------------------------------------------------------------;
(define create-makefile
  (lambda (out-name)
    (let ((out-port 
           (begin (if (file-exists? "makefile")  (delete-file "makefile") 1)
           (open-output-file "makefile")))
          (out (list->string (reverse (cddr (reverse (string->list out-name)))))))
      (display
       (string-append 
        out": " out".c" nl
        (list->string (list #\tab)) "gcc -o " out " " out ".c" nl
        ".PHONY: clean" nl
        "clean:" nl 
       (list->string (list #\tab)) "rm -f "out) 
       out-port)
       (close-output-port out-port))))


(define compile-scheme-file
  (lambda (in out)
    (if (file-exists? out)  (delete-file out) 1)
    (init-const-table)
    (add-to-fvar-table builtin-proc)
    (create-makefile out) ;;;;;;;;talllllllllllllllllllll!!!!!!!!!!!!!!!!!!!!!!!
    ;(add-builtin-proc-to-table builtin-proc)
    (let* ((out-port (open-output-file out))
           (in-code (file->sexprs in))
           (parsed-in-code (map (lambda(x) (annotate-tc (pe->lex-pe (parse x)))) in-code))
           (code-gen-in (map-cg  parsed-in-code)))
      
      (display
       (string-append
        prologue
        " /********************************** load constant table **********************************/ " nl
        "MOV(ADDR(0),IMM(1000));" nl
        "MOV(IND(20), IMM(T_VOID));" nl
        "MOV(IND(21), IMM(T_NIL));" nl
        "MOV(IND(22), IMM(T_BOOL))" nl
        "MOV(IND(23), IMM(0))" nl
        "MOV(IND(24), IMM(T_BOOL))" nl
        "MOV(IND(25), IMM(1))" nl
        
        (load-const-table const-table)
        " /********************************** load builtin proc **********************************/ " nl
        
        
        (load-bulitin-list builtin-proc-labels)
        (get-all-fvars parsed-in-code)
        
        ;(load-bucket-list (filter take-if-symbol const-table))
        " /********************************** code generation for input file **********************************/ " nl
        code-gen-in
        epilogue) out-port)
      (close-output-port out-port))))

(define append-code
  (lambda (code)
    (if (null? code)
        ""
        (string-append (car code) (append-code (cdr code))))))
          
(define file->sexprs
   (lambda (filename)
     (let ((input (open-input-file filename)))
       (letrec ((run
                 (lambda ()
                   (let ((e (read input)))
                     (if (eof-object? e)
                         (begin (close-input-port input)
                                '())
                         (cons e (run)))))))
         (run)))))

(define map-cg
  (lambda (pe)
    (let ((lnext (^label-next)))
      (if (null? pe)
          ""
          (string-append (code-gen (car pe) 0 0) nl
                         "CMP(R0, SOB_VOID);" nl
                         "JUMP_EQ(" lnext ");" nl
                         "MOV(R15,R0);" NL
                         "PUSH(R0);" nl		
                         "CALL(WRITE_SOB);" nl
                         "DROP (1);" nl
                          "PUSH(IMM(\'\\n\'));" nl
                         "CALL(PUTCHAR);" nl
                         "DROP(1);" nl
                         "MOV(R0, R15);" NL
                         lnext ":" nl
                         (map-cg (cdr pe)))))))
                         
          

(define map-code-gen
	(lambda (p-code)
		(if (null? p-code) 
			""
			(let ((current-pe (car p-code)))
				(string-append (code-gen current-pe 0 0)
								(map-code-gen (cdr p-code)) )))))

;--------------------------------------------------------------------------
;tal-edit
(define prologue
  (string-append
   "#include <stdlib.h>"  nl
   "#include <stdio.h> "  nl
   "#define SOB_VOID  20" nl
   "#define SOB_NIL   21"  nl
   "#define SOB_FALSE 22 " nl
   "#define SOB_TRUE  24 " nl

   "/* change to 0 for no debug info to be printed: */" nl
   "#define DO_SHOW 1" nl

   "/* for debugging only, use SHOW(<msg>, <arg>) */" nl
   "#if DO_SHOW" nl
   "#define SHOW(msg, x) { printf(\"%s %s = %ld\\n\", (msg), (#x), (x)); }" nl
   "#else" nl
   "#define SHOW(msg, x) {}" nl
   "#endif" nl
   "#include \"cisc.h\" " nl
   
   "#include \"debug_macros.h\" " nl
				
   " /*add here  the define of the functions*/ " nl nl
   "int main (){" nl nl
   "START_MACHINE;" nl nl
   "JUMP(CONTINUE);" nl nl
   "void print_stack(char* comment){" nl
   "	int i;" nl
   "	printf(\"printing stack, FP: %d SP: %d %s\\n\", (int)(FP), (int)(SP), comment);" nl
   "	for(i=SP+5; i>=0; --i){" nl
   "		if(SP == i){ "nl
   "			printf(\"SP \"); }" nl
   "		if(FP == i){" nl
   "			printf(\"FP \");}" nl
   "		printf(\"element %d: \", i);" nl		
   "		SHOW(\" \", STACK(i)) ;" nl
   "	}" nl
   "}" nl
				
   "void print_heap(){ " nl
   "	int i; " nl
   "	printf(\"printing heap\\n\"); "nl
   "	for (i=0; i<ADDR(0); i++){ " nl
   "		printf(\"\\t element %d: \", i);" nl
   "		SHOW(\" \",ADDR(i));" nl
   "	}" nl
   "}" nl
   
   "#include \"scheme.lib\"" nl
   "#include \"char.lib\"" nl
   "#include \"io.lib\"" nl
   "#include \"math.lib\"" nl
   "#include \"string.lib\"" nl
   "#include \"system.lib\"" nl nl
   
   "CONTINUE:" nl nl
   
    "/* -----------------------------code----------------------------------------*/" nl
   
   ))
 
(define epilogue
  (string-append
  "/***************************endof code generation for input file **********************************/" nl 
	"Lend: " nl
        "INFO;" nl nl
        "SHOW(\"the value of R0 is: \", R0);" nl nl
	"END_PROG: " nl
	"  STOP_MACHINE;"nl
	"  return 0;" nl
        "}"))
;--------------------------------------------------------

;---------------------------------------------------- code generator --------------------------------------------------------------------;
(define code-gen 
	(lambda (pe env params)
          (cond ((eq? (car pe) 'const) (code-gen-const (cadr pe)))
                ((eq? (car pe) 'pvar) (code-gen-pvar pe env params))
                ((eq? (car pe) 'bvar) (code-gen-bvar pe env params))
                ((eq? (car pe) 'fvar) (code-gen-fvar pe env params))
                ((eq? (car pe) 'if3) (code-gen-if3 pe env params))
                ((eq? (car pe) 'lambda-simple) (code-gen-lambda-simple pe env params))
                ((eq? (car pe) 'lambda-opt) (code-gen-lambda-opt pe env params))
                ((eq? (car pe) 'lambda-variadic) (code-gen-lambda-variadic pe env params))
                ((eq? (car pe) 'applic) (code-gen-applic pe env params))
                ((eq? (car pe) 'tc-applic) (code-gen-applic pe env params))
                ((eq? (car pe) 'define) (code-gen-define pe env params))
                ((eq? (car pe) 'or) (code-gen-or (cadr pe) env params))
                ((eq? (car pe) 'seq) (code-gen-seq (cadr pe) env params))
		     (else (error   'code_gen (format "I can't recognize this: ~s" pe))))))

(define code-gen-if3
  (lambda (e env params)
    (with e
          (lambda (if3 test do-if-true do-if-false)
            (let ((code-test (code-gen test env params))
                  (code-dit (code-gen do-if-true env params))
                  (code-dif (code-gen do-if-false env params))
                  (label-else (^label-if3else))
                  (label-exit (^label-if3exit)))
              (string-append
               code-test nl ; when run, the result of the test will be in R0
               "CMP(R0, SOB_FALSE);" nl
               "JUMP_EQ(" label-else ");" nl
               code-dit nl
               "JUMP(" label-exit ");" nl
               label-else ":" nl
               code-dif nl
               label-exit ":"))))))

(define code-gen-const
	(lambda (const)
          (string-append 
           "/*const*/" nl
           "MOV(R0," 
           (number->string (get-const-stack-addr const const-table)) 
           ");" nl
           "/*endof const*/" nl)))

;tal-edit
 (define code-gen-seq
  (lambda (pe env params)
    (cond ((null? pe) "")
	  ((null? (cdr pe)) (string-append "/* sequence */" nl
					  (code-gen (car pe) env params) nl
					  "/* endof sequence */" nl))
	  (else (string-append "/* sequence */" nl
				(code-gen (car pe) env params) nl
				(code-gen-seq (cdr pe) env params) nl)))))
;tal-edit
(define code-gen-or
  (lambda (pe env params)
    (let ((lexit (^label-orexit)))
    (letrec ((cg-or
	      (lambda (pe env params)
		(if (null? pe)
		  (string-append lexit ":" nl "/* endof or*/" nl)
		  (string-append "/* or */"  nl
				 (code-gen (car pe) env params) nl
				 "CMP(R0, SOB_FALSE);" nl
				 "JUMP_NE(" lexit ");" nl
				 (cg-or (cdr pe) env params))))))
      (cg-or pe env params)))))
      
;tal-edit
;tal-edit-2
(define code-gen-lambda-simple
  (lambda (pe env params)
    (let* ((envsize (+ env 1))
	   (paramsize  (length (cadr pe)))
	   (lcode (^label-closure-code))
	   (lexit (^label-closure-exit))
	   (lenv (^label-lambda-env))
	   (largs (^label-lambda-args))
	   (cg-body (code-gen (caddr pe) envsize paramsize)))
	  (string-append
	    "/* lambda-simple */" nl
	    "PUSH(IMM(" (number->string envsize) "));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R1, R0); /*now R1 contains the new env*/" nl
	    "MOV(R2, FPARG(0)); /*now R2 contains the old env*/" nl
	    "/*now copying the old env to the new one */" nl
	    "MOV(R3, IMM(0)); /*this is i- for the old env*/" nl
	    "MOV(R4, IMM(1)); /*this is j - for the new env*/" nl
	    lenv ":" nl
	    "MOV(INDD(R1, R4), INDD(R2, R3)); /*copying old env elements*/" nl
	    "INCR(R3);" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(" (number->string env) "));" nl
	    "JUMP_LT(" lenv ");" nl
	    "PUSH(IMM(" (number->string paramsize) "));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R3, R0); /*now R3 contains the new args table*/" nl
	    "MOV(R4, IMM(0)); /*this is i - for the args table loop*/" nl
	    largs ":" nl
	    "MOV(INDD(R3, R4), FPARG(2 + R4));" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(" (number->string paramsize) "));" nl
	    "JUMP_LT(" largs ");" nl
	    "MOV(INDD(R1, 0), R3); /*now r1 holds the env*/" nl
	    "/*create the SOB_CLOSURE*/" nl
	    "PUSH(LABEL(" lcode ")); " nl
	    "PUSH(R1); /*now r1 holds the env*/" nl
	    "CALL(MAKE_SOB_CLOSURE); 	/* R10 - the pointer to the new clos */"nl
	    "DROP(2);" NL
	    "JUMP(" lexit ");" nl
	    lcode ": /*closure code*/" nl
	    "PUSH(FP);" nl
	    "MOV(FP,SP);" NL
	    cg-body nl
	    "POP(FP);" NL
	    "RETURN;" nl
	    lexit ":" nl
            "/*endof lambda-simple */" nl))))

(define list-reverse
  (lambda (lst)
    (if (null? lst)
        '()
        (reverse lst))))

(define code-gen-applic-params
  (lambda (params-list env params)
    (if (null? params-list)
        ""
        (string-append (code-gen (car params-list) env params) nl
                       "PUSH(R0);" nl
                       (code-gen-applic-params (cdr params-list) env params)))))

(define code-gen-applic
  (lambda (pe env params)
    (let* ((params-list (list-reverse (caddr pe)))
          (params-num (length (caddr pe)))
          (lnotclosure (^label-not-closure))
          (lexit (^label-applic-exit))
          (cg-params (code-gen-applic-params params-list env params))
          (cg-proc (code-gen (cadr pe) env params)))
      (string-append  "/*applic*/" nl
                      "/*params code*/" nl
                      "PUSH(SOB_NIL); /*MAGIC*/" NL
                      cg-params
                      "/*endof params code*/" nl
                      "PUSH(IMM(" (number->string params-num) ")); /*the number of the parameters*/" nl
                      "/*procedure code*/" nl
                      cg-proc nl
                      "/*endof procedure code*/" nl
                      "CMP(INDD(R0, 0),IMM(T_CLOSURE)); /*make sure we got a closure*/" nl
                      "JUMP_NE(" lnotclosure ");" nl
                      "PUSH(INDD(R0, 1)); /*RO[1] = env*/" nl
                      "CALLA(INDD(R0, 2)); /*R0[2] = function pointer*/" nl
                      "/*cleaning stack*/" nl
                      ;"DROP(IMM(2 + " (number->string params-num) ")); /*dropping the env, params-num and all the pushing of the params code */" nl
                      ;MAGIC correction
                     
                      "DROP(IMM(3 + " (number->string params-num) ")); /*dropping the env, params-num, the MAGIC and all the pushing of the params code */" nl
                      "JUMP(" lexit ");" nl
                      lnotclosure ":" nl
                      "printf(\" ERROR APPLIC - not a closure\");" nl
                      lexit ":" nl
                      "/*endof applic*/" nl))))

(define code-gen-tc-applic
  (lambda (pe env params)
    (let* ((params-list (list-reverse (caddr pe)))
          (params-num (length (caddr pe)))
          (lnotclosure (^label-not-closure))
          (lloop (^label-tc-applic-loop))
          (lloopexit (^label-tc-applic-loopexit))
          (cg-params (code-gen-applic-params params-list env params))
          (cg-proc (code-gen (cadr pe) env params)))
       (string-append  "/*tc-applic*/" nl
                      "/*params code*/" nl
                      "PUSH(SOB_NIL); /*MAGIC*/" NL
                      cg-params
                      "/*endof params code*/" nl
                      "PUSH(IMM(" (number->string params-num) ")); /*the number of the parameters*/" nl
                      "/*procedure code*/" nl
                      cg-proc nl
                      "/*endof procedure code*/" nl
                      "CMP(INDD(R0, 0),IMM(T_CLOSURE)); /*make sure we got a closure*/" nl
                      "JUMP_NE(" lnotclosure ");" nl
                      "MOV(R1, SP); /*SP backup*/" nl
                      "MOV(R2, FP); /*FP backup*/" nl
                      "MOV(R3,FPARG(-2)); /* old FP backup */ " nl
                      "/*calculating the bottom of the prev frame - to R4 */" nl
                      "MOV(R4, SP);" nl
                      ;"SUB(R4, FPARG(1) + 5 + "  (number->string params-num) ");"nl
                      ;MAGIC CORRECTION
                      "SUB(R4, FPARG(1) + 6 + "  (number->string params-num) ");"nl
                      "PUSH(INDD(R0, 1)); /* push the new env */" nl
                      "PUSH(FPARG(-1)); /*push the current frame RA*/" nl
                      "/*moving the last frame*/" nl
                      "SUB(R1, R2);" nl
                      "DECR(R1); /*now contains the frame size*/" nl
                      "MOV(R5, 0);"
                      lloop ":" nl
                      "CMP(R1, R5);" nl
                      "JUMP_LT(" lloopexit ");" nl
                      "MOV(STACK(R4 + R5), STACK(R2 + R5));" nl
                      "INCR(R5);" NL
                      "JUMP(" lloop ");" nl
                      "/*end of moving the last frame*/" nl
                      "/*fixing FP SP*/" nl
                      lloopexit ":"
                      "MOV(SP, R5 + R4); /*new SP = old SP + frame size*/" nl
                      "MOV(FP, R3); /*FP takes the old FP*/" nl
                      "/*now jump to the function*/" NL
                      "JUMPA(INDD(R0, 2));" NL
                      lnotclosure ":" nl
                      "printf(\" ERROR TC-APPLIC - not a closure\");" nl
                      "/*endof tc-applic*/" nl))))

(define code-gen-lambda-opt
  (lambda (pe env params)
    (let* ((envsize (+ env 1))
	   (paramsize (length (cadr pe)))
	   (lcode (^label-closure-code))
	   (lexit (^label-closure-exit))
	   (lenv (^label-lambda-env))
	   (largs (^label-lambda-args))
           (lfinish (^label-opt-finish))
           (loptparams (^label-opt-optparams))
           (lafterparams (^label-opt-afterparams))
           (cg-body (code-gen (cadddr pe) envsize (+ 1 paramsize))))
	  (string-append
	    "/* lambda-opt */" nl
	    "PUSH(IMM(" (number->string envsize) "));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R1, R0); /*now R1 contains the new env*/" nl
	    "MOV(R2, FPARG(0)); /*now R2 contains the old env*/" nl
	    "/*now copying the old env to the new one */" nl
	    "MOV(R3, IMM(0)); /*this is i- for the old env*/" nl
	    "MOV(R4, IMM(1)); /*this is j - for the new env*/" nl
	    lenv ":" nl
	    "MOV(INDD(R1, R4), INDD(R2, R3)); /*copying old env elements*/" nl
	    "INCR(R3);" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(" (number->string env) "));" nl
	    "JUMP_LT(" lenv ");" nl
	    "PUSH(IMM(" (number->string paramsize) "));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R3, R0); /*now R3 contains the new args table*/" nl
	    "MOV(R4, IMM(0)); /*this is i - for the args table loop*/" nl
	    largs ":" nl
	    "MOV(INDD(R3, R4), FPARG(2 + R4));" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(" (number->string paramsize) "));" nl
	    "JUMP_LT(" largs ");" nl
	    "MOV(INDD(R1, 0), R3); /*now r1 holds the env*/" nl
	    "/*create the SOB_CLOSURE*/" nl
	    "PUSH(LABEL(" lcode ")); " nl
	    "PUSH(R1); /*now r1 holds the env*/" nl
	    "CALL(MAKE_SOB_CLOSURE); 	/* R10 - the pointer to the new clos */"nl
	    "DROP(2);" NL
	    "JUMP(" lexit ");" nl
	    lcode ": /*closure code*/" nl
	    "PUSH(FP);" nl
	    "MOV(FP,SP);" NL
            "/*creation of optionals args list*/" nl
            "MOV(R1, FPARG(1)); /* now R1 got the total number of arguments*/" nl
            "SUB(R1, "  (number->string paramsize) "); /*now R1 got the number of opt arguments*/" nl
            "CMP(R1, IMM(0)); /*if there is not opt*/" NL
            "JUMP_EQ(" lfinish ");" nl
            "MOV(R2, 1 + FPARG(1)); /*FPARG(R2) = the last optional arg*/" nl
            "MOV(R3, IMM(0));" NL
            "MOV(R4, SOB_NIL);" NL
            loptparams ":" NL
            "CMP(R3, R1);" NL
            "JUMP_GE(" lafterparams ");" nl
            "PUSH(R4); /*cons cdr*/" NL
            "PUSH(FPARG(R2 - R3)); /*cons car*/" NL
            "CALL(MAKE_SOB_PAIR);" NL
            "DROP(2);" NL
            "MOV(R4, R0);" NL
            "INCR(R3);" NL
            "JUMP(" loptparams ");" NL
            lafterparams ":"
            "/*now R4 - contains the list of the optional arguments */" nl
            "MOV(R3, 2 + " (number->string paramsize) "); /*FPARG(R3) = the first optional arg*/" nl
            "MOV(FPARG(R3), R4); /*put the list of optional args in the place */" nl
            
            lfinish ":" nl
	    cg-body nl
	    "POP(FP);" NL
	    "RETURN;" nl
	    lexit ":" nl
            "/*endof lambda-opt */" nl))))

(define code-gen-lambda-variadic
  (lambda (pe env params)
    (let* ((envsize (+ env 1))
	   (lcode (^label-closure-code))
	   (lexit (^label-closure-exit))
	   (lenv (^label-lambda-env))
	   (largs (^label-lambda-args))
     (lfinish (^label-opt-finish))
     (loptparams (^label-opt-optparams))
     (lafterparams (^label-opt-afterparams))
	   (cg-body (code-gen (caddr pe) envsize 1)))
	  (string-append
	    "/* lambda-variadic */" nl
	    "PUSH(IMM(" (number->string envsize) "));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R1, R0); /*now R1 contains the new env*/" nl
	    "MOV(R2, FPARG(0)); /*now R2 contains the old env*/" nl
	    "/*now copying the old env to the new one */" nl
	    "MOV(R3, IMM(0)); /*this is i- for the old env*/" nl
	    "MOV(R4, IMM(1)); /*this is j - for the new env*/" nl
	    lenv ":" nl
	    "MOV(INDD(R1, R4), INDD(R2, R3)); /*copying old env elements*/" nl
	    "INCR(R3);" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(" (number->string env) "));" nl
	    "JUMP_LT(" lenv ");" nl
	    "PUSH(IMM(FPARG(1)));" nl
	    "CALL(MALLOC);" nl
	    "DROP(1);" nl
	    "MOV(R3, R0); /*now R3 contains the new args table*/" nl
	    "MOV(R4, IMM(0)); /*this is i - for the args table loop*/" nl
	    largs ":" nl
	    "MOV(INDD(R3, R4), FPARG(2 + R4));" nl
	    "INCR(R4);" nl
	    "CMP(R3, IMM(FPARG(1)));" nl
	    "JUMP_LT(" largs ");" nl
	    "MOV(INDD(R1, 0), R3); /*now r1 holds the env*/" nl
	    "/*create the SOB_CLOSURE*/" nl
	    "PUSH(LABEL(" lcode ")); " nl
	    "PUSH(R1); /*now r1 holds the env*/" nl
	    "CALL(MAKE_SOB_CLOSURE); 	/* R10 - the pointer to the new clos */"nl
	    "DROP(2);" NL
	    "JUMP(" lexit ");" nl
	    lcode ": /*closure code*/" nl
	    "PUSH(FP);" nl
	    "MOV(FP,SP);" NL
            "/*creation of optionals args list*/" nl
            "MOV(R1, FPARG(1)); /* now R1 got the total number of arguments*/" nl
            "CMP(R1, IMM(0)); /*if there is no args*/" NL
            "JUMP_EQ(" lfinish ");" nl
            "MOV(R2, 1 + R1); /*FPARG(R2) = the last arg*/" nl
            "MOV(R3, IMM(0));" NL
            "MOV(R4, SOB_NIL);" NL
            loptparams ":" NL
            "CMP(R3, R1);" NL
            "JUMP_GE(" lafterparams ");" nl
            "PUSH(R4); /*cons cdr*/" NL
            "PUSH(FPARG(R2 - R3)); /*cons car*/" NL
            "CALL(MAKE_SOB_PAIR);" NL
            "DROP(2);" NL
            "MOV(R4, R0);" NL
            "INCR(R3);" NL
            "JUMP(" loptparams ");" NL
            lafterparams ":"
            "/*now R4 - contains the list of the optional arguments */" nl
            "MOV(R3, 2); /*FPARG(R3) = the first arg*/" nl
            "MOV(FPARG(R3), R4); /*put the list of optional args in the place */" nl
            lfinish ":" nl
	    cg-body nl
	    "POP(FP);" NL
	    "RETURN;" nl
	    lexit ":" nl
            "/*endof lambda-variadic */" nl))))

(define code-gen-pvar
	(lambda (pe env params)
       (string-append "/*pvar*/" nl
         "/*(number->string (+ 2 (caddr pe))) = " (number->string (+ 2 (caddr pe))) "*/" nl
        "MOV(R0,(FPARG(" (number->string (+ 2 (caddr pe))) ")));" nl
        )))

(define code-gen-bvar
	(lambda (pe env params)
     (string-append "/*bvar*/" nl
      "MOV(R0,FPARG(0));" nl 	
	    "MOV(R0,INDD(R0 ," (number->string (caddr pe)) "));" nl
      "MOV(R0,INDD(R0 ," (number->string (cadddr pe)) "));" nl)))

(define code-gen-fvar ; here we search the symbol in the symbol table and jump to the body of the code 	
	(lambda (pe env params)
	   (string-append
       "/*FVAR*/" NL
      "MOV(R3," (number->string (get-const-stack-addr (cadr pe) fvar-table)) ");" nl
      "MOV(R0, IND(R3)); /*now R0 points to the fvar \"code\" value*/" nl ;now R0 points to the fvar "code" value
      "/*ENDOF FVAR*/" NL)))


(define code-gen-define
	(lambda (pe env params)
       ;   (display "=====================code-gen-define=====================\n")
        ;  (display pe)(display "\n")
         ; (display "=========================================================\n")
       (string-append
        "/*code-gen for the define body:*/" nl
        (code-gen (caddr pe) env params)	nl
        
        "/*link define var - " (symbol->string (cadadr pe)) " to it's body*/" nl
        "MOV(R2," (number->string (get-const-stack-addr (cadadr pe) fvar-table)) "); /*R2 points to symbol address*/" nl
        "MOV(IND(R2), R0); /*put in the memory the code of the body of the define*/" NL
        "MOV(R0, SOB_VOID);" nl)))


