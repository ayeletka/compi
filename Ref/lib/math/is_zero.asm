/* is_zero.asm
 * R0 <- TRUE, FALSE -- depending on whether ARG[0] is zero
 *
 * Programmer: Mayer Goldberg, 2010
 */

 IS_ZERO:
  CMP(STARG(0), IMM(0));
  JUMP_NE(L_IS_ZERO_F);
  MOV(R0, SOB_TRUE);
  RETURN;
 L_IS_ZERO_F:
  MOV(R0, SOB_FALSE);
  RETURN;
