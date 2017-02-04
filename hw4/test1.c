/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 12 

#define TRUE 14 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

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
MOV(IND(1000), IMM(T_VOID));
MOV(IND(1001), IMM(T_NIL));
MOV(IND(1002), IMM(T_BOOL));
MOV(IND(1003), IMM(0));
MOV(IND(1004), IMM(T_BOOL));
MOV(IND(1005), IMM(1));
MOV(IND(1006), IMM(T_INTEGER));
MOV(IND(1007), IMM(7));
MOV(IND(1008), IMM(T_INTEGER));
MOV(IND(1009), IMM(1));
MOV(IND(1010), IMM(T_INTEGER));
MOV(IND(1011), IMM(0));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1012), R0);
MOV(IND(1013), IMM(999999));
MOV(IND(1014), IMM(999999));
MOV(IND(1015), IMM(999999));
MOV(IND(1016), IMM(999999));
MOV(IND(1017), IMM(999999));
MOV(IND(1018), IMM(999999));
MOV(IND(1019), IMM(999999));
MOV(IND(1020), IMM(999999));
MOV(IND(1021), IMM(999999));
MOV(IND(1022), IMM(999999));
MOV(IND(1023), IMM(999999));
MOV(IND(1024), IMM(999999));
MOV(IND(1025), IMM(999999));
MOV(IND(1026), IMM(999999));
MOV(IND(1027), IMM(999999));
MOV(IND(1028), IMM(999999));
MOV(IND(1029), IMM(999999));
MOV(IND(1030), IMM(999999));
MOV(IND(1031), IMM(999999));
MOV(IND(1032), IMM(999999));
MOV(IND(1033), IMM(999999));
MOV(IND(1034), IMM(999999));
MOV(IND(1035), IMM(999999));
MOV(IND(1036), IMM(999999));
MOV(IND(1037), IMM(999999));
MOV(IND(1038), IMM(999999));
MOV(IND(1039), IMM(999999));
MOV(IND(1040), IMM(999999));
MOV(IND(1041), IMM(999999));
MOV(IND(1042), IMM(999999));
MOV(IND(1043), IMM(999999));
MOV(IND(1044), IMM(999999));
MOV(IND(1045), IMM(999999));
MOV(IND(1046), IMM(999999));
MOV(IND(1047), IMM(999999));
MOV(IND(1048), IMM(999999));
MOV(IND(1049), IMM(999999));
MOV(IND(1050), IMM(999999));
MOV(IND(1051), IMM(999999));
MOV(IND(1052), IMM(999999));

/* define */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
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
closureEnvLoopLabel48:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel47);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel48);
closureEnvLoopEndLabel47: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel50:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel49);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel50);
closureParameterLoopEndLabel49: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel52));
JUMP(closureEndLabel51);
closureBodyLabel52:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
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
closureEnvLoopLabel54:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel53);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel54);
closureEnvLoopEndLabel53: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel56:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel55);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel56);
closureParameterLoopEndLabel55: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel58));
JUMP(closureEndLabel57);
closureBodyLabel58:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/*ifExp*/
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
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
MOV(R0, IND(1027));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

CMP(R0, FALSE);
JUMP_EQ(labelElse99);
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1008));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(1013));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel72:
CMP(R10,IMM(2));
JUMP_EQ(closureEnvLoopEndLabel71);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel72);
closureEnvLoopEndLabel71: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel74:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel73);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel74);
closureParameterLoopEndLabel73: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel76));
JUMP(closureEndLabel75);
closureBodyLabel76:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel78:
CMP(R10,IMM(3));
JUMP_EQ(closureEnvLoopEndLabel77);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel78);
closureEnvLoopEndLabel77: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel80:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel79);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel80);
closureParameterLoopEndLabel79: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel82));
JUMP(closureEndLabel81);
closureBodyLabel82:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(5));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel84:
CMP(R10,IMM(4));
JUMP_EQ(closureEnvLoopEndLabel83);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel84);
closureEnvLoopEndLabel83: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel86:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel85);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel86);
closureParameterLoopEndLabel85: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel88));
JUMP(closureEndLabel87);
closureBodyLabel88:
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
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
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
closureParameterLoopLabel89:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel90);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel89);
closureParameterLoopEndLabel90:
CMP(R5,R2);
JUMP_GE(greaterLabel92);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel91);
greaterLabel92:
CMP(R5,R2);
JUMP_EQ(equalLabel93);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel91);
equalLabel93:
DROP(R5);
DROP(1);endLabel91:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel87:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel81:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel75:
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
closureParameterLoopLabel94:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel95);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel94);
closureParameterLoopEndLabel95:
CMP(R5,R2);
JUMP_GE(greaterLabel97);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel96);
greaterLabel97:
CMP(R5,R2);
JUMP_EQ(equalLabel98);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel96);
equalLabel98:
DROP(R5);
DROP(1);endLabel96:
MOV(FP, R1);
JUMPA(INDD(R0, 2));


JUMP(labelIfExit100);
labelElse99:
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel60:
CMP(R10,IMM(2));
JUMP_EQ(closureEnvLoopEndLabel59);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel60);
closureEnvLoopEndLabel59: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel62:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel61);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel62);
closureParameterLoopEndLabel61: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel64));
JUMP(closureEndLabel63);
closureBodyLabel64:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel66:
CMP(R10,IMM(3));
JUMP_EQ(closureEnvLoopEndLabel65);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel66);
closureEnvLoopEndLabel65: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel68:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel67);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel68);
closureParameterLoopEndLabel67: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel70));
JUMP(closureEndLabel69);
closureBodyLabel70:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel69:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel63:

labelIfExit100:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel57:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel51:

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
closureEnvLoopLabel102:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel101);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel102);
closureEnvLoopEndLabel101: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel104:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel103);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel104);
closureParameterLoopEndLabel103: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel106));
JUMP(closureEndLabel105);
closureBodyLabel106:
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
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

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
closureParameterLoopLabel107:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel108);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel107);
closureParameterLoopEndLabel108:
CMP(R5,R2);
JUMP_GE(greaterLabel110);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel109);
greaterLabel110:
CMP(R5,R2);
JUMP_EQ(equalLabel111);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel109);
equalLabel111:
DROP(R5);
DROP(1);endLabel109:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel105:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
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
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
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
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel14:
CMP(R10,IMM(2));
JUMP_EQ(closureEnvLoopEndLabel13);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel14);
closureEnvLoopEndLabel13: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel16:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel15);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel16);
closureParameterLoopEndLabel15: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel18));
JUMP(closureEndLabel17);
closureBodyLabel18:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel17:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel11:

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
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
closureEnvLoopLabel20:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel19);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel20);
closureEnvLoopEndLabel19: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel22:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel21);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel22);
closureParameterLoopEndLabel21: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel24));
JUMP(closureEndLabel23);
closureBodyLabel24:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel26:
CMP(R10,IMM(2));
JUMP_EQ(closureEnvLoopEndLabel25);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel26);
closureEnvLoopEndLabel25: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel28:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel27);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel28);
closureParameterLoopEndLabel27: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel30));
JUMP(closureEndLabel29);
closureBodyLabel30:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(4));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel32:
CMP(R10,IMM(3));
JUMP_EQ(closureEnvLoopEndLabel31);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel32);
closureEnvLoopEndLabel31: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel34:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel33);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel34);
closureParameterLoopEndLabel33: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel36));
JUMP(closureEndLabel35);
closureBodyLabel36:
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
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,1));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
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
closureParameterLoopLabel37:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel38);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel37);
closureParameterLoopEndLabel38:
CMP(R5,R2);
JUMP_GE(greaterLabel40);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel39);
greaterLabel40:
CMP(R5,R2);
JUMP_EQ(equalLabel41);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel39);
equalLabel41:
DROP(R5);
DROP(1);endLabel39:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel35:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel29:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel23:

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
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
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
closureParameterLoopLabel42:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel43);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel42);
closureParameterLoopEndLabel43:
CMP(R5,R2);
JUMP_GE(greaterLabel45);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel44);
greaterLabel45:
CMP(R5,R2);
JUMP_EQ(equalLabel46);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel44);
equalLabel46:
DROP(R5);
DROP(1);endLabel44:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel5:

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
closureEnvLoopLabel113:
CMP(R10,IMM(0));
JUMP_EQ(closureEnvLoopEndLabel112);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel113);
closureEnvLoopEndLabel112: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel115:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel114);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel115);
closureParameterLoopEndLabel114: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel117));
JUMP(closureEndLabel116);
closureBodyLabel117:
PUSH(FP);
MOV(FP,SP);
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
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
closureEnvLoopLabel119:
CMP(R10,IMM(1));
JUMP_EQ(closureEnvLoopEndLabel118);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel119);
closureEnvLoopEndLabel118: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel121:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel120);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel121);
closureParameterLoopEndLabel120: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel123));
JUMP(closureEndLabel122);
closureBodyLabel123:
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
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1010));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* get old env address, put in R8 */
MOV(R8, FPARG(0));
/* make room for new env */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R9 */
MOV(R9,R0);
/* clone the env */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(1));
closureEnvLoopLabel125:
CMP(R10,IMM(2));
JUMP_EQ(closureEnvLoopEndLabel124);
MOV(INDD(R9,R11), INDD(R8,R10));
INCR(R10);
INCR(R11);
JUMP(closureEnvLoopLabel125);
closureEnvLoopEndLabel124: 
MOV(R12, FPARG(1));
PUSH(R12);
CALL(MALLOC);
DROP(1);/* put old params in R9 */
MOV(INDD(R9,0),R0);
/* clone parameters from stack */
/* R10 is i, R11 is j */
MOV(R10, IMM(0));
MOV(R11, IMM(2));
closureParameterLoopLabel127:
CMP(R10,R12);
JUMP_EQ(closureParameterLoopEndLabel126);
MOV(R13,INDD(R9,IMM(0)));
MOV(INDD(R13,R10), FPARG(R11));
INCR(R10);
INCR(R11);
JUMP(closureParameterLoopLabel127);
closureParameterLoopEndLabel126: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R9);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel129));
JUMP(closureEndLabel128);
closureBodyLabel129:
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
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1008));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(1012));
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
closureParameterLoopLabel130:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel131);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel130);
closureParameterLoopEndLabel131:
CMP(R5,R2);
JUMP_GE(greaterLabel133);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel132);
greaterLabel133:
CMP(R5,R2);
JUMP_EQ(equalLabel134);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel132);
equalLabel134:
DROP(R5);
DROP(1);endLabel132:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel128:

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,1));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);
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
closureParameterLoopLabel135:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel136);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel135);
closureParameterLoopEndLabel136:
CMP(R5,R2);
JUMP_GE(greaterLabel138);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel137);
greaterLabel138:
CMP(R5,R2);
JUMP_EQ(equalLabel139);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel137);
equalLabel139:
DROP(R5);
DROP(1);endLabel137:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel122:


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel116:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

MOV(IND(IMM(1052)),R0);
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(1052));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(3));
DROP(R5);

CALL(PRINT_R0);


PROG_ENDING: 
  STOP_MACHINE;
  return 0;
}
