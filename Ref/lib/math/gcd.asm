GCD:
    PUSH(FP);
    MOV(FP, SP);
    PUSH(R1);
    PUSH(R2);
    MOV(R0,FPARG(0));
    MOV(R1,FPARG(1));
GCD_START_LOP:
    CMP(R1,IMM(0));
    JUMP_EQ(GCD_END_LOP);
    MOV(R2,R0);
    MOV(R0,R1);
    REM(R2,R1);
    MOV(R1,R2);
    JUMP(GCD_START_LOP);
GCD_END_LOP:	

	CMP(R0 , IMM(0));
	JUMP_GE(GCD_END);
	MUL(R0 ,IMM(-1));
GCD_END:
    POP(R2);
    POP(R1);
    POP(FP);
    RETURN;