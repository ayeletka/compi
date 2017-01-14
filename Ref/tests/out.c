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
MOV(ADDR(0),IMM(20));
/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(97));
PUSH(IMM(112));
PUSH(IMM(112));
PUSH(IMM(108));
PUSH(IMM(121));
PUSH(IMM(5));
CALL(MAKE_SOB_STRING); 
DROP(6);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(98));
PUSH(IMM(111));
PUSH(IMM(111));
PUSH(IMM(108));
PUSH(IMM(101));
PUSH(IMM(97));
PUSH(IMM(110));
PUSH(IMM(63));
PUSH(IMM(8));
CALL(MAKE_SOB_STRING); 
DROP(9);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(99));
PUSH(IMM(97));
PUSH(IMM(114));
PUSH(IMM(3));
CALL(MAKE_SOB_STRING); 
DROP(4);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(99));
PUSH(IMM(100));
PUSH(IMM(114));
PUSH(IMM(3));
CALL(MAKE_SOB_STRING); 
DROP(4);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(99));
PUSH(IMM(104));
PUSH(IMM(97));
PUSH(IMM(114));
PUSH(IMM(45));
PUSH(IMM(62));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(116));
PUSH(IMM(101));
PUSH(IMM(103));
PUSH(IMM(101));
PUSH(IMM(114));
PUSH(IMM(13));
CALL(MAKE_SOB_STRING); 
DROP(14);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(99));
PUSH(IMM(104));
PUSH(IMM(97));
PUSH(IMM(114));
PUSH(IMM(63));
PUSH(IMM(5));
CALL(MAKE_SOB_STRING); 
DROP(6);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(99));
PUSH(IMM(111));
PUSH(IMM(110));
PUSH(IMM(115));
PUSH(IMM(4));
CALL(MAKE_SOB_STRING); 
DROP(5);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(101));
PUSH(IMM(113));
PUSH(IMM(63));
PUSH(IMM(3));
CALL(MAKE_SOB_STRING); 
DROP(4);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(116));
PUSH(IMM(101));
PUSH(IMM(103));
PUSH(IMM(101));
PUSH(IMM(114));
PUSH(IMM(63));
PUSH(IMM(8));
CALL(MAKE_SOB_STRING); 
DROP(9);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(116));
PUSH(IMM(101));
PUSH(IMM(103));
PUSH(IMM(101));
PUSH(IMM(114));
PUSH(IMM(45));
PUSH(IMM(62));
PUSH(IMM(99));
PUSH(IMM(104));
PUSH(IMM(97));
PUSH(IMM(114));
PUSH(IMM(13));
CALL(MAKE_SOB_STRING); 
DROP(14);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(109));
PUSH(IMM(97));
PUSH(IMM(107));
PUSH(IMM(101));
PUSH(IMM(45));
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(11));
CALL(MAKE_SOB_STRING); 
DROP(12);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(109));
PUSH(IMM(97));
PUSH(IMM(107));
PUSH(IMM(101));
PUSH(IMM(45));
PUSH(IMM(118));
PUSH(IMM(101));
PUSH(IMM(99));
PUSH(IMM(116));
PUSH(IMM(111));
PUSH(IMM(114));
PUSH(IMM(11));
CALL(MAKE_SOB_STRING); 
DROP(12);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(110));
PUSH(IMM(117));
PUSH(IMM(108));
PUSH(IMM(108));
PUSH(IMM(63));
PUSH(IMM(5));
CALL(MAKE_SOB_STRING); 
DROP(6);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(110));
PUSH(IMM(117));
PUSH(IMM(109));
PUSH(IMM(98));
PUSH(IMM(101));
PUSH(IMM(114));
PUSH(IMM(63));
PUSH(IMM(7));
CALL(MAKE_SOB_STRING); 
DROP(8);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(112));
PUSH(IMM(97));
PUSH(IMM(105));
PUSH(IMM(114));
PUSH(IMM(63));
PUSH(IMM(5));
CALL(MAKE_SOB_STRING); 
DROP(6);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(112));
PUSH(IMM(114));
PUSH(IMM(111));
PUSH(IMM(99));
PUSH(IMM(101));
PUSH(IMM(100));
PUSH(IMM(117));
PUSH(IMM(114));
PUSH(IMM(101));
PUSH(IMM(63));
PUSH(IMM(10));
CALL(MAKE_SOB_STRING); 
DROP(11);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(114));
PUSH(IMM(101));
PUSH(IMM(109));
PUSH(IMM(97));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(100));
PUSH(IMM(101));
PUSH(IMM(114));
PUSH(IMM(9));
CALL(MAKE_SOB_STRING); 
DROP(10);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(101));
PUSH(IMM(116));
PUSH(IMM(45));
PUSH(IMM(99));
PUSH(IMM(97));
PUSH(IMM(114));
PUSH(IMM(33));
PUSH(IMM(8));
CALL(MAKE_SOB_STRING); 
DROP(9);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(101));
PUSH(IMM(116));
PUSH(IMM(45));
PUSH(IMM(99));
PUSH(IMM(100));
PUSH(IMM(114));
PUSH(IMM(33));
PUSH(IMM(8));
CALL(MAKE_SOB_STRING); 
DROP(9);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(45));
PUSH(IMM(108));
PUSH(IMM(101));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(116));
PUSH(IMM(104));
PUSH(IMM(13));
CALL(MAKE_SOB_STRING); 
DROP(14);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(45));
PUSH(IMM(114));
PUSH(IMM(101));
PUSH(IMM(102));
PUSH(IMM(10));
CALL(MAKE_SOB_STRING); 
DROP(11);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(45));
PUSH(IMM(115));
PUSH(IMM(101));
PUSH(IMM(116));
PUSH(IMM(33));
PUSH(IMM(11));
CALL(MAKE_SOB_STRING); 
DROP(12);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(45));
PUSH(IMM(62));
PUSH(IMM(115));
PUSH(IMM(121));
PUSH(IMM(109));
PUSH(IMM(98));
PUSH(IMM(111));
PUSH(IMM(108));
PUSH(IMM(14));
CALL(MAKE_SOB_STRING); 
DROP(15);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(63));
PUSH(IMM(7));
CALL(MAKE_SOB_STRING); 
DROP(8);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(121));
PUSH(IMM(109));
PUSH(IMM(98));
PUSH(IMM(111));
PUSH(IMM(108));
PUSH(IMM(63));
PUSH(IMM(7));
CALL(MAKE_SOB_STRING); 
DROP(8);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(115));
PUSH(IMM(121));
PUSH(IMM(109));
PUSH(IMM(98));
PUSH(IMM(111));
PUSH(IMM(108));
PUSH(IMM(45));
PUSH(IMM(62));
PUSH(IMM(115));
PUSH(IMM(116));
PUSH(IMM(114));
PUSH(IMM(105));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(14));
CALL(MAKE_SOB_STRING); 
DROP(15);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(118));
PUSH(IMM(101));
PUSH(IMM(99));
PUSH(IMM(116));
PUSH(IMM(111));
PUSH(IMM(114));
PUSH(IMM(45));
PUSH(IMM(108));
PUSH(IMM(101));
PUSH(IMM(110));
PUSH(IMM(103));
PUSH(IMM(116));
PUSH(IMM(104));
PUSH(IMM(13));
CALL(MAKE_SOB_STRING); 
DROP(14);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(118));
PUSH(IMM(101));
PUSH(IMM(99));
PUSH(IMM(116));
PUSH(IMM(111));
PUSH(IMM(114));
PUSH(IMM(45));
PUSH(IMM(114));
PUSH(IMM(101));
PUSH(IMM(102));
PUSH(IMM(10));
CALL(MAKE_SOB_STRING); 
DROP(11);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(118));
PUSH(IMM(101));
PUSH(IMM(99));
PUSH(IMM(116));
PUSH(IMM(111));
PUSH(IMM(114));
PUSH(IMM(45));
PUSH(IMM(115));
PUSH(IMM(101));
PUSH(IMM(116));
PUSH(IMM(33));
PUSH(IMM(11));
CALL(MAKE_SOB_STRING); 
DROP(12);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create string scheme object*/
PUSH(IMM(118));
PUSH(IMM(101));
PUSH(IMM(99));
PUSH(IMM(116));
PUSH(IMM(111));
PUSH(IMM(114));
PUSH(IMM(63));
PUSH(IMM(7));
CALL(MAKE_SOB_STRING); 
DROP(8);

