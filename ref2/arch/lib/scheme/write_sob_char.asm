/* scheme/write_sob_char.asm
 * Take a pointer to a Scheme char object, and 
 * prints (to stdout) the character representation
 * of that object.
 * 
 * Programmer: Mayer Goldberg, 2010
 */

 WRITE_SOB_CHAR:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(IMM('#'));
  CALL(PUTCHAR);
  PUSH(IMM('\\'));
  CALL(PUTCHAR);
  DROP(2);
  MOV(R0, FPARG(0));
  MOV(R0, INDD(R0, 1));
  CMP(R0, IMM('\n'));
  JUMP_EQ(L_WRITE_SOB_CHAR_NEWLINE);
  CMP(R0, IMM('\t'));
  JUMP_EQ(L_WRITE_SOB_CHAR_TAB);
  CMP(R0, IMM('\f'));
  JUMP_EQ(L_WRITE_SOB_CHAR_PAGE);
  CMP(R0, IMM('\r'));
  JUMP_EQ(L_WRITE_SOB_CHAR_RETURN);
  CMP(R0, IMM(' '));
  JUMP_EQ(L_WRITE_SOB_CHAR_SPACE);
  JUMP_LT(L_WRITE_SOB_CHAR_OCTAL);
  PUSH(R0);
  CALL(PUTCHAR);
  DROP(1);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_OCTAL:
  MOV(R1, R0);
  REM(R1, IMM(8));
  PUSH(R1);
  DIV(R0, IMM(8));
  MOV(R1, R0);
  REM(R1, IMM(8));
  PUSH(R1);
  DIV(R0, IMM(8));
  REM(R0, IMM(8));
  PUSH(R0);
  CALL(WRITE_INTEGER);
  DROP(1);
  CALL(WRITE_INTEGER);
  DROP(1);
  CALL(WRITE_INTEGER);
  DROP(1);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_RETURN:
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  PUSH(IMM('u'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('n'));
  CALL(PUTCHAR);
  DROP(6);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_PAGE:
  PUSH(IMM('p'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('g'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  DROP(4);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_TAB:
  PUSH(IMM('t'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('b'));
  CALL(PUTCHAR);
  DROP(3);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_NEWLINE:
  PUSH(IMM('n'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('w'));
  CALL(PUTCHAR);
  PUSH(IMM('l'));
  CALL(PUTCHAR);
  PUSH(IMM('i'));
  CALL(PUTCHAR);
  PUSH(IMM('n'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  DROP(7);
  JUMP(L_WRITE_SOB_CHAR_EXIT);
 L_WRITE_SOB_CHAR_SPACE:
  PUSH(IMM('s'));
  CALL(PUTCHAR);
  PUSH(IMM('p'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('c'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  DROP(5);
 L_WRITE_SOB_CHAR_EXIT:
  POP(R1);
  POP(FP);
  RETURN;
  
