/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#define SOB_NIL 2

#define FALSE 200000002 

#define TRUE 200000004 

#define LOCAL_NUM_ARGS 1 

#define LOCAL_ENV 0

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
MOV(IND(200000000), IMM(T_VOID));
MOV(IND(200000001), IMM(T_NIL));
MOV(IND(200000002), IMM(T_BOOL));
MOV(IND(200000003), IMM(0));
MOV(IND(200000004), IMM(T_BOOL));
MOV(IND(200000005), IMM(1));
MOV(IND(200000006), IMM(T_INTEGER));
MOV(IND(200000007), IMM(2));
MOV(IND(200000008), IMM(T_INTEGER));
MOV(IND(200000009), IMM(1));
MOV(IND(200000010), IMM(T_FRAC));
MOV(IND(200000011), IMM(1));
MOV(IND(200000012), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000013), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000014), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000015), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000016), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000017), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000018), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000019), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000020), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000021), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000022), R0);
MOV(IND(200000023), IMM(999999));
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000024), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000025), R0);
MOV(IND(200000026), IMM(999999));
MOV(IND(200000027), IMM(999999));
MOV(IND(200000028), IMM(999999));
MOV(IND(200000029), IMM(999999));
MOV(IND(200000030), IMM(999999));
MOV(IND(200000031), IMM(999999));
MOV(IND(200000032), IMM(999999));
MOV(IND(200000033), IMM(999999));
MOV(IND(200000034), IMM(999999));
MOV(IND(200000035), IMM(999999));
MOV(IND(200000036), IMM(999999));
MOV(IND(200000037), IMM(999999));
MOV(IND(200000038), IMM(999999));
MOV(IND(200000039), IMM(999999));
MOV(IND(200000040), IMM(999999));
MOV(IND(200000041), IMM(999999));
MOV(IND(200000042), IMM(999999));
MOV(IND(200000043), IMM(999999));
MOV(IND(200000044), IMM(999999));
MOV(IND(200000045), IMM(999999));
MOV(IND(200000046), IMM(999999));
MOV(IND(200000047), IMM(999999));
MOV(IND(200000048), IMM(999999));
MOV(IND(200000049), IMM(999999));
MOV(IND(200000050), IMM(999999));
MOV(IND(200000051), IMM(999999));
MOV(IND(200000052), IMM(999999));

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000008));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000020));
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
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000010));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000020));
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
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000010));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000021));
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
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000021));
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
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000001));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000025));
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
MOV(R0,IMM(200000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(200000008));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(200000025));
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
