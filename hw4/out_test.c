/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 3 

#define TRUE 5 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#define SYMTAB 67

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

PUSH(IMM(67));
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
MOV(IND(1), IMM(T_VOID));
MOV(IND(2), IMM(T_NIL));
MOV(IND(3), IMM(T_BOOL));
MOV(IND(4), IMM(0));
MOV(IND(5), IMM(T_BOOL));
MOV(IND(6), IMM(1));
MOV(IND(7), IMM(T_STRING));
MOV(IND(8), IMM(0));
MOV(IND(9), IMM(T_INTEGER));
MOV(IND(10), IMM(2));
MOV(IND(53), IMM(T_VOID));
MOV(IND(54), IMM(T_NIL));
MOV(IND(55), IMM(T_BOOL));
MOV(IND(56), IMM(1));
MOV(IND(57), IMM(T_BOOL));
MOV(IND(58), IMM(1));
MOV(IND(59), IMM(T_INTEGER));
MOV(IND(60), IMM(5));
MOV(IND(61), IMM(T_INTEGER));
MOV(IND(62), IMM(1));
MOV(IND(63), IMM(T_STRING));
MOV(IND(64), IMM(0));
MOV(IND(65), IMM(T_INTEGER));
MOV(IND(66), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(11), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(12), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(13), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(14), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(15), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(16), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(17), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(18), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(19), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(20), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(21), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(22), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(23), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(24), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(25), R0);
PUSH(LABEL(OURS_IS_ZERO));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(26), R0);
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(27), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(28), R0);
PUSH(LABEL(CHAR_2_INTEGER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(29), R0);
PUSH(LABEL(INTEGER_2_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(30), R0);
PUSH(LABEL(STRING_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(31), R0);
PUSH(LABEL(STRING_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(32), R0);
PUSH(LABEL(STRING_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(33), R0);
PUSH(LABEL(MAKE_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(34), R0);
PUSH(LABEL(VECTOR_LENGTH));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(35), R0);
PUSH(LABEL(VECTOR_REF));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(36), R0);
PUSH(LABEL(VECTOR_SET));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(37), R0);
PUSH(LABEL(MAKE_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(38), R0);
PUSH(LABEL(CONS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(39), R0);
PUSH(LABEL(CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(40), R0);
PUSH(LABEL(CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(41), R0);
PUSH(LABEL(SET_CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(42), R0);
PUSH(LABEL(SET_CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(43), R0);
MOV(IND(44), IMM(999999));
PUSH(LABEL(VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(45), R0);
MOV(IND(46), IMM(999999));
MOV(IND(47), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(48), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(49), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(50), R0);
MOV(IND(51), IMM(999999));
MOV(IND(52), IMM(999999));

/* ----------initiating symbols string linked list---------- */
MOV(IND(67), IMM(0));

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
closureEnvLoopLabel1158:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel1157);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1158);
closureEnvLoopEndLabel1157: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1160:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1159);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1160);
closureParameterLoopEndLabel1159: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1162));
JUMP(closureEndLabel1161);
closureBodyLabel1162:
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
MOV(R0,IMM(2));
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
MOV(R0, IND(18));
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
JUMP_EQ(labelElse1165);
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(9));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(18));
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
JUMP_EQ(labelElse1163);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(15));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit1164);
labelElse1163:
/*const*/
MOV(R0, IMM(3));

labelIfExit1164:

JUMP(labelIfExit1166);
labelElse1165:
/*const*/
MOV(R0, IMM(3));

labelIfExit1166:

CMP(R0, FALSE);
JUMP_EQ(labelElse1176);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit1177);
labelElse1176:
/*ifExp*/
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(18));
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
JUMP_EQ(labelElse1167);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(9));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(18));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

JUMP(labelIfExit1168);
labelElse1167:
/*const*/
MOV(R0, IMM(3));

labelIfExit1168:

CMP(R0, FALSE);
JUMP_EQ(labelElse1174);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(12));
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
MOV(R0, IND(51));
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
closureParameterLoopLabel1169:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel1170);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel1169);
closureParameterLoopEndLabel1170:
CMP(R5,R2);
JUMP_GE(greaterLabel1172);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel1171);
greaterLabel1172:
CMP(R5,R2);
JUMP_EQ(equalLabel1173);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel1171);
equalLabel1173:
DROP(R5);
DROP(1);endLabel1171:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit1175);
labelElse1174:
/*const*/
MOV(R0, IMM(7));

labelIfExit1175:

labelIfExit1177:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel1161:

MOV(IND(IMM(51)),IMM(R0));
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
closureEnvLoopLabel1148:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel1147);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1148);
closureEnvLoopEndLabel1147: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1150:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1149);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1150);
closureParameterLoopEndLabel1149: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1152));
JUMP(closureEndLabel1151);
closureBodyLabel1152:
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
JUMP_EQ(noParamsLabel1153);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel1155:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel1156);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel1155);closureParameterLoopEndLabel1156:
DROP(R13);
JUMP(EndLabel1154);

