/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 102 

#define TRUE 104 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#define SYMTAB 176

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

PUSH(IMM(176));
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
MOV(IND(103), IMM(1));
MOV(IND(104), IMM(T_BOOL));
MOV(IND(105), IMM(1));
MOV(IND(106), IMM(T_INTEGER));
MOV(IND(107), IMM(4));
MOV(IND(108), IMM(T_INTEGER));
MOV(IND(109), IMM(5));
MOV(IND(110), IMM(T_PAIR));
MOV(IND(111), IMM(108));
MOV(IND(112), IMM(101));
MOV(IND(113), IMM(T_PAIR));
MOV(IND(114), IMM(106));
MOV(IND(115), IMM(110));
MOV(IND(116), IMM(T_STRING));
MOV(IND(117), IMM(0));
MOV(IND(118), IMM(T_INTEGER));
MOV(IND(119), IMM(2));
MOV(IND(162), IMM(T_VOID));
MOV(IND(163), IMM(T_NIL));
MOV(IND(164), IMM(T_BOOL));
MOV(IND(165), IMM(1));
MOV(IND(166), IMM(T_BOOL));
MOV(IND(167), IMM(1));
MOV(IND(168), IMM(T_INTEGER));
MOV(IND(169), IMM(5));
MOV(IND(170), IMM(T_INTEGER));
MOV(IND(171), IMM(1));
MOV(IND(172), IMM(T_STRING));
MOV(IND(173), IMM(0));
MOV(IND(174), IMM(T_INTEGER));
MOV(IND(175), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(120), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(121), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(122), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(123), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(124), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(125), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(126), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(127), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(128), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(129), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(130), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(131), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(132), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(133), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(134), R0);
PUSH(LABEL(OURS_IS_ZERO));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(135), R0);
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(136), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(137), R0);
PUSH(LABEL(CHAR_2_INTEGER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(138), R0);
PUSH(LABEL(INTEGER_2_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(139), R0);
PUSH(LABEL(STRING_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(140), R0);
PUSH(LABEL(STRING_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(141), R0);
PUSH(LABEL(STRING_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(142), R0);
PUSH(LABEL(MAKE_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(143), R0);
PUSH(LABEL(VECTOR_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(144), R0);
PUSH(LABEL(VECTOR_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(145), R0);
PUSH(LABEL(VECTOR_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(146), R0);
PUSH(LABEL(MAKE_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(147), R0);
PUSH(LABEL(CONS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(148), R0);
PUSH(LABEL(CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(149), R0);
PUSH(LABEL(CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(150), R0);
PUSH(LABEL(SET_CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(151), R0);
PUSH(LABEL(SET_CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(152), R0);
MOV(IND(153), IMM(999999));
PUSH(LABEL(VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(154), R0);
MOV(IND(155), IMM(999999));
MOV(IND(156), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(157), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(158), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(159), R0);
MOV(IND(160), IMM(999999));
MOV(IND(161), IMM(999999));

/* ----------initiating symbols string linked list---------- */
MOV(IND(176), IMM(0));

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
closureEnvLoopLabel141:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel140);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel141);
closureEnvLoopEndLabel140: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel143:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel142);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel143);
closureParameterLoopEndLabel142: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel145));
JUMP(closureEndLabel144);
closureBodyLabel145:
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
MOV(R0, IND(127));
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
JUMP_EQ(labelElse148);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(118));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(127));
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
JUMP_EQ(labelElse146);
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
MOV(R0, IND(124));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit147);
labelElse146:
/*const*/
MOV(R0, IMM(102));

labelIfExit147:

JUMP(labelIfExit149);
labelElse148:
/*const*/
MOV(R0, IMM(102));

labelIfExit149:

CMP(R0, FALSE);
JUMP_EQ(labelElse159);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit160);
labelElse159:
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
MOV(R0, IND(127));
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
JUMP_EQ(labelElse150);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(101));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(118));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(127));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit151);
labelElse150:
/*const*/
MOV(R0, IMM(102));

labelIfExit151:

CMP(R0, FALSE);
JUMP_EQ(labelElse157);
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
MOV(R0, IND(121));
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
MOV(R0, IND(160));
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
closureParameterLoopLabel152:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel153);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel152);
closureParameterLoopEndLabel153:
CMP(R5,R2);
JUMP_GE(greaterLabel155);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel154);
greaterLabel155:
CMP(R5,R2);
JUMP_EQ(equalLabel156);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel154);
equalLabel156:
DROP(R5);
DROP(1);endLabel154:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit158);
labelElse157:
/*const*/
MOV(R0, IMM(116));

