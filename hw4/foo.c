/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 180000002 

#define TRUE 180000004 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

#define SYMTAB 190000000

#include "arch/cisc.h"
#include "arch/BenTest.h"

int main()
{
 START_MACHINE;

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
MOV(IND(180000000), IMM(T_VOID));
MOV(IND(180000001), IMM(T_NIL));
MOV(IND(180000002), IMM(T_BOOL));
MOV(IND(180000003), IMM(0));
MOV(IND(180000004), IMM(T_BOOL));
MOV(IND(180000005), IMM(1));
MOV(IND(180000006), IMM(T_INTEGER));
MOV(IND(180000007), IMM(1));
MOV(IND(180000008), IMM(T_INTEGER));
MOV(IND(180000009), IMM(1));
MOV(IND(180000010), IMM(T_INTEGER));
MOV(IND(180000011), IMM(2));
MOV(IND(180000012), IMM(T_PAIR));
MOV(IND(180000013), IMM(180000010));
MOV(IND(180000014), IMM(180000001));
MOV(IND(180000015), IMM(T_PAIR));
MOV(IND(180000016), IMM(180000006));
MOV(IND(180000017), IMM(180000012));
MOV(IND(180000018), IMM(T_PAIR));
MOV(IND(180000019), IMM(180000006));
MOV(IND(180000020), IMM(180000015));
MOV(IND(180000021), IMM(T_STRING));
MOV(IND(180000022), IMM(1));
MOV(IND(180000023), IMM(97));
MOV(IND(180000024), IMM(T_SYMBOL));
MOV(IND(180000025), IMM(180000021));
MOV(IND(180000026), IMM(T_INTEGER));
MOV(IND(180000027), IMM(2));
MOV(IND(180000028), IMM(T_INTEGER));
MOV(IND(180000029), IMM(1));
MOV(IND(180000030), IMM(T_INTEGER));
MOV(IND(180000031), IMM(1));
MOV(IND(180000032), IMM(T_VECTOR));
MOV(IND(180000033), IMM(3));
MOV(IND(180000034), IMM(180000006));
MOV(IND(180000035), IMM(180000006));
MOV(IND(180000036), IMM(180000010));
MOV(IND(180000037), IMM(T_FRAC));
MOV(IND(180000038), IMM(1));
MOV(IND(180000039), IMM(2));
MOV(IND(180000040), IMM(T_INTEGER));
MOV(IND(180000041), IMM(1));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000042), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000043), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000044), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000045), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000046), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000047), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000048), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000049), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000050), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000051), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000052), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000053), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000054), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000055), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000056), R0);
MOV(IND(180000057), IMM(999999));
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000058), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000059), R0);
MOV(IND(180000060), IMM(999999));
MOV(IND(180000061), IMM(999999));
MOV(IND(180000062), IMM(999999));
MOV(IND(180000063), IMM(999999));
MOV(IND(180000064), IMM(999999));
MOV(IND(180000065), IMM(999999));
MOV(IND(180000066), IMM(999999));
MOV(IND(180000067), IMM(999999));
MOV(IND(180000068), IMM(999999));
MOV(IND(180000069), IMM(999999));
MOV(IND(180000070), IMM(999999));
MOV(IND(180000071), IMM(999999));
MOV(IND(180000072), IMM(999999));
MOV(IND(180000073), IMM(999999));
MOV(IND(180000074), IMM(999999));
MOV(IND(180000075), IMM(999999));
MOV(IND(180000076), IMM(999999));
MOV(IND(180000077), IMM(999999));
MOV(IND(180000078), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000079), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000080), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000081), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000082), R0);

/* ----------initiating symbols string linked list---------- */
MOV(IND(190000000), IMM(180000024));
MOV(IND(190000001), IMM(0));

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000037));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000082));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000082));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000024));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000082));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000032));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000058));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000018));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000058));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
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
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(0));
JUMP_NE(ERROR);
/* code-gen on body */
/* tc-applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(180000042));
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
closureParameterLoopLabel7:
CMP(R6, R5);
JUMP_EQ(closureParameterLoopEndLabel8);
MOV(FPARG(R3), STARG(R4));
DECR(R4);
DECR(R3);
INCR(R6);
JUMP(closureParameterLoopLabel7);
closureParameterLoopEndLabel8:
CMP(R5,R2);
JUMP_GE(greaterLabel10);
DROP(R5);
SUB(R2,R5);
DROP(R2);
DROP(1);JUMP(endLabel9);
greaterLabel10:
CMP(R5,R2);
JUMP_EQ(equalLabel11);
MOV(R7,R5);
SUB(R5,R2);
SUB(R7,R5);
DROP(R7);
DROP(1);JUMP(endLabel9);
equalLabel11:
DROP(R5);
DROP(1);endLabel9:
MOV(FP, R1);
JUMPA(INDD(R0, 2));



POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel5:

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000059));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(180000042));
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
MOV(R0, IND(180000059));
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
