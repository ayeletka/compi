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
#include "ours.lib"
#include "scheme.lib"

CONTINUE:

/* ----------initiating const table---------- */
MOV(IND(10), IMM(T_VOID));
MOV(IND(11), IMM(T_NIL));
MOV(IND(12), IMM(T_BOOL));
MOV(IND(13), IMM(T_BOOL));
MOV(IND(14), IMM(T_CHAR));
MOV(IND(15), IMM(1));

/*const*/
MOV(R0,14);

CALL(PRINT_R0);
/*const*/
MOV(R0,12);

CALL(PRINT_R0);

PROG_ENDING: 
  STOP_MACHINE;
  return 0;
}