labelIfExit158:

labelIfExit160:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel144:

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
closureEnvLoopLabel131:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel130);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel131);
closureEnvLoopEndLabel130: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel133:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel132);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel133);
closureParameterLoopEndLabel132: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel135));
JUMP(closureEndLabel134);
closureBodyLabel135:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
/* pop old fp */
POP(R10);
/* pop return address */
POP(R11);
/* pop env */
POP(R12);
/* pop number of arguments */
POP(R13);

/* no params */
CMP(R13,IMM(0));
JUMP_EQ(noParamsLabel136);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel138:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel139);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel138);closureParameterLoopEndLabel139:
DROP(R13);
JUMP(EndLabel137);

noParamsLabel136:
MOV(R1, 101)
MOV(FPARG(IMM(1)),R1);
EndLabel137:
PUSH(R13);
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* code-gen on body */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel134:

MOV(IND(IMM(153)),IMM(R0));
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
closureEnvLoopLabel118:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel117);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel118);
closureEnvLoopEndLabel117: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel120:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel119);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel120);
closureParameterLoopEndLabel119: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel122));
JUMP(closureEndLabel121);
closureBodyLabel122:
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
MOV(R0, IND(132));
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
JUMP_EQ(labelElse128);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit129);
labelElse128:
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
MOV(R0, IND(150));
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
MOV(R0, IND(149));
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
MOV(R0, IND(148));
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
closureParameterLoopLabel123:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel124);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel123);
closureParameterLoopEndLabel124:
CMP(R5,R2);
JUMP_GE(greaterLabel126);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel125);
greaterLabel126:
CMP(R5,R2);
JUMP_EQ(equalLabel127);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel125);
equalLabel127:
DROP(R5);
DROP(1);endLabel125:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit129:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel121:

MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(IND(R10),R0);
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
closureEnvLoopLabel105:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel104);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel105);
closureEnvLoopEndLabel104: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel107:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel106);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel107);
closureParameterLoopEndLabel106: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel109));
JUMP(closureEndLabel108);
closureBodyLabel109:
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
MOV(R0, IND(132));
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
JUMP_EQ(labelElse115);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit116);
labelElse115:
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
MOV(R0, IND(150));
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
MOV(R0, IND(149));
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
closureParameterLoopLabel110:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel111);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel110);
closureParameterLoopEndLabel111:
CMP(R5,R2);
JUMP_GE(greaterLabel113);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel112);
greaterLabel113:
CMP(R5,R2);
JUMP_EQ(equalLabel114);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel112);
equalLabel114:
DROP(R5);
DROP(1);endLabel112:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit116:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel108:

MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(IND(R10),R0);
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
closureEnvLoopLabel88:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel87);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel88);
closureEnvLoopEndLabel87: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel90:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel89);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel90);
closureParameterLoopEndLabel89: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel92));
JUMP(closureEndLabel91);
closureBodyLabel92:
PUSH(FP);
MOV(FP,SP);
/* lambda var body */
/* pop old fp */
POP(R10);
/* pop return address */
POP(R11);
/* pop env */
POP(R12);
/* pop number of arguments */
POP(R13);

/* no params */
CMP(R13,IMM(0));
JUMP_EQ(noParamsLabel93);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel95:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel96);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel95);closureParameterLoopEndLabel96:
DROP(R13);
JUMP(EndLabel94);

noParamsLabel93:
MOV(R1, 101)
MOV(FPARG(IMM(1)),R1);
EndLabel94:
PUSH(R13);
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
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
MOV(R0, IND(132));
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
JUMP_EQ(labelElse102);
/*const*/
MOV(R0, IMM(101));

JUMP(labelIfExit103);
labelElse102:
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
MOV(R0, IND(150));
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
MOV(R0, IND(149));
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
closureParameterLoopLabel97:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel98);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel97);
closureParameterLoopEndLabel98:
CMP(R5,R2);
JUMP_GE(greaterLabel100);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel99);
greaterLabel100:
CMP(R5,R2);
JUMP_EQ(equalLabel101);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel99);
equalLabel101:
DROP(R5);
DROP(1);endLabel99:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit103:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel91:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel85:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

MOV(IND(IMM(161)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

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
/*const*/
MOV(R0, IMM(118));

PUSH(R0);
/*const*/
MOV(R0, IMM(118));

PUSH(R0);
/*const*/
MOV(R0, IMM(170));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(120));
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
/*const*/
MOV(R0, IMM(108));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(121));
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
MOV(R0, IND(135));
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
