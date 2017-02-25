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
MOV(IND(200000008), IMM(T_STRING));
MOV(IND(200000009), IMM(7));
MOV(IND(200000010), IMM(97));
MOV(IND(200000011), IMM(118));
MOV(IND(200000012), IMM(105));
MOV(IND(200000013), IMM(115));
MOV(IND(200000014), IMM(104));
MOV(IND(200000015), IMM(97));
MOV(IND(200000016), IMM(103));
MOV(IND(200000017), IMM(T_SYMBOL));
MOV(IND(200000018), IMM(200000008));
MOV(IND(200000019), IMM(T_STRING));
MOV(IND(200000020), IMM(6));
MOV(IND(200000021), IMM(97));
MOV(IND(200000022), IMM(121));
MOV(IND(200000023), IMM(101));
MOV(IND(200000024), IMM(108));
MOV(IND(200000025), IMM(101));
MOV(IND(200000026), IMM(121));
MOV(IND(200000027), IMM(T_SYMBOL));
MOV(IND(200000028), IMM(200000019));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000029), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000030), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000031), R0);
PUSH(LABEL(DIVIDE));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000032), R0);
PUSH(LABEL(LOWER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000033), R0);
PUSH(LABEL(GREATER));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000034), R0);
PUSH(LABEL(EQUAL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000035), R0);
PUSH(LABEL(IS_NUM));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000036), R0);
PUSH(LABEL(IS_INT));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000037), R0);
PUSH(LABEL(IS_BOOLEAN));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000038), R0);
MOV(IND(200000039), IMM(999999));
PUSH(LABEL(IS_CHAR));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000040), R0);
PUSH(LABEL(IS_NULL));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(200000041), R0);
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
MOV(IND(200000053), IMM(999999));
MOV(IND(200000054), IMM(999999));
MOV(IND(200000055), IMM(999999));
MOV(IND(200000056), IMM(999999));
MOV(IND(200000057), IMM(999999));
MOV(IND(200000058), IMM(999999));
MOV(IND(200000059), IMM(999999));
MOV(IND(200000060), IMM(999999));
MOV(IND(200000061), IMM(999999));
MOV(IND(200000062), IMM(999999));
MOV(IND(200000063), IMM(999999));
MOV(IND(200000064), IMM(999999));
MOV(IND(200000065), IMM(999999));
MOV(IND(200000066), IMM(999999));
MOV(IND(200000067), IMM(999999));
MOV(IND(200000068), IMM(999999));

/* ----------initiating symbols string linked list---------- */
MOV(IND(200000069), IMM(200000008));
MOV(IND(200000070), IMM(200000071));
MOV(IND(200000071), IMM(200000019));
MOV(IND(200000072), IMM(0));

/*const*/
MOV(R0, IMM(200000017));

CALL(PRINT_R0);

/*const*/
MOV(R0, IMM(200000027));

CALL(PRINT_R0);

/*const*/
MOV(R0, IMM(200000006));

CALL(PRINT_R0);


PROG_ENDING: 
  MOV(SP,FP);
  POP(FP);
  STOP_MACHINE;
  return 0;
}
