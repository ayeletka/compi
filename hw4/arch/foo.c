/* final compilar project
Programmers: Ayelet Kalderon & Avishag Daniely */

#include <stdio.h>
#include <stdlib.h>

/* change to 0 for no debug info to be printed: */
#define DO_SHOW 1

#include "cisc.h"

int main()
{
 START_MACHINE;

 JUMP(CONTINUE);

#include "char.lib"
#include "io.lib"
#include "math.lib"
#include "string.lib"
#include "system.lib"
#include "scheme.lib"

CONTINUE:

/* ----------initiating const table---------- */
MOV(IND(10), IMM(T_VOID));
MOV(IND(11), IMM(T_NIL));
MOV(IND(12), IMM(T_BOOL));
MOV(IND(13), IMM(T_BOOL));
MOV(IND(14), IMM(T_STRING));
MOV(IND(15), IMM(1));
MOV(IND(16), IMM(97));
MOV(IND(17), IMM(T_SYMBOL));
MOV(IND(18), IMM(14));
MOV(IND(19), IMM(T_CHAR));
MOV(IND(20), IMM(1));

/*const*/
MOV(R0,17);

PUSH(R0);
CALL(WRITE_SOB);
/*const*/
MOV(R0,19);

PUSH(R0);
CALL(WRITE_SOB);

PROG_ENDING: 
  STOP_MACHINE;
  return 0;
}
