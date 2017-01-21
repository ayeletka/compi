/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define FALSE 12 

#define TRUE 14 

#define LOCAL_NUM_ARGS 1 

#include "arch/cisc.h"

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
MOV(IND(10), IMM(T_VOID));
MOV(IND(11), IMM(T_NIL));
MOV(IND(12), IMM(T_BOOL));
MOV(IND(13), IMM(0));
MOV(IND(14), IMM(T_BOOL));
MOV(IND(15), IMM(1));
MOV(IND(16), IMM(T_INTEGER));
MOV(IND(17), IMM(6));
MOV(IND(18), IMM(T_INTEGER));
MOV(IND(19), IMM(5));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(20), R0);
MOV(IND(21), IMM(999999));
MOV(IND(22), IMM(999999));
MOV(IND(23), IMM(999999));
MOV(IND(24), IMM(999999));
MOV(IND(25), IMM(999999));
MOV(IND(26), IMM(999999));
MOV(IND(27), IMM(999999));
MOV(IND(28), IMM(999999));
MOV(IND(29), IMM(999999));
MOV(IND(30), IMM(999999));
MOV(IND(31), IMM(999999));
MOV(IND(32), IMM(999999));
MOV(IND(33), IMM(999999));
MOV(IND(34), IMM(999999));
MOV(IND(35), IMM(999999));
MOV(IND(36), IMM(999999));
MOV(IND(37), IMM(999999));
MOV(IND(38), IMM(999999));
MOV(IND(39), IMM(999999));
MOV(IND(40), IMM(999999));
MOV(IND(41), IMM(999999));
MOV(IND(42), IMM(999999));
MOV(IND(43), IMM(999999));
MOV(IND(44), IMM(999999));
MOV(IND(45), IMM(999999));
MOV(IND(46), IMM(999999));
MOV(IND(47), IMM(999999));
MOV(IND(48), IMM(999999));
MOV(IND(49), IMM(999999));
MOV(IND(50), IMM(999999));
MOV(IND(51), IMM(999999));
MOV(IND(52), IMM(999999));
MOV(IND(53), IMM(999999));
MOV(IND(54), IMM(999999));
MOV(IND(55), IMM(999999));
MOV(IND(56), IMM(999999));
MOV(IND(57), IMM(999999));
MOV(IND(58), IMM(999999));
MOV(IND(59), IMM(999999));

/* applic */

/* push params reverse order. */
/*const*/
MOV(R0, IMM(18));

PUSH(R0);
/*const*/
MOV(R0, IMM(16));

PUSH(R0);
/* push number of args. */
PUSH(IMM(2));
/* get old env address, put in R1 */
MOV(R1, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R2 */
MOV(R2,R0);
/* clone the env */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureEnvLoopLabel14:
CMP(R4,IMM(0));
JUMP_GE(closureEnvLoopEndLabel13);
MOV(INDD(R2,R5), INDD(R1,R4));
INCR(R4);
INCR(R5);
JUMP(closureEnvLoopLabel14);
closureEnvLoopEndLabel13: 
/* get old parameters length, put in R3 */
PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));

/* put old params in R2 */
MOV(INDD(R2,0),R0);/* clone parameters from stack */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureParameterLoopLabel16:
CMP(R4,IMM(2));
JUMP_GE(closureParameterLoopEndLabel15);
MOV(INDD(INDD(R2,0),R4), FPARG(R5));
INCR(R4);
INCR(R5);
JUMP(closureParameterLoopLabel16);
closureParameterLoopEndLabel15: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R2);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel18));
JUMP(closureEndLabel17);
closureBodyLabel18:
PUSH(FP);
MOV(FP,SP);
/* simple lambda body ... */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R1 */
MOV(R1, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R2 */
MOV(R2,R0);
/* clone the env */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureEnvLoopLabel20:
CMP(R4,IMM(1));
JUMP_GE(closureEnvLoopEndLabel19);
MOV(INDD(R2,R5), INDD(R1,R4));
INCR(R4);
INCR(R5);
JUMP(closureEnvLoopLabel20);
closureEnvLoopEndLabel19: 
/* get old parameters length, put in R3 */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));

/* put old params in R2 */
MOV(INDD(R2,0),R0);/* clone parameters from stack */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureParameterLoopLabel22:
CMP(R4,IMM(4));
JUMP_GE(closureParameterLoopEndLabel21);
MOV(INDD(INDD(R2,0),R4), FPARG(R5));
INCR(R4);
INCR(R5);
JUMP(closureParameterLoopLabel22);
closureParameterLoopEndLabel21: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R2);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel24));
JUMP(closureEndLabel23);
closureBodyLabel24:
PUSH(FP);
MOV(FP,SP);
/* simple lambda body ... */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(1));
JUMP_NE(ERROR);
/* code-gen on body */
/* bvar */
MOV(R0, FPARG(IMM(0)));
MOV(R0,INDD(R0,0));
MOV(R0,INDD(R0,0));
SHOW("",R0);

POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel23:
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));

POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel17:
CMP(INDD(R0,0), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move to R5 number of args .. to know how to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(2));
DROP(R5);

CALL(PRINT_R0);

/* applic */

/* push params reverse order. */
/*const*/
MOV(R0, IMM(18));

PUSH(R0);
/*const*/
MOV(R0, IMM(16));

PUSH(R0);
/* push number of args. */
PUSH(IMM(2));
/* get old env address, put in R1 */
MOV(R1, FPARG(0));
/* make room for new env */
PUSH(IMM(1));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R2 */
MOV(R2,R0);
/* clone the env */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureEnvLoopLabel2:
CMP(R4,IMM(0));
JUMP_GE(closureEnvLoopEndLabel1);
MOV(INDD(R2,R5), INDD(R1,R4));
INCR(R4);
INCR(R5);
JUMP(closureEnvLoopLabel2);
closureEnvLoopEndLabel1: 
/* get old parameters length, put in R3 */
PUSH(IMM(0));
CALL(MALLOC);
DROP(IMM(1));

/* put old params in R2 */
MOV(INDD(R2,0),R0);/* clone parameters from stack */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureParameterLoopLabel4:
CMP(R4,IMM(2));
JUMP_GE(closureParameterLoopEndLabel3);
MOV(INDD(INDD(R2,0),R4), FPARG(R5));
INCR(R4);
INCR(R5);
JUMP(closureParameterLoopLabel4);
closureParameterLoopEndLabel3: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R2);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel6));
JUMP(closureEndLabel5);
closureBodyLabel6:
PUSH(FP);
MOV(FP,SP);
/* simple lambda body ... */
/* check if number of params is correct */
MOV(R1, FPARG(1));
CMP(R1, IMM(2));
JUMP_NE(ERROR);
/* code-gen on body */
/* get old env address, put in R1 */
MOV(R1, FPARG(0));
/* make room for new env */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));
/* put new env in R2 */
MOV(R2,R0);
/* clone the env */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureEnvLoopLabel8:
CMP(R4,IMM(1));
JUMP_GE(closureEnvLoopEndLabel7);
MOV(INDD(R2,R5), INDD(R1,R4));
INCR(R4);
INCR(R5);
JUMP(closureEnvLoopLabel8);
closureEnvLoopEndLabel7: 
/* get old parameters length, put in R3 */
PUSH(IMM(2));
CALL(MALLOC);
DROP(IMM(1));

/* put old params in R2 */
MOV(INDD(R2,0),R0);/* clone parameters from stack */
/* R4 is i, R5 is j */
MOV(R4, IMM(0));
MOV(R5, IMM(1));
closureParameterLoopLabel10:
CMP(R4,IMM(4));
JUMP_GE(closureParameterLoopEndLabel9);
MOV(INDD(INDD(R2,0),R4), FPARG(R5));
INCR(R4);
INCR(R5);
JUMP(closureParameterLoopLabel10);
closureParameterLoopEndLabel9: 
/* Calling malloc for closure, env and body. */
PUSH(IMM(3));
CALL(MALLOC);
DROP(IMM(1));
/* put closure in R0 */
MOV(INDD(R0,IMM(0)),276405);
/* put env in R0 */
MOV(INDD(R0,IMM(1)), R2);
/* closure body ...*/
MOV(INDD(R0,IMM(2)), LABEL(closureBodyLabel12));
JUMP(closureEndLabel11);
closureBodyLabel12:
PUSH(FP);
MOV(FP,SP);
/* simple lambda body ... */
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
closureEndLabel11:
/* pvar */
MOV(R10, IMM(1));
ADD(R10,IMM(2));
MOV(R0, FPARG(R10));
POP(FP);
RETURN;
/* LABEL END LAMBDA */
closureEndLabel5:
CMP(INDD(R0,0), IMM(T_CLOSURE));
JUMP_NE(ERROR);
PUSH(INDD(R0,IMM(1)));
CALLA(INDD(R0,IMM(2)));
/* move to R5 number of args .. to know how to drop from stack. */
MOV(R5,STARG(IMM(0)));
ADD(R5, IMM(2));
DROP(R5);

CALL(PRINT_R0);


PROG_ENDING: 
  STOP_MACHINE;
  return 0;
}
