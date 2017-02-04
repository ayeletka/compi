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

PUSH(LABEL(PLUS));
PUSH(IMM(0));
CALL(MAKE_SOB_CLOSURE);
DROP(IMM(2));
MOV(IND(1006), R0);
MOV(IND(1007), IMM(999999));
MOV(IND(1008), IMM(999999));
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


PROG_ENDING: 
  STOP_MACHINE;
  return 0;
}
