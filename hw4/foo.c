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
MOV(IND(1003), IMM(1));
MOV(IND(1004), IMM(T_BOOL));
MOV(IND(1005), IMM(1));
MOV(IND(1006), IMM(T_INTEGER));
MOV(IND(1007), IMM(22));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1008), R0);
MOV(IND(1009), IMM(999999));
MOV(IND(1010), IMM(999999));
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

/* define */
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
closureEndLabel5:

MOV(IND(IMM(1048)),R0);
MOV(R0, IMM(T_VOID));

CALL(PRINT_R0);

/* applic */

/* push params reverse order. */
/*const*/
MOV(R0, IMM(1006));

PUSH(R0);
/* push number of args. */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(1048));
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