/*create symbol scheme object*/
PUSH(SOB_NIL);
CALL(MAKE_SOB_SYMBOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create void scheme object*/
CALL(MAKE_SOB_VOID);

/*create null scheme object*/
CALL(MAKE_SOB_NIL);

/*create boolean scheme object*/
PUSH(IMM(0));
CALL(MAKE_SOB_BOOL); 
DROP(1);

/*create boolean scheme object*/
PUSH(IMM(1));
CALL(MAKE_SOB_BOOL); 
DROP(1);

 /********************************** create buckets for symbol table **********************************/ 
/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,26);  /* R0 point to string - apply */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,33); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for apply proc*/
PUSH(LABEL(APPLY));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,33);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,35);  /* R0 point to string - boolean? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,45); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for boolean? proc*/
PUSH(LABEL(IS_BOOLEAN));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,45);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,47);  /* R0 point to string - car */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,52); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for car proc*/
PUSH(LABEL(CAR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,52);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,54);  /* R0 point to string - cdr */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,59); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for cdr proc*/
PUSH(LABEL(CDR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,59);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,61);  /* R0 point to string - char->integer */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,76); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for char->integer proc*/
PUSH(LABEL(CHAR_TO_INT));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,76);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,78);  /* R0 point to string - char? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,85); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for char? proc*/
PUSH(LABEL(IS_CHAR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,85);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,87);  /* R0 point to string - cons */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,93); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for cons proc*/
PUSH(LABEL(CONS));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,93);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,95);  /* R0 point to string - eq? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,100); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for eq? proc*/
PUSH(LABEL(IS_EQ));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,100);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,102);  /* R0 point to string - integer? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,112); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for integer? proc*/
PUSH(LABEL(IS_INT));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,112);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,114);  /* R0 point to string - integer->char */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,129); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for integer->char proc*/
PUSH(LABEL(INT_TO_CHAR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,129);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,131);  /* R0 point to string - make-string */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,144); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for make-string proc*/
PUSH(LABEL(MAKE_STRING));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,144);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,146);  /* R0 point to string - make-vector */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,159); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for make-vector proc*/
PUSH(LABEL(MAKE_VECTOR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,159);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,161);  /* R0 point to string - null? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,168); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for null? proc*/
PUSH(LABEL(IS_NULL));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,168);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,170);  /* R0 point to string - number? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,179); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for number? proc*/
PUSH(LABEL(IS_NUMBER));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,179);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,181);  /* R0 point to string - pair? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,188); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for pair? proc*/
PUSH(LABEL(IS_PAIR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,188);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,190);  /* R0 point to string - procedure? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,202); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for procedure? proc*/
PUSH(LABEL(IS_PROC));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,202);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,204);  /* R0 point to string - remainder */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,215); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for remainder proc*/
PUSH(LABEL(REMAINDER));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,215);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,217);  /* R0 point to string - set-car! */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,227); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for set-car! proc*/
PUSH(LABEL(SET_CAR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,227);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,229);  /* R0 point to string - set-cdr! */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,239); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for set-cdr! proc*/
PUSH(LABEL(SET_CDR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,239);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,241);  /* R0 point to string - string-length */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,256); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for string-length proc*/
PUSH(LABEL(STRING_LENGTH));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,256);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,258);  /* R0 point to string - string-ref */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,270); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for string-ref proc*/
PUSH(LABEL(STRING_REF));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,270);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,272);  /* R0 point to string - string-set! */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,285); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for string-set! proc*/
PUSH(LABEL(STRING_SET));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,285);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,287);  /* R0 point to string - string->symbol */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,303); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for string->symbol proc*/
PUSH(LABEL(STRING_TO_SYMBOL));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,303);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,305);  /* R0 point to string - string? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,314); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for string? proc*/
PUSH(LABEL(IS_STRING));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,314);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,316);  /* R0 point to string - symbol? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,325); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for symbol? proc*/
PUSH(LABEL(IS_SYMBOL));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,325);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,327);  /* R0 point to string - symbol->string */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,343); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for symbol->string proc*/
PUSH(LABEL(SYMBOL_TO_STRING));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,343);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,345);  /* R0 point to string - vector-length */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,360); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for vector-length proc*/
PUSH(LABEL(VECTOR_LENGTH));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,360);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,362);  /* R0 point to string - vector-ref */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,374); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for vector-ref proc*/
PUSH(LABEL(VECTOR_REF));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,374);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,376);  /* R0 point to string - vector-set! */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,389); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for vector-set! proc*/
PUSH(LABEL(VECTOR_SET));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,389);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



