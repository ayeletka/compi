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
MOV(IND(1008), IMM(T_FRAC));
MOV(IND(1009), IMM(-1));
MOV(IND(1010), IMM(2));
MOV(IND(1011), IMM(T_INTEGER));
MOV(IND(1012), IMM(0));
MOV(IND(1013), IMM(T_FRAC));
MOV(IND(1014), IMM(-2));
MOV(IND(1015), IMM(3));
MOV(IND(1016), IMM(T_FRAC));
MOV(IND(1017), IMM(3));
MOV(IND(1018), IMM(2));

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1019), R0);
PUSH(LABEL(MINUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1020), R0);
PUSH(LABEL(MULTIPLY));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1021), R0);
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
MOV(IND(1053), IMM(999999));
MOV(IND(1054), IMM(999999));
MOV(IND(1055), IMM(999999));
MOV(IND(1056), IMM(999999));
MOV(IND(1057), IMM(999999));
MOV(IND(1058), IMM(999999));

/* applic */

/* push T_NIL for empty lambda var and opt */
MOV(R0,IMM(1001));
PUSH(R0);
/* push params in reverse order. */
/*const*/
MOV(R0, IMM(1006));

PUSH(R0);
/*const*/
MOV(R0, IMM(1011));

PUSH(R0);
/*const*/
MOV(R0, IMM(1008));

PUSH(R0);
/*const*/
MOV(R0, IMM(1016));

PUSH(R0);
/*const*/
MOV(R0, IMM(1013));

PUSH(R0);
/* push number of arguments */
PUSH(IMM(5));
/*fvar */
MOV(R0, IND(1021));
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