noParamsLabel1153:
MOV(R1, 2)
MOV(FPARG(IMM(1)),R1);
EndLabel1154:
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
closureEndLabel1151:

MOV(IND(IMM(44)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* define */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(3));

PUSH(R0);
/*const*/
MOV(R0, IMM(3));

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
closureEnvLoopLabel1099:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel1098);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1099);
closureEnvLoopEndLabel1098: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1101:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1100);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1101);
closureParameterLoopEndLabel1100: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1103));
JUMP(closureEndLabel1102);
closureBodyLabel1103:
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
closureEnvLoopLabel1135:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel1134);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1135);
closureEnvLoopEndLabel1134: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1137:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1136);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1137);
closureParameterLoopEndLabel1136: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1139));
JUMP(closureEndLabel1138);
closureBodyLabel1139:
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
MOV(R0,IMM(2));
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
MOV(R0, IND(23));
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
JUMP_EQ(labelElse1145);
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit1146);
labelElse1145:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(41));
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
MOV(R0,IMM(2));
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
MOV(R0, IND(40));
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
MOV(R0, IND(39));
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
closureParameterLoopLabel1140:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel1141);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel1140);
closureParameterLoopEndLabel1141:
CMP(R5,R2);
JUMP_GE(greaterLabel1143);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel1142);
greaterLabel1143:
CMP(R5,R2);
JUMP_EQ(equalLabel1144);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel1142);
equalLabel1144:
DROP(R5);
DROP(1);endLabel1142:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit1146:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel1138:

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
closureEnvLoopLabel1122:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel1121);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1122);
closureEnvLoopEndLabel1121: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1124:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1123);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1124);
closureParameterLoopEndLabel1123: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1126));
JUMP(closureEndLabel1125);
closureBodyLabel1126:
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
MOV(R0,IMM(2));
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
MOV(R0, IND(23));
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
JUMP_EQ(labelElse1132);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

JUMP(labelIfExit1133);
labelElse1132:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(41));
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
MOV(R0,IMM(2));
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
MOV(R0, IND(40));
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
closureParameterLoopLabel1127:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel1128);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel1127);
closureParameterLoopEndLabel1128:
CMP(R5,R2);
JUMP_GE(greaterLabel1130);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel1129);
greaterLabel1130:
CMP(R5,R2);
JUMP_EQ(equalLabel1131);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel1129);
equalLabel1131:
DROP(R5);
DROP(1);endLabel1129:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit1133:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel1125:

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
closureEnvLoopLabel1105:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel1104);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel1105);
closureEnvLoopEndLabel1104: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel1107:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel1106);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel1107);
closureParameterLoopEndLabel1106: 
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
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel1109));
JUMP(closureEndLabel1108);
closureBodyLabel1109:
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
JUMP_EQ(noParamsLabel1110);
/* with params */
MOV(R14,R13);
MOV(R15,R13);
MOV(R4, IMM(0));
ADD(R15,IMM(1));
ADD(R14,IMM(2));
closurePushLoopLabel1112:
CMP(R4,R13);
JUMP_EQ(closureParameterLoopEndLabel1113);
MOV(R1, FPARG(R14));
PUSH(R1);
MOV(R1, FPARG(R15));
PUSH(R1);
CALL(MAKE_SOB_PAIR);
DROP(IMM(2));
MOV(FPARG(R14),R0);
INCR(R4);
DECR(R15);
JUMP(closurePushLoopLabel1112);closureParameterLoopEndLabel1113:
DROP(R13);
JUMP(EndLabel1111);

noParamsLabel1110:
MOV(R1, 2)
MOV(FPARG(IMM(1)),R1);
EndLabel1111:
PUSH(R13);
PUSH(R12);
PUSH(R11);
PUSH(R10);
MOV(FP, SP);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(23));
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
JUMP_EQ(labelElse1119);
/*const*/
MOV(R0, IMM(2));

JUMP(labelIfExit1120);
labelElse1119:
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
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
MOV(R0, IND(41));
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
MOV(R0,IMM(2));
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
MOV(R0, IND(40));
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
closureParameterLoopLabel1114:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel1115);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel1114);
closureParameterLoopEndLabel1115:
CMP(R5,R2);
JUMP_GE(greaterLabel1117);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel1116);
greaterLabel1117:
CMP(R5,R2);
JUMP_EQ(equalLabel1118);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel1116);
equalLabel1118:
DROP(R5);
DROP(1);endLabel1116:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


labelIfExit1120:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel1108:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel1102:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);

MOV(IND(IMM(52)),IMM(R0));
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(2));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(9));

PUSH(R0);
/*const*/
MOV(R0, IMM(9));

PUSH(R0);
/*const*/
MOV(R0, IMM(61));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(3));
/*fvar */
MOV(R0, IND(11));
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
MOV(R0, IMM(59));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(12));
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
MOV(R0, IND(26));
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