/*create bucket scheme object*/
/*first cell in the bucket point to the address of the string of the symbol*/
/*second cell in the bucket point to null (address 21)*/
MOV(R0,391);  /* R0 point to string - vector? */
PUSH(R0);
CALL(MAKE_SOB_BUCKET);
DROP(1);
/*add the new bucket to symbol table (linked list)*/ 
MOV(R1,ADDR(SYMBOL_TABLE));
MOV(INDD(R1,2),R0);
MOV(ADDR(SYMBOL_TABLE),R0);
/*link the symbol to the new bucket*/ 
MOV(R2,400); /* R2 contains the symbol's address */
MOV(INDD(R2,1),R0); 


/*create closure scheme object for vector? proc*/
PUSH(LABEL(IS_VECTOR));
PUSH(SOB_NIL);
CALL(MAKE_SOB_CLOSURE);
DROP(2);
/*link the second cell in the bucket to the new closure*/
PUSH(R0);
MOV(R1,400);
MOV(R2,INDD(R1,1));
MOV(INDD(R2,1),R0); 
POP(R0);



 /********************************** code generation for input file **********************************/ 
INFO;/*applic*/
/*params code*/
PUSH(SOB_NIL); /*MAGIC*/
/*applic*/
/*params code*/
PUSH(SOB_NIL); /*MAGIC*/
MOV(R0,0);

PUSH(R0);
MOV(R0,0);

PUSH(R0);
MOV(R0,0);

PUSH(R0);
/*endof params code*/
PUSH(IMM(3)); /*the number of the parameters*/
/*procedure code*/
/* lambda-variadic */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R1, R0); /*now R1 contains the new env*/
MOV(R2, FPARG(0)); /*now R2 contains the old env*/
/*now copying the old env to the new one */
MOV(R3, IMM(0)); /*this is i- for the old env*/
MOV(R4, IMM(1)); /*this is j - for the new env*/
Llsenv25:
MOV(INDD(R1, R4), INDD(R2, R3)); /*copying old env elements*/
INCR(R3);
INCR(R4);
CMP(R3, IMM(0));
JUMP_LT(Llsenv25);
PUSH(IMM(FPARG(1)));
CALL(MALLOC);
DROP(1);
MOV(R3, R0); /*now R3 contains the new args table*/
MOV(R4, IMM(0)); /*this is i - for the args table loop*/
Llsargs25:
MOV(INDD(R3, R4), FPARG(2 + R4));
INCR(R4);
CMP(R3, IMM(FPARG(1)));
JUMP_LT(Llsargs25);
MOV(INDD(R1, 0), R3); /*now r1 holds the env*/
/*create the SOB_CLOSURE*/
PUSH(LABEL(Llsccode25)); 
PUSH(R1); /*now r1 holds the env*/
CALL(MAKE_SOB_CLOSURE); 	/* R10 - the pointer to the new clos */
DROP(2);
JUMP(Llscexit25);
Llsccode25: /*closure code*/
PUSH(FP);
MOV(FP,SP);
/*creation of optionals args list*/
MOV(R1, FPARG(1)); /* now R1 got the total number of arguments*/
CMP(R1, IMM(0)); /*if there is no args*/
JUMP_EQ(Loptfinish13);
MOV(R2, 1 + R1); /*FPARG(R2) = the last arg*/
MOV(R3, IMM(0));
MOV(R4, SOB_NIL);
Loptparams13:
CMP(R3, R1);
JUMP_GE(Loptaparams13);
PUSH(R4); /*cons cdr*/
PUSH(FPARG(R2 - R3)); /*cons car*/
CALL(MAKE_SOB_PAIR);
DROP(2);
MOV(R4, R0);
INCR(R3);
JUMP(Loptparams13);
Loptaparams13:/*now R4 - contains the list of the optional arguments */
MOV(R3, 2); /*FPARG(R3) = the first arg*/
MOV(FPARG(R3), R4); /*put the list of optional args in the place */
Loptfinish13:
/*applic*/
/*params code*/
PUSH(SOB_NIL); /*MAGIC*/
/*pvar*/
MOV(R0,(FPARG(2)));

PUSH(R0);
/*endof params code*/
PUSH(IMM(1)); /*the number of the parameters*/
/*procedure code*/
MOV(R3,52);
MOV(R0,INDD(R3 ,1));
MOV(R0,INDD(R0,1)); /* R0 contains the potiner to the code of the Fvar */
Lfvarexit13:

/*endof procedure code*/
CMP(INDD(R0, 0),IMM(T_CLOSURE)); /*make sure we got a closure*/
JUMP_NE(Lanotclosure39);
PUSH(INDD(R0, 1)); /*RO[1] = env*/
CALLA(INDD(R0, 2)); /*R0[2] = function pointer*/
/*cleaning stack*/
DROP(IMM(3 + 1)); /*dropping the env, params-num, the MAGIC and all the pushing of the params code */
JUMP(Laexit39);
Lanotclosure39:
printf(" ERROR APPLIC - not a closure");
Laexit39:
/*endof applic*/

POP(FP);
RETURN;
Llscexit25:
/*endof lambda-variadic */

/*endof procedure code*/
CMP(INDD(R0, 0),IMM(T_CLOSURE)); /*make sure we got a closure*/
JUMP_NE(Lanotclosure38);
PUSH(INDD(R0, 1)); /*RO[1] = env*/
CALLA(INDD(R0, 2)); /*R0[2] = function pointer*/
/*cleaning stack*/
DROP(IMM(3 + 3)); /*dropping the env, params-num, the MAGIC and all the pushing of the params code */
JUMP(Laexit38);
Lanotclosure38:
printf(" ERROR APPLIC - not a closure");
Laexit38:
/*endof applic*/

PUSH(R0);
/*endof params code*/
PUSH(IMM(1)); /*the number of the parameters*/
/*procedure code*/
/* lambda-simple */
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R1, R0); /*now R1 contains the new env*/
MOV(R2, FPARG(0)); /*now R2 contains the old env*/
/*now copying the old env to the new one */
MOV(R3, IMM(0)); /*this is i- for the old env*/
MOV(R4, IMM(1)); /*this is j - for the new env*/
Llsenv26:
MOV(INDD(R1, R4), INDD(R2, R3)); /*copying old env elements*/
INCR(R3);
INCR(R4);
CMP(R3, IMM(0));
JUMP_LT(Llsenv26);
PUSH(IMM(1));
CALL(MALLOC);
DROP(1);
MOV(R3, R0); /*now R3 contains the new args table*/
MOV(R4, IMM(0)); /*this is i - for the args table loop*/
Llsargs26:
MOV(INDD(R3, R4), FPARG(2 + R4));
INCR(R4);
CMP(R3, IMM(1));
JUMP_LT(Llsargs26);
MOV(INDD(R1, 0), R3); /*now r1 holds the env*/
/*create the SOB_CLOSURE*/
PUSH(LABEL(Llsccode26)); 
PUSH(R1); /*now r1 holds the env*/
CALL(MAKE_SOB_CLOSURE); 	/* R10 - the pointer to the new clos */
DROP(2);
JUMP(Llscexit26);
Llsccode26: /*closure code*/
PUSH(FP);
MOV(FP,SP);
/*pvar*/
MOV(R0,(FPARG(2)));

POP(FP);
RETURN;
Llscexit26:
/*endof lambda-simple */

/*endof procedure code*/
CMP(INDD(R0, 0),IMM(T_CLOSURE)); /*make sure we got a closure*/
JUMP_NE(Lanotclosure37);
PUSH(INDD(R0, 1)); /*RO[1] = env*/
CALLA(INDD(R0, 2)); /*R0[2] = function pointer*/
/*cleaning stack*/
DROP(IMM(3 + 1)); /*dropping the env, params-num, the MAGIC and all the pushing of the params code */
JUMP(Laexit37);
Lanotclosure37:
printf(" ERROR APPLIC - not a closure");
Laexit37:
/*endof applic*/

CMP(R0,SOB_VOID);
JUMP_EQ(Lnext40);
PUSH(R0);
CALL(WRITE_SOB);
DROP (1);
PUSH(IMM('\n'));
CALL(PUTCHAR);
DROP(1);
Lnext40:
/***************************endof code generation for input file **********************************/
Lend: 
INFO;
END_PROG: 
  STOP_MACHINE;
  return 0;
}