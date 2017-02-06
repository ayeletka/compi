/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 1002 

#define TRUE 1004 

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
MOV(IND(1007), IMM(1));
MOV(IND(1008), IMM(T_INTEGER));
MOV(IND(1009), IMM(10));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1010), R0);
MOV(IND(1011), IMM(999999));
MOV(IND(1012), IMM(999999));
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

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*fvar */
MOV(R0, IND(1010));

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
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1008));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
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
/* lambda simple body */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1006));

PUSH(R0);
/* pvar */
MOV(R10, IMM(0));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);


POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel11:
CMP(INDD(R0,IMM(0)), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move number of args to R5, this is the amount to drop from stack. */
DROP(1);
POP(R1);
INCR(R1);
DROP(R1);


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
  STOP_MACHINE;
  return 0;
}
