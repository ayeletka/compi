#include <stdlib.h>
#include <stdio.h> 
#define SOB_VOID  20
#define SOB_NIL   21
#define SOB_FALSE 22 
#define SOB_TRUE  24 
/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1
/* for debugging only, use SHOW(<msg>, <arg>) */
#if DO_SHOW
#define SHOW(msg, x) { printf("%s %s = %ld\n", (msg), (#x), (x)); }
#else
#define SHOW(msg, x) {}
#endif
#include "cisc.h" 
#include "debug_macros.h" 
 /*add here  the define of the functions*/ 

int main (){

START_MACHINE;

JUMP(CONTINUE);

void print_stack(char* comment){
	int i;
	printf("printing stack, FP: %d SP: %d %s\n", (int)(FP), (int)(SP), comment);
	for(i=SP+5; i>=0; --i){
		if(SP == i){ 
			printf("SP "); }
		if(FP == i){
			printf("FP ");}
		printf("element %d: ", i);
		SHOW(" ", STACK(i)) ;
	}
}
void print_heap(){ 
	int i; 
	printf("printing heap\n"); 
	for (i=0; i<ADDR(0); i++){ 
		printf("\t element %d: ", i);
		SHOW(" ",ADDR(i));
	}
}
#include "scheme.lib"
#include "char.lib"
#include "io.lib"
#include "math.lib"
#include "string.lib"
#include "system.lib"

CONTINUE:

/* -----------------------------code----------------------------------------*/
 /********************************** load constant table **********************************/ 
MOV(ADDR(0),IMM(1000));
MOV(IND(20), IMM(T_VOID));
MOV(IND(21), IMM(T_NIL));
MOV(IND(22), IMM(T_BOOL))
MOV(IND(23), IMM(0))
MOV(IND(24), IMM(T_BOOL))
MOV(IND(25), IMM(1))
MOV(IND(64), IMM(T_INTEGER));
MOV(IND(65), IMM(5));

 /********************************** load builtin proc **********************************/ 
/*create closure scheme object for apply proc*/
PUSH(LABEL(APPLY)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(26));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for boolean? proc*/
PUSH(LABEL(IS_BOOLEAN)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(27));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for car proc*/
PUSH(LABEL(CAR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(28));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for cdr proc*/
PUSH(LABEL(CDR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(29));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for char->integer proc*/
PUSH(LABEL(CHAR_TO_INT)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(30));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for char? proc*/
PUSH(LABEL(IS_CHAR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(31));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for cons proc*/
PUSH(LABEL(CONS)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(32));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for eq? proc*/
PUSH(LABEL(IS_EQ)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(33));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for integer? proc*/
PUSH(LABEL(IS_INT)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(34));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for integer->char proc*/
PUSH(LABEL(INT_TO_CHAR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(35));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for make-string proc*/
PUSH(LABEL(MAKE_STRING)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(36));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for make-vector proc*/
PUSH(LABEL(MAKE_VECTOR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(37));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for null? proc*/
PUSH(LABEL(IS_NULL)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(38));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for number? proc*/
PUSH(LABEL(IS_NUMBER)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(39));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for pair? proc*/
PUSH(LABEL(IS_PAIR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(40));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for procedure? proc*/
PUSH(LABEL(IS_PROC)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(41));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for remainder proc*/
PUSH(LABEL(REMAINDER)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(42));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for set-car! proc*/
PUSH(LABEL(SET_CAR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(43));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for set-cdr! proc*/
PUSH(LABEL(SET_CDR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(44));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for string-length proc*/
PUSH(LABEL(STRING_LENGTH)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(45));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for string-ref proc*/
PUSH(LABEL(STRING_REF)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(46));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for string-set! proc*/
PUSH(LABEL(STRING_SET)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(47));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for string->symbol proc*/
PUSH(LABEL(STRING_TO_SYMBOL)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(48));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for string? proc*/
PUSH(LABEL(IS_STRING)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(49));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for symbol? proc*/
PUSH(LABEL(IS_SYMBOL)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(50));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for symbol->string proc*/
PUSH(LABEL(SYMBOL_TO_STRING)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(51));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for vector-length proc*/
PUSH(LABEL(VECTOR_LENGTH)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(52));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for vector-ref proc*/
PUSH(LABEL(VECTOR_REF)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(53));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for vector-set! proc*/
PUSH(LABEL(VECTOR_SET)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(54));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for vector? proc*/
PUSH(LABEL(IS_VECTOR)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(55));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for zero? proc*/
PUSH(LABEL(IS_ZERO)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(56));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for + proc*/
PUSH(LABEL(OP_PLUS)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(57));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for - proc*/
PUSH(LABEL(OP_MINUS)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(58));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for * proc*/
PUSH(LABEL(OP_MUL)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(59));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for / proc*/
PUSH(LABEL(OP_DIV)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(60));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for < proc*/
PUSH(LABEL(OP_SMALLER)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(61));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for > proc*/
PUSH(LABEL(OP_BIGGER)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(62));
MOV(IND(R1),IMM(R0));


/*create closure scheme object for = proc*/
PUSH(LABEL(OP_EQUAL)); /*push the address for the function*/
PUSH(SOB_NIL); /*push the env*/
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
MOV(R1, IMM(63));
MOV(IND(R1),IMM(R0));


 /********************************** code generation for input file **********************************/ 
/*code-gen for the define body:*/
/*const*/
MOV(R0,64);
/*endof const*/

/*link define var - a to it's body*/
MOV(R2,0); /*R2 points to symbol address*/
MOV(IND(R2), R0); /*put in the memory the code of the body of the define*/
MOV(R0, SOB_VOID);

CMP(R0, SOB_VOID);
JUMP_EQ(Lnext1);
MOV(R15,R0);
PUSH(R0);
CALL(WRITE_SOB);
DROP (1);
PUSH(IMM('\n'));
CALL(PUTCHAR);
DROP(1);
MOV(R0, R15);
Lnext1:
/*FVAR*/
MOV(R3,0);
MOV(R0, IND(R3)); /*now R0 points to the fvar "code" value*/
/*ENDOF FVAR*/

CMP(R0, SOB_VOID);
JUMP_EQ(Lnext2);
MOV(R15,R0);
PUSH(R0);
CALL(WRITE_SOB);
DROP (1);
PUSH(IMM('\n'));
CALL(PUTCHAR);
DROP(1);
MOV(R0, R15);
Lnext2:
/***************************endof code generation for input file **********************************/
Lend: 
INFO;

SHOW("the value of R0 is: ", R0);

END_PROG: 
  STOP_MACHINE;
  return 0;
}