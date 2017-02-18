 MAKE_SOB_FRAC:

  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);

  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);

  MOV(R4, R0);// R4 has 3 slots
  MOV(R3, FPARG(0));
  MOV(R2, FPARG(1));

  PUSH(R2);
  PUSH(R3);

  CALL(GCD);
  DROP(2);

  DIV(R2, R0);
  DIV(R3, R0);

  MOV(INDD(R4, 0), T_FRAC);
  MOV(INDD(R4, 1), R2); // 1
  MOV(INDD(R4, 2), R3); // 2
  MOV(R0, R4);
  POP(R4);
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;


GCD:



  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

MOV(R2, FPARG(0));  //1
MOV(R1, FPARG(1)); //2

GCD_LOOP:

MOV(R3, R1);
REM(R3, R2);
CMP(R3, IMM(0));
JUMP_EQ(GCD_EXIT);
MOV(R1, R2);
MOV(R2, R3);
JUMP(GCD_LOOP);

GCD_EXIT:
MOV(R0, R2);


POP(R3);
POP(R2);
POP(R1);
POP(FP);



RETURN;

L_SECOND_ARG_CANNOT_BE_ZERO:








