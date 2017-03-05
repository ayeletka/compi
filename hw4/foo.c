/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_VOID 100

#define SOB_NIL 101

#define FALSE 102 

#define TRUE 104 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#define SYMTAB 165

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

PUSH(IMM(165));
CALL(MALLOC);
DROP(1);
PUSH(IMM(0));
PUSH(IMM(0));
PUSH(LABEL(PROG_ENDING));
PUSH(FP);
MOV(FP,SP);

 JUMP(CONTINUE);

#include "arch/char.lib"
#include "arch/io.lib"
#include "arch/math.lib"
#include "arch/string.lib"
#include "arch/system.lib"
#include "arch/scheme.lib"
#include "arch/ours.lib"

ERROR:
HALT;

CONTINUE:

/* ----------initiating const table---------- */
MOV(IND(100), IMM(T_VOID));
MOV(IND(101), IMM(T_NIL));
MOV(IND(102), IMM(T_BOOL));
MOV(IND(103), IMM(0));
MOV(IND(104), IMM(T_BOOL));
MOV(IND(105), IMM(1));
MOV(IND(106), IMM(T_STRING));
MOV(IND(107), IMM(0));
MOV(IND(108), IMM(T_INTEGER));
MOV(IND(109), IMM(0));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(110), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(111), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(112), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(113), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(114), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(115), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(116), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(117), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(118), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(119), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(120), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(121), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(122), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(123), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(124), R0);
PUSH(LABEL(OURS_IS_ZERO));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(125), R0);
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(126), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(127), R0);
PUSH(LABEL(CHAR_2_INTEGER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(128), R0);
PUSH(LABEL(INTEGER_2_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(129), R0);
PUSH(LABEL(STRING_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(130), R0);
PUSH(LABEL(STRING_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(131), R0);
PUSH(LABEL(STRING_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(132), R0);
PUSH(LABEL(MAKE_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(133), R0);
PUSH(LABEL(VECTOR_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(134), R0);
PUSH(LABEL(VECTOR_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(135), R0);
PUSH(LABEL(VECTOR_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(136), R0);
PUSH(LABEL(MAKE_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(137), R0);
PUSH(LABEL(CONS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(138), R0);
PUSH(LABEL(CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(139), R0);
PUSH(LABEL(CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(140), R0);
PUSH(LABEL(SET_CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(141), R0);
PUSH(LABEL(SET_CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(142), R0);
PUSH(LABEL(LIST));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(143), R0);
PUSH(LABEL(VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(144), R0);
PUSH(LABEL(APPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(145), R0);
MOV(IND(146), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(147), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(148), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(149), R0);
MOV(IND(150), IMM(999999));
MOV(IND(151), IMM(999999));
MOV(IND(152), IMM(999999));
MOV(IND(153), IMM(999999));
MOV(IND(154), IMM(999999));
MOV(IND(155), IMM(999999));
MOV(IND(156), IMM(999999));
MOV(IND(157), IMM(999999));
MOV(IND(158), IMM(999999));
MOV(IND(159), IMM(999999));
MOV(IND(160), IMM(999999));
MOV(IND(161), IMM(999999));
MOV(IND(162), IMM(999999));
MOV(IND(163), IMM(999999));
MOV(IND(164), IMM(999999));

/* ----------initiating symbols string linked list---------- */
MOV(IND(165), IMM(0));

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel214:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel213);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel214);
closureEnvLoopEndLabel213: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel216:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel215);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel216);
closureParameterLoopEndLabel215: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel218));
JUMP(closureEndLabel217);
closureBodyLabel218:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(117));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse219);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(117));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit220);
labelElse219:
/*const*/
MOV(R0, IMM(102));

labelIfExit220:

CMP(R0, FALSE);
JUMP_EQ(labelElse262);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(116));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse260);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit261);
labelElse260:
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(116));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse258);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel221:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel222);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel221);
closureParameterLoopEndLabel222:
CMP(R5,R2);
JUMP_GE(greaterLabel224);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel223);
greaterLabel224:
CMP(R5,R2);
JUMP_EQ(equalLabel225);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel223);
equalLabel225:
DROP(R5);
DROP(1);endLabel223:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit259);
labelElse258:
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(116));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse256);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(110));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel226:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel227);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel226);
closureParameterLoopEndLabel227:
CMP(R5,R2);
JUMP_GE(greaterLabel229);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel228);
greaterLabel229:
CMP(R5,R2);
JUMP_EQ(equalLabel230);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel228);
equalLabel230:
DROP(R5);
DROP(1);endLabel228:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit257);
labelElse256:
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(114));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse254);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(150));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel231:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel232);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel231);
closureParameterLoopEndLabel232:
CMP(R5,R2);
JUMP_GE(greaterLabel234);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel233);
greaterLabel234:
CMP(R5,R2);
JUMP_EQ(equalLabel235);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel233);
equalLabel235:
DROP(R5);
DROP(1);endLabel233:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit255);
labelElse254:
/*ifExp*/
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(114));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse236);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(115));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit237);
labelElse236:
/*const*/
MOV(R0, IMM(102));

labelIfExit237:

CMP(R0, FALSE);
JUMP_EQ(labelElse252);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(150));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel238:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel239);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel238);
closureParameterLoopEndLabel239:
CMP(R5,R2);
JUMP_GE(greaterLabel241);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel240);
greaterLabel241:
CMP(R5,R2);
JUMP_EQ(equalLabel242);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel240);
equalLabel242:
DROP(R5);
DROP(1);endLabel240:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit253);
labelElse252:
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(114));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse250);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit251);
labelElse250:
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(115));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse248);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(111));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(150));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel243:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel244);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel243);
closureParameterLoopEndLabel244:
CMP(R5,R2);
JUMP_GE(greaterLabel246);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel245);
greaterLabel246:
CMP(R5,R2);
JUMP_EQ(equalLabel247);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel245);
equalLabel247:
DROP(R5);
DROP(1);endLabel245:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit249);
labelElse248:
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

labelIfExit249:

labelIfExit251:

labelIfExit253:

labelIfExit255:

labelIfExit257:

labelIfExit259:

labelIfExit261:

JUMP(labelIfExit263);
labelElse262:
/*const*/
MOV(R0, IMM(106));

labelIfExit263:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel217:

MOV(IND(IMM(150)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel203:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel202);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel203);
closureEnvLoopEndLabel202: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel205:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel204);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel205);
closureParameterLoopEndLabel204: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel207));
JUMP(closureEndLabel206);
closureBodyLabel207:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel208:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel209);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel208);
closureParameterLoopEndLabel209:
CMP(R5,R2);
JUMP_GE(greaterLabel211);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel210);
greaterLabel211:
CMP(R5,R2);
JUMP_EQ(equalLabel212);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel210);
equalLabel212:
DROP(R5);
DROP(1);endLabel210:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel206:

MOV(IND(IMM(151)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel192:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel191);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel192);
closureEnvLoopEndLabel191: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel194:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel193);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel194);
closureParameterLoopEndLabel193: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel196));
JUMP(closureEndLabel195);
closureBodyLabel196:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel197:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel198);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel197);
closureParameterLoopEndLabel198:
CMP(R5,R2);
JUMP_GE(greaterLabel200);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel199);
greaterLabel200:
CMP(R5,R2);
JUMP_EQ(equalLabel201);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel199);
equalLabel201:
DROP(R5);
DROP(1);endLabel199:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel195:

MOV(IND(IMM(152)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel181:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel180);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel181);
closureEnvLoopEndLabel180: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel183:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel182);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel183);
closureParameterLoopEndLabel182: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel185));
JUMP(closureEndLabel184);
closureBodyLabel185:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel186:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel187);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel186);
closureParameterLoopEndLabel187:
CMP(R5,R2);
JUMP_GE(greaterLabel189);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel188);
greaterLabel189:
CMP(R5,R2);
JUMP_EQ(equalLabel190);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel188);
equalLabel190:
DROP(R5);
DROP(1);endLabel188:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel184:

MOV(IND(IMM(153)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel170:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel169);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel170);
closureEnvLoopEndLabel169: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel172:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel171);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel172);
closureParameterLoopEndLabel171: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel174));
JUMP(closureEndLabel173);
closureBodyLabel174:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel175:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel176);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel175);
closureParameterLoopEndLabel176:
CMP(R5,R2);
JUMP_GE(greaterLabel178);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel177);
greaterLabel178:
CMP(R5,R2);
JUMP_EQ(equalLabel179);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel177);
equalLabel179:
DROP(R5);
DROP(1);endLabel177:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel173:

MOV(IND(IMM(154)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel159:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel158);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel159);
closureEnvLoopEndLabel158: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel161:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel160);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel161);
closureParameterLoopEndLabel160: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel163));
JUMP(closureEndLabel162);
closureBodyLabel163:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel164:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel165);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel164);
closureParameterLoopEndLabel165:
CMP(R5,R2);
JUMP_GE(greaterLabel167);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel166);
greaterLabel167:
CMP(R5,R2);
JUMP_EQ(equalLabel168);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel166);
equalLabel168:
DROP(R5);
DROP(1);endLabel166:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel162:

MOV(IND(IMM(155)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel148:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel147);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel148);
closureEnvLoopEndLabel147: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel150:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel149);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel150);
closureParameterLoopEndLabel149: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel152));
JUMP(closureEndLabel151);
closureBodyLabel152:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel153:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel154);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel153);
closureParameterLoopEndLabel154:
CMP(R5,R2);
JUMP_GE(greaterLabel156);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel155);
greaterLabel156:
CMP(R5,R2);
JUMP_EQ(equalLabel157);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel155);
equalLabel157:
DROP(R5);
DROP(1);endLabel155:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel151:

MOV(IND(IMM(156)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel137:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel136);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel137);
closureEnvLoopEndLabel136: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel139:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel138);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel139);
closureParameterLoopEndLabel138: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel141));
JUMP(closureEndLabel140);
closureBodyLabel141:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel142:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel143);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel142);
closureParameterLoopEndLabel143:
CMP(R5,R2);
JUMP_GE(greaterLabel145);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel144);
greaterLabel145:
CMP(R5,R2);
JUMP_EQ(equalLabel146);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel144);
equalLabel146:
DROP(R5);
DROP(1);endLabel144:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel140:

MOV(IND(IMM(157)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel126:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel125);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel126);
closureEnvLoopEndLabel125: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel128:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel127);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel128);
closureParameterLoopEndLabel127: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel130));
JUMP(closureEndLabel129);
closureBodyLabel130:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel131:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel132);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel131);
closureParameterLoopEndLabel132:
CMP(R5,R2);
JUMP_GE(greaterLabel134);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel133);
greaterLabel134:
CMP(R5,R2);
JUMP_EQ(equalLabel135);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel133);
equalLabel135:
DROP(R5);
DROP(1);endLabel133:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel129:

MOV(IND(IMM(158)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel115:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel114);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel115);
closureEnvLoopEndLabel114: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel117:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel116);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel117);
closureParameterLoopEndLabel116: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel119));
JUMP(closureEndLabel118);
closureBodyLabel119:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel120:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel121);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel120);
closureParameterLoopEndLabel121:
CMP(R5,R2);
JUMP_GE(greaterLabel123);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel122);
greaterLabel123:
CMP(R5,R2);
JUMP_EQ(equalLabel124);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel122);
equalLabel124:
DROP(R5);
DROP(1);endLabel122:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel118:

MOV(IND(IMM(159)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel104:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel103);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel104);
closureEnvLoopEndLabel103: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel106:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel105);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel106);
closureParameterLoopEndLabel105: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel108));
JUMP(closureEndLabel107);
closureBodyLabel108:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel109:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel110);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel109);
closureParameterLoopEndLabel110:
CMP(R5,R2);
JUMP_GE(greaterLabel112);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel111);
greaterLabel112:
CMP(R5,R2);
JUMP_EQ(equalLabel113);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel111);
equalLabel113:
DROP(R5);
DROP(1);endLabel111:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel107:

MOV(IND(IMM(160)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel93:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel92);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel93);
closureEnvLoopEndLabel92: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel95:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel94);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel95);
closureParameterLoopEndLabel94: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel97));
JUMP(closureEndLabel96);
closureBodyLabel97:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel98:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel99);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel98);
closureParameterLoopEndLabel99:
CMP(R5,R2);
JUMP_GE(greaterLabel101);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel100);
greaterLabel101:
CMP(R5,R2);
JUMP_EQ(equalLabel102);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel100);
equalLabel102:
DROP(R5);
DROP(1);endLabel100:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel96:

MOV(IND(IMM(161)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel82:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel81);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel82);
closureEnvLoopEndLabel81: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel84:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel83);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel84);
closureParameterLoopEndLabel83: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel86));
JUMP(closureEndLabel85);
closureBodyLabel86:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel87:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel88);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel87);
closureParameterLoopEndLabel88:
CMP(R5,R2);
JUMP_GE(greaterLabel90);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel89);
greaterLabel90:
CMP(R5,R2);
JUMP_EQ(equalLabel91);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel89);
equalLabel91:
DROP(R5);
DROP(1);endLabel89:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel85:

MOV(IND(IMM(162)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(102));

PUSH(R0);
/*const*/
MOV(R0, IMM(102));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel37:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel36);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel37);
closureEnvLoopEndLabel36: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel39:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel38);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel39);
closureParameterLoopEndLabel38: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel41));
JUMP(closureEndLabel40);
closureBodyLabel41:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/* set-pvar */
/* box-pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));

MOV(IND(R0),FPARG(R10));

MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(FPARG(R10),R0);
MOV(R0,IMM(T_VOID));
/* set-pvar */
/* box-pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));

MOV(IND(R0),FPARG(R10));

MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(FPARG(R10),R0);
MOV(R0,IMM(T_VOID));
/* box-set-pvar */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel69:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel68);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel69);
closureEnvLoopEndLabel68: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel71:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel70);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel71);
closureParameterLoopEndLabel70: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel73));
JUMP(closureEndLabel72);
closureBodyLabel73:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(122));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse79);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit80);
labelElse79:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(138));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel74:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel75);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel74);
closureParameterLoopEndLabel75:
CMP(R5,R2);
JUMP_GE(greaterLabel77);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel76);
greaterLabel77:
CMP(R5,R2);
JUMP_EQ(equalLabel78);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel76);
equalLabel78:
DROP(R5);
DROP(1);endLabel76:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit80:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel72:

MOV(R1, IMM(0));
ADD(R1,IMM(2));
MOV(IND(FPARG(R1)),R0);
/* box-set-pvar */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel56:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel55);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel56);
closureEnvLoopEndLabel55: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel58:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel57);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel58);
closureParameterLoopEndLabel57: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel60));
JUMP(closureEndLabel59);
closureBodyLabel60:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(122));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse66);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit67);
labelElse66:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(1)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel61:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel62);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel61);
closureParameterLoopEndLabel62:
CMP(R5,R2);
JUMP_GE(greaterLabel64);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel63);
greaterLabel64:
CMP(R5,R2);
JUMP_EQ(equalLabel65);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel63);
equalLabel65:
DROP(R5);
DROP(1);endLabel63:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit67:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel59:

MOV(R1, IMM(1));
ADD(R1,IMM(2));
MOV(IND(FPARG(R1)),R0);
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel43:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel42);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel43);
closureEnvLoopEndLabel42: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel45:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel44);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel45);
closureParameterLoopEndLabel44: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel47));
JUMP(closureEndLabel46);
closureBodyLabel47:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
POP(R10);
POP(R11);
POP(R12);
POP(R13);
PUSH(R13);
PUSH(IMM(0));
CALL(LIST);
DROP(IMM(1));
POP(R13);
DROP(R13);
PUSH(R0);
PUSH(IMM(1));
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(122));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse53);
/*const*/
MOV(R0, IMM(101));

JUMP(labelIfExit54);
labelElse53:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* box-get-bvar */
MOV(R1, FPARG(IMM(0)));
MOV(R1,INDD(R1,IMM(0)));
MOV(R1,INDD(R1,IMM(1)));
MOV(R0,IND(R1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel48:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel49);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel48);
closureParameterLoopEndLabel49:
CMP(R5,R2);
JUMP_GE(greaterLabel51);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel50);
greaterLabel51:
CMP(R5,R2);
JUMP_EQ(equalLabel52);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel50);
equalLabel52:
DROP(R5);
DROP(1);endLabel50:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit54:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel46:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel40:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

MOV(IND(IMM(163)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel19:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel18);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel19);
closureEnvLoopEndLabel18: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel21:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel20);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel21);
closureParameterLoopEndLabel20: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel23));
JUMP(closureEndLabel22);
closureBodyLabel23:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(122));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CMP(R0, FALSE);
JUMP_EQ(labelElse34);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* push number of arguments */
PUSH(IMM(0));
/*fvar */
MOV(R0, IND(143));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel24:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel25);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel24);
closureParameterLoopEndLabel25:
CMP(R5,R2);
JUMP_GE(greaterLabel27);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel26);
greaterLabel27:
CMP(R5,R2);
JUMP_EQ(equalLabel28);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel26);
equalLabel28:
DROP(R5);
DROP(1);endLabel26:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit35);
labelElse34:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(140));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(164));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(139));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(138));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel29:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel30);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel29);
closureParameterLoopEndLabel30:
CMP(R5,R2);
JUMP_GE(greaterLabel32);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel31);
greaterLabel32:
CMP(R5,R2);
JUMP_EQ(equalLabel33);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel31);
equalLabel33:
DROP(R5);
DROP(1);endLabel31:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit35:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel22:

MOV(IND(IMM(164)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(104));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel2:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel1);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel2);
closureEnvLoopEndLabel1: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel4:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel3);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel4);
closureParameterLoopEndLabel3: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel6));
JUMP(closureEndLabel5);
closureBodyLabel6:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
POP(R10);
POP(R11);
POP(R12);
POP(R13);
PUSH(R13);
PUSH(IMM(0));
CALL(LIST);
DROP(IMM(1));
POP(R13);
DROP(R13);
PUSH(R0);
PUSH(IMM(1));
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel8:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel7);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel8);
closureEnvLoopEndLabel7: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel10:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel9);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel10);
closureParameterLoopEndLabel9: 
MOV(INDD(R9,IMM(0)),R13);
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel12));
JUMP(closureEndLabel11);
closureBodyLabel12:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
POP(R10);
POP(R11);
POP(R12);
POP(R13);
PUSH(R13);
PUSH(IMM(0));
CALL(LIST);
DROP(IMM(1));
POP(R13);
DROP(R13);
PUSH(R0);
PUSH(IMM(1));
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel11:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));

/*tc-applic specific code starts here */
PUSH(FPARG(-1));
MOV(R1,FPARG(-2));
PUSH(R1);
MOV(R2, FPARG(1));
INCR(R2);
MOV(R3, R2);
INCR(R3);
ADD(R2,IMM(4));
MOV(R4,STARG(2));
ADD(R4,IMM(3));
MOV(R5, R4);
ADD(R5,IMM(2));
/* loop over frame, R6 <- running indx */
MOV(R6, IMM(0));
closureParameterLoopLabel13:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel14);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel13);
closureParameterLoopEndLabel14:
CMP(R5,R2);
JUMP_GE(greaterLabel16);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel15);
greaterLabel16:
CMP(R5,R2);
JUMP_EQ(equalLabel17);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel15);
equalLabel17:
DROP(R5);
DROP(1);endLabel15:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel5:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

CALL(PRINT_R0);


PROG_ENDING: 
  MOV(SP,FP);
  POP(FP);
  STOP_MACHINE;
  return 0;
}
