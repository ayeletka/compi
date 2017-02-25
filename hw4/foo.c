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
MOV(IND(180000009), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000010), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000011), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000012), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000013), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000014), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000015), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000016), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000017), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000018), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000019), R0);
PUSH(LABEL(IS_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000020), R0);
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000021), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000022), R0);
PUSH(LABEL(IS_PAIR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000023), R0);
PUSH(LABEL(IS_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000024), R0);
PUSH(LABEL(OURS_IS_ZERO));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000025), R0);
PUSH(LABEL(IS_VECTOR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000026), R0);
PUSH(LABEL(IS_PROC));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000027), R0);
PUSH(LABEL(CHAR_2_INTEGER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000028), R0);
PUSH(LABEL(INTEGER_2_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000029), R0);
MOV(IND(180000030), IMM(999999));
MOV(IND(180000031), IMM(999999));
MOV(IND(180000032), IMM(999999));
MOV(IND(180000033), IMM(999999));
MOV(IND(180000034), IMM(999999));
MOV(IND(180000035), IMM(999999));
MOV(IND(180000036), IMM(999999));
MOV(IND(180000037), IMM(999999));
PUSH(LABEL(CONS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000038), R0);
PUSH(LABEL(CAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000039), R0);
PUSH(LABEL(CDR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000040), R0);
MOV(IND(180000041), IMM(999999));
MOV(IND(180000042), IMM(999999));
MOV(IND(180000043), IMM(999999));
MOV(IND(180000044), IMM(999999));
MOV(IND(180000045), IMM(999999));
MOV(IND(180000046), IMM(999999));
PUSH(LABEL(SYMBOL_2_STRING));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000047), R0);
PUSH(LABEL(STRING_2_SYMBOL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000048), R0);
PUSH(LABEL(CHECK_EQ_OBJECT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000049), R0);
PUSH(LABEL(NOT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(180000050), R0);

/* ----------initiating symbols string linked list---------- */
MOV(IND(190000000), IMM(0));

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(180000001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(180000002));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000050));
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
MOV(R0, IMM(180000004));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(1));
/*fvar */
MOV(R0, IND(180000050));
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
MOV(R0, IMM(180000008));

PUSH(R0);
/*const*/
MOV(R0, IMM(180000006));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(2));
/*fvar */
MOV(R0, IND(180000016));
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
MOV(R0, IND(180000050));
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
