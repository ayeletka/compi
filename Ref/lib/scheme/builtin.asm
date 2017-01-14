GENERAL_ERROR:	  
  PUSH(IMM('\n'));
  CALL(PUTCHAR);
  PUSH(IMM('g'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('n'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('l'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('o'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('s'));
  CALL(PUTCHAR);
  PUSH(IMM('a'));
  CALL(PUTCHAR);
  PUSH(IMM('c'));
  CALL(PUTCHAR);
  PUSH(IMM('u'));
  CALL(PUTCHAR);
  PUSH(IMM('r'));
  CALL(PUTCHAR);
  PUSH(IMM('e'));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(34);
  CALL(NEWLINE);
  HALT;
/*---------------------------------------------------------------------*/ 
APPLY:
  
  PUSH(FP);
  MOV(FP, SP);  
  PUSH(R1)
  PUSH(R2)
  PUSH(R3)
  PUSH(R4)
  PUSH(R5)
  PUSH(R6)
  PUSH(R7)
  PUSH(R8)
  PUSH(R9)
  PUSH(R10)


		  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(2));
  JUMP_LT(GENERAL_ERROR);
  

  CMP(IND(STACK(FP - 5)) ,T_CLOSURE);
  JUMP_NE(GENERAL_ERROR);
  
  CMP( IND(STACK(FP - 4 - R1)) ,T_PAIR);
  JUMP_EQ(APPLY_VALID);
  CMP( IND(STACK(FP - 4 - R1)) ,T_NIL);
  JUMP_EQ(APPLY_VALID);  
  JUMP(GENERAL_ERROR);
  
APPLY_VALID:  
  
  MOV(R2 , R1 - 2);  
  PUSH(R2);
  CALL(MALLOC);
  DROP(IMM(1));
  MOV(R8 ,R0);  
  MOV(R4 ,IMM(0));
APPLY_OBJECTS_LOOP:
  CMP(R2 , R4);
  JUMP_LE(APPLY_OBJECTS_LOOP_CONT);
  MOV(INDD(R8 , R4) ,STACK(FP - 6 - R4)) ;
  INCR(R4);
  JUMP(APPLY_OBJECTS_LOOP);

APPLY_OBJECTS_LOOP_CONT:  
  MOV( R5,STACK(FP - 4 - R1));
  MOV(R3, IMM(0));
  
APPLY_LIST_SIZE_LOOP:  
  CMP(IND(R5) , T_NIL);
  JUMP_EQ(APPLY_LIST_SIZE_LOOP_CONT);  
  MOV(R5  , INDD(R5 , 2));
  INCR(R3);
  JUMP( APPLY_LIST_SIZE_LOOP) ;

APPLY_LIST_SIZE_LOOP_CONT:
  PUSH(R3);
  CALL(MALLOC);
  DROP(IMM(1));
  MOV(R9 ,R0);  
  MOV(R4 ,IMM(0)); 
  MOV( R5,STACK(FP - 4 - R1));  
GLOBAL_FUNC_APPLY_LIST_OBJ_LOOP : 
  CMP(R3 , R4);
  JUMP_LE(APPLY_LIST_OBJ_LOOP_CONT);
  
  CMP(IND(R5) , T_NIL);
  JUMP_EQ(GENERAL_ERROR);    
  
  MOV(INDD(R9 , R4) ,INDD(R5 , 1)) ;
  MOV(R5  , INDD(R5 , 2));  
  INCR(R4);
  JUMP(GLOBAL_FUNC_APPLY_LIST_OBJ_LOOP);

APPLY_LIST_OBJ_LOOP_CONT: 


  PUSH(IMM(9999999));
  MOV(R4 ,IMM(0)); 
APPLY_LIST_OBJ_PUSH_LOOP:
  CMP(R3 , R4);
  JUMP_LE(APPLY_LIST_OBJ_PUSH_LOOP_CONT);
  PUSH(INDD(R9 , R3 -1 -R4));
  INCR(R4);
  JUMP(APPLY_LIST_OBJ_PUSH_LOOP);
APPLY_LIST_OBJ_PUSH_LOOP_CONT:  

  MOV(R4 ,IMM(0)); 
APPLY_OBJ_PUSH_LOOP:
  CMP(R2 , R4);
  JUMP_LE(APPLY_OBJ_PUSH_LOOP_CONT);
  PUSH(INDD(R8 , R2 -1 -R4));
  INCR(R4);
  JUMP(APPLY_OBJ_PUSH_LOOP);
  
APPLY_OBJ_PUSH_LOOP_CONT:
  PUSH(IMM(R2+R3));
  MOV(R10 , STACK(FP - 5));
  PUSH(INDD(R10,1));  


  CALLA(INDD(R10,2));  
  DROP(IMM(1));
  POP(R1);
  DROP(R1);
  JUMP(APPLY_END);
  
APPLY_END: 

  POP(R1)
  POP(R2)
  POP(R3)
  POP(R4)
  POP(R5)
  POP(R6)
  POP(R7)
  POP(R8)
  POP(R9)
  POP(R10)
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/	
  OP_SMALLER:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_SMALLER_TRUE);  
  MOV(R2 , IMM(1));

OP_SMALLER_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_SMALLER_TRUE);
  MOV( R3 , STACK(FP - 4 - R2));
  MOV( R4 , STACK(FP - 5 - R2));
  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , INDD(R3 ,1));
  MOV(R6 , INDD(R3 ,2));
  
  MUL(R5 , INDD(R4 ,2));
  MUL(R6 , INDD(R4 ,1));
  CMP(R5 , R6 );
  JUMP_GE(OP_SMALLER_FALSE);  
  
  INCR(R2);
  JUMP(OP_SMALLER_LOOP);


OP_SMALLER_TRUE:
  MOV(R0, SOB_TRUE);
  JUMP(OP_SMALLER_END) ; 
  
OP_SMALLER_FALSE:
  MOV(R0, SOB_FALSE);
  
OP_SMALLER_END: 

  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
OP_EQUAL:
 
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_EQUAL_TRUE);  
  MOV(R2 , IMM(1));

OP_EQUAL_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_EQUAL_TRUE);
  MOV( R3 , STACK(FP - 4 - R2));
  MOV( R4 , STACK(FP - 5 - R2));
  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  CMP(INDD(R3 ,1) , INDD(R4 ,1));
  JUMP_NE(OP_EQUAL_FALSE);
  CMP(INDD(R3 ,2) , INDD(R4 ,2)); 
  JUMP_NE(OP_EQUAL_FALSE);   
  
  INCR(R2);
  JUMP(OP_EQUAL_LOOP);


OP_EQUAL_TRUE:
  MOV(R0, SOB_TRUE);
  JUMP(OP_EQUAL_END) ; 
  
OP_EQUAL_FALSE:
  MOV(R0, SOB_FALSE);
  
OP_EQUAL_END: 

  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;

/*---------------------------------------------------------------------*/

  OP_BIGGER:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_BIGGER_TRUE);  
  MOV(R2 , IMM(1));

OP_BIGGER_TRUE_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_BIGGER_TRUE);
  MOV( R3 , STACK(FP - 4 - R2));
  MOV( R4 , STACK(FP - 5 - R2));
  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , INDD(R3 ,1));
  MOV(R6 , INDD(R3 ,2));
  
  MUL(R5 , INDD(R4 ,2));
  MUL(R6 , INDD(R4 ,1));
  CMP(R5 , R6 );
  JUMP_LE(OP_BIGGER_FALSE);  
  
  INCR(R2);
  JUMP(OP_BIGGER_TRUE_LOOP);


OP_BIGGER_TRUE:
  MOV(R0, SOB_TRUE);
  JUMP(OP_BIGGER_END) ; 
  
OP_BIGGER_FALSE:
  MOV(R0, SOB_FALSE);
  
OP_BIGGER_END: 

  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
 OP_PLUS:  
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  PUSH(R7);
  PUSH(R8);
  PUSH(R9);
  
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(OP_PLUS_ZERO_OPEREND);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_PLUS_ONE_OPEREND);  

  MOV( R3 , STACK(FP - 5));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
  MOV( R2 , IMM(1));
  
OP_PLUS_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_PLUS_END);
  
  MOV( R4 , STACK(FP - 5 - R2));
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , R8);
  MOV(R6 , R9);
  MOV(R7 , R9);
  
  MUL(R5 , INDD(R4 ,2));
  MUL(R6 , INDD(R4 ,1));
  MUL(R7 , INDD(R4 ,2));  
  ADD(R5 , R6);
  
  PUSH(R5);
  PUSH(R7);
  CALL(GCD);
  DROP(IMM(2));
  
  DIV(R5,R0);
  DIV(R7,R0);
  
  MOV(R8,R5);
  MOV(R9,R7);
    
  INCR(R2);
  JUMP(OP_PLUS_LOOP);


  
OP_PLUS_ZERO_OPEREND:
  MOV(R8 , IMM(0));
  MOV(R9 , IMM(1));
  JUMP(OP_PLUS_END);
  
OP_PLUS_ONE_OPEREND:
  MOV( R3 , STACK(FP - 5 ));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
OP_PLUS_END: 
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), R8);
  MOV(INDD(R0, 2), R9); 
  
  
  POP(R9);
  POP(R8);
  POP(R7);
  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
  /*---------------------------------------------------------------------*/
  OP_DIV:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  PUSH(R7);
  PUSH(R8);
  PUSH(R9);
  
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(OP_DIV_ZERO_OPEREND);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_DIV_ONE_OPEREND);  

  MOV( R3 , STACK(FP - 5));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
  MOV( R2 , IMM(1));
  
OP_DIV_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_DIV_END);
  
  MOV( R4 , STACK(FP - 5 - R2));
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , R8);
  MOV(R6 , R9);
  
  MUL(R5 , INDD(R4 ,2));  
  MUL(R6 , INDD(R4 ,1));

  CMP(R6 ,IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  JUMP_GT(OP_DIV_LOOP_CONT);
  MUL( R5 , IMM(-1));
  MUL( R6 , IMM(-1));

OP_DIV_LOOP_CONT:  
  PUSH(R5);
  PUSH(R6);
  CALL(GCD);
  DROP(IMM(2));
  
  DIV(R5,R0);
  DIV(R6,R0);
  
  MOV(R8,R5);
  MOV(R9,R6);
    
  INCR(R2);
  JUMP(OP_DIV_LOOP);


  
OP_DIV_ZERO_OPEREND:
  JUMP(GENERAL_ERROR);
  
OP_DIV_ONE_OPEREND:
  MOV( R3 , STACK(FP - 5 ));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,2));
  MOV( R9 , INDD(R3 ,1));

  CMP( R9 , IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  JUMP_GT(OP_DIV_END);
  MUL( R8 , IMM(-1));
  MUL( R9 , IMM(-1));
  
OP_DIV_END: 
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), R8);
  MOV(INDD(R0, 2), R9); 
  
  
  POP(R9);
  POP(R8);
  POP(R7);
  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/
  OP_MUL:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  PUSH(R7);
  PUSH(R8);
  PUSH(R9);		

  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(OP_MUL_ZERO_OPEREND);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_MUL_ONE_OPEREND);  
  MOV( R3 , STACK(FP - 5));  
  CMP(IND(R3) , T_NUMBER);
   
		  

  JUMP_NE(GENERAL_ERROR);

  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
  MOV( R2 , IMM(1));
  
OP_MUL_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_MUL_END);
  
  MOV( R4 , STACK(FP - 5 - R2));
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , R8);
  MOV(R6 , R9);
  
  MUL(R5 , INDD(R4 ,1));
  MUL(R6 , INDD(R4 ,2));  
  
  PUSH(R5);
  PUSH(R6);
  CALL(GCD);
  DROP(IMM(2));
  
  DIV(R5,R0);
  DIV(R6,R0);
  
  MOV(R8,R5);
  MOV(R9,R6);
    
  INCR(R2);
  JUMP(OP_MUL_LOOP);


  
OP_MUL_ZERO_OPEREND:
  MOV(R8 , IMM(1));
  MOV(R9 , IMM(1));
  JUMP(OP_MUL_END);
  
OP_MUL_ONE_OPEREND:
  MOV( R3 , STACK(FP - 5 ));  
  CMP(IND(R3) , T_NUMBER);

  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
OP_MUL_END: 
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), R8);
  MOV(INDD(R0, 2), R9); 
  
  POP(R9);
  POP(R8);
  POP(R7);
  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
  
  /*---------------------------------------------------------------------*/
  OP_MINUS:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  PUSH(R5);
  PUSH(R6);
  PUSH(R7);
  PUSH(R8);
  PUSH(R9);
  
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(OP_MINUS_ZERO_OPEREND);
  CMP(R1,IMM(1));
  JUMP_EQ(OP_MINUS_ONE_OPEREND);  

  MOV( R3 , STACK(FP - 5));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MOV( R9 , INDD(R3 ,2));
  
  MOV( R2 , IMM(1));
  
OP_MINUS_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(OP_MINUS_END);
  
  MOV( R4 , STACK(FP - 5 - R2));
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R5 , R8);
  MOV(R6 , R9);
  MOV(R7 , R9);
  
  MUL(R5 , INDD(R4 ,2));
  MUL(R6 , INDD(R4 ,1));
  MUL(R7 , INDD(R4 ,2));  
  SUB(R5 , R6);
  
  PUSH(R5);
  PUSH(R7);
  CALL(GCD);
  DROP(IMM(2));
  
  DIV(R5,R0);
  DIV(R7,R0);
  
  MOV(R8,R5);
  MOV(R9,R7);
    
  INCR(R2);
  JUMP(OP_MINUS_LOOP);
  
OP_MINUS_ZERO_OPEREND:
  JUMP(GENERAL_ERROR);
  
OP_MINUS_ONE_OPEREND:
  MOV( R3 , STACK(FP - 5 ));  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  MOV( R8 , INDD(R3 ,1));
  MUL( R8 , IMM(-1)); 
  MOV( R9 , INDD(R3 ,2));
  
OP_MINUS_END: 
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), R8);
  MOV(INDD(R0, 2), R9); 
  
  
  POP(R9);
  POP(R8);
  POP(R7);
  POP(R6);
  POP(R5);
  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
 /*---------------------------------------------------------------------*/ 
 
IS_BOOLEAN:
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_BOOL);
  JUMP_EQ(IS_BOOLEAN_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_BOOLEAN_EXIT);
 IS_BOOLEAN_TRUE:
  MOV(R0, SOB_TRUE);
 IS_BOOLEAN_EXIT:
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
   CAR: 
	PUSH(FP);
	MOV(FP , SP);
	PUSH(R1)
	
	MOV(R1, FPARG(2));
	MOV(R0, INDD(R1 , 1));
	
	POP(R1)
	POP(FP);
	RETURN ;
/*---------------------------------------------------------------------*/
CDR:	
	PUSH(FP);
	MOV(FP , SP);
	PUSH(R1)
	
	MOV(R1 , FPARG(2));
	MOV(R0 , INDD(R1 , 2));
	
	POP(R1)
	POP(FP);
	RETURN ;
/*---------------------------------------------------------------------*/
CHAR_TO_INT:
	PUSH(FP);
	MOV(FP, SP);
	PUSH(R1);
	
	MOV(R1, FPARG(2));
	CMP(IND(R1), T_CHAR);
	JUMP_NE(GENERAL_ERROR);
	
	
	PUSH(IMM(3));
	CALL(MALLOC);
	DROP(1);
	MOV(IND(R0), T_NUMBER);
	MOV(INDD(R0, 1), INDD(R1,1));
	MOV(INDD(R0, 2), IMM(1)); 
	
	POP(R1);
	POP(FP);
	RETURN;	
/*---------------------------------------------------------------------*/
IS_CHAR:
 PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_CHAR);
  JUMP_EQ(IS_CHAR_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_CHAR_EXIT);
 IS_CHAR_TRUE:
  MOV(R0, SOB_TRUE);
 IS_CHAR_EXIT:
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/ 
CONS: 
  PUSH(FP);
  MOV(FP, SP);
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_PAIR);
  MOV(INDD(R0, 1), FPARG(2));
  MOV(INDD(R0, 2), FPARG(3));
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
IS_EQ:	
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  
  MOV(R1 , STACK(FP - 4)); 
  CMP(R1 ,IMM(0));
  JUMP_EQ(GENERAL_ERROR);
  CMP(R1,IMM(1));
  JUMP_EQ(IS_EQ_TRUE);  
  MOV(R2 , IMM(1));

IS_EQ_LOOP:
  CMP(R1 ,R2);
  JUMP_LE(IS_EQ_TRUE);
  MOV( R3 , STACK(FP - 4 - R2));
  MOV( R4 , STACK(FP - 5 - R2));
  
  CMP(IND(R3) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(IND(R4) , T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  
  CMP(INDD(R3 ,1) , INDD(R4 ,1));
  JUMP_NE(IS_EQ_FALSE);
  CMP(INDD(R3 ,2) , INDD(R4 ,2)); 
  JUMP_NE(IS_EQ_FALSE);   
  
  INCR(R2);
  JUMP(IS_EQ_LOOP);


IS_EQ_TRUE:
  MOV(R0, SOB_TRUE);
  JUMP(IS_EQ_END) ; 
  
IS_EQ_FALSE:
  MOV(R0, SOB_FALSE);
  
IS_EQ_END: 

  POP(R4); 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
IS_INT:	
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_NUMBER);
  JUMP_EQ(IS_INT_TRUE_1);
  MOV(R0, SOB_FALSE);
  JUMP(IS_INT_EXIT);
  
 IS_INT_TRUE_1:
  CMP(INDD(R0 ,2),1);
  JUMP_EQ(IS_INT_TRUE_2);
  MOV(R0, SOB_FALSE);
  JUMP(IS_INT_EXIT);
  
 IS_INT_TRUE_2:
  MOV(R0, SOB_TRUE);
  
 IS_INT_EXIT:
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/
INT_TO_CHAR:
	  PUSH(FP);
	  MOV(FP, SP);
	  PUSH(R1);
	  
	  MOV(R1, FPARG(2));
	  CMP(IND(R1), T_NUMBER);
	  JUMP_NE(GENERAL_ERROR);
	  CMP(INDD(R1 ,2), IMM(1));
	  JUMP_NE(GENERAL_ERROR);
	  
	  PUSH(IMM(2));
	  CALL(MALLOC);
	  DROP(1);
	  MOV(IND(R0), T_CHAR);
	  MOV(INDD(R0, 1), INDD(R1,1));
	  
	  POP(R1);
	  POP(FP);
	  RETURN;
  
/*---------------------------------------------------------------------*/
MAKE_STRING: 
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R1 , STACK(FP - 4));
  CMP(R1 ,1);
  JUMP_EQ(MAKE_STRING_NO_CHAR_INPUT);
  CMP(R1 ,2);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R2 , STACK(FP - 6));
  CMP(IND(R2) ,T_CHAR);
  JUMP_NE(GENERAL_ERROR);
  MOV(R2 ,INDD(R2,1));
  JUMP(MAKE_STRING_CONT);
  
MAKE_STRING_NO_CHAR_INPUT:
  MOV(R2 , IMM(0));
  
MAKE_STRING_CONT:  
  MOV(R1 , STACK(FP - 5));
  
  CMP(IND(R1) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR);

  CMP(INDD(R1 , 2) ,IMM(1));
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1,INDD(R1,1));
  
  PUSH(R1 + 2);
  CALL(MALLOC);
  DROP(IMM(1));
  MOV(IND(R0) , T_STRING);
  MOV(INDD(R0,1) , R1);
  
  MOV(R3 , IMM(0));

MAKE_STRING_LOOP:
  CMP(R1 ,R3);
  JUMP_LE(MAKE_STRING_END);
  MOV(INDD(R0 , R3+2) , R2);
  INCR(R3);
  JUMP(MAKE_STRING_LOOP);
  
MAKE_STRING_END:  
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;

/*---------------------------------------------------------------------*/
MAKE_VECTOR: 
 PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R1 , STACK(FP - 4));
  CMP(R1 ,1);
  JUMP_EQ(MAKE_VECTOR_NO_INPUT);
  CMP(R1 ,2);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R2 , STACK(FP - 6));
  JUMP(MAKE_VECTOR_CONT);
  
MAKE_VECTOR_NO_INPUT:
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), IMM(0));
  MOV(INDD(R0, 2), IMM(1)); 
  MOV(R2,R0)
  
MAKE_VECTOR_CONT:  
  MOV(R1 , STACK(FP - 5));
  
  CMP(IND(R1) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR);

  CMP(INDD(R1 , 2) ,IMM(1));
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1,INDD(R1,1));
  
  PUSH(R1 + 2);
  CALL(MALLOC);
  DROP(IMM(1));
  MOV(IND(R0) , T_VECTOR);
  MOV(INDD(R0,1) , R1);  
  MOV(R3 , IMM(0));

MAKE_VECTOR_LOOP:
  CMP(R1 ,R3);
  JUMP_LE(MAKE_VECTOR_END);
  MOV(INDD(R0 , R3+2) , R2);
  INCR(R3);
  JUMP(MAKE_VECTOR_LOOP);
  
MAKE_VECTOR_END:  
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
IS_NULL:
	  PUSH(FP);
	  MOV(FP, SP);
	  MOV(R0, FPARG(2));
	  CMP(IND(R0), T_NIL);
	  JUMP_EQ(IS_NULL_TRUE);
	  MOV(R0, SOB_FALSE);
	  JUMP(IS_NULL_EXIT);
	IS_NULL_TRUE:
	  MOV(R0, SOB_TRUE);
	IS_NULL_EXIT:
	  POP(FP);
	  RETURN;
/*---------------------------------------------------------------------*/
IS_NUMBER:	 
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_NUMBER);
  JUMP_EQ(IS_NUMBER_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_NUMBER_EXIT);
 IS_NUMBER_TRUE:
  MOV(R0, SOB_TRUE);
 IS_NUMBER_EXIT:
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
IS_PAIR: 
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_PAIR);
  JUMP_EQ(IS_PAIR_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_PAIR_EXIT);
 IS_PAIR_TRUE:
  MOV(R0, SOB_TRUE);
 IS_PAIR_EXIT:
  POP(FP);
  RETURN;


/*---------------------------------------------------------------------*/
IS_PROC:	
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_CLOSURE);
  JUMP_EQ(IS_PROC_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_PROC_EXIT);
 IS_PROC_TRUE:
  MOV(R0, SOB_TRUE);
 IS_PROC_EXIT:
  POP(FP);
  RETURN;


/*---------------------------------------------------------------------*/ 
REMAINDER:	
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R1 , STACK(FP - 4));
  CMP(R1 , 2);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5));
  CMP(IND(R1) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(INDD(R1 , 2) ,IMM(1));
  JUMP_NE(GENERAL_ERROR);
  MOV(R1 , INDD(R1 , 1));


  MOV(R2 , STACK(FP - 6));
  CMP(IND(R2) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR);
  CMP(INDD(R2 , 2) ,IMM(1));
  JUMP_NE(GENERAL_ERROR);
  MOV(R2 , INDD(R2 , 1));  
 
  REM(R1 , R2);
  
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), R1);
  MOV(INDD(R0, 2), IMM(1)); 

 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/
SET_CAR:
	 PUSH(FP);  
	 MOV(FP, SP);    
	 
	 CMP(IND(FPARG(2)), T_PAIR);
	 JUMP_NE(GENERAL_ERROR);
	 MOV(INDD(FPARG(2), 1), FPARG(3)); 
	 MOV(R0, SOB_VOID);
	 MOV(SP, FP);     
	 POP(FP);  
	 RETURN;    
/*---------------------------------------------------------------------*/	
  SET_CDR:
	 PUSH(FP);  
	 MOV(FP, SP);    
	 
	 CMP(IND(FPARG(2)), T_PAIR);
	 JUMP_NE(GENERAL_ERROR);
	 MOV(INDD(FPARG(2), 2), FPARG(3));
	 MOV(R0, SOB_VOID);
	 MOV(SP, FP);     
	 POP(FP);  
	 RETURN;    
/*---------------------------------------------------------------------*/
STRING_LENGTH:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 ,1);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5))
  CMP(IND(R1) ,T_STRING);
  JUMP_NE(GENERAL_ERROR);
    
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), INDD(R1,1));
  MOV(INDD(R0, 2), IMM(1)); 
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/
STRING_REF: 
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 ,2);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5));
  CMP(IND(R1) ,T_STRING);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R2 , STACK(FP - 6));
  CMP(IND(R2) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR); 
  CMP(INDD(R2 , 2) ,1);
  JUMP_NE(GENERAL_ERROR); 
  MOV(R2, INDD(R2 , 1)); 
  
  CMP(INDD(R1 , 1) ,R2);
  JUMP_LE(GENERAL_ERROR); 

  
  PUSH(IMM(2));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_CHAR);
  MOV(INDD(R0, 1), INDD(R1,2 + R2));
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/
STRING_SET:
 
	PUSH(FP);   
	MOV(FP,SP);
	PUSH(R1);
	PUSH(R2);
	PUSH(R3);
	PUSH(R4);
	
	MOV(R1,FPARG(2)); 
	MOV(R2,FPARG(3)); 
	MOV(R3,FPARG(4)); 
	
	CMP(INDD(R2, 1), INDD(R1, 1)); 
	JUMP_GE(GENERAL_ERROR);
	
	CMP(IMM(0), INDD(R2,1)); 
	JUMP_GT(GENERAL_ERROR);
	
	MOV(R4, INDD(R2,1) + 2);
	MOV(INDD(R1, R4),INDD(R3,1));
	MOV(R0,SOB_VOID);
	
	POP(R4);
	POP(R5);
	POP(R2);	
	POP(R1);
	POP(FP);
	RETURN;  
  
/*---------------------------------------------------------------------*/
STRING_TO_SYMBOL:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 , 1);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5));
  CMP(IND(R1) ,T_STRING);
  JUMP_NE(GENERAL_ERROR);

  PUSH(R1);
  
  DROP(1);
  
  MOV(R2,R0);
  PUSH(IMM(2));
  CALL(MALLOC);
  DROP(1);
  MOV(INDD(R0,0),T_SYMBOL);
  MOV(INDD(R0,1),R2);
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/ 
IS_STRING:
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_STRING);
  JUMP_EQ(IS_STRING_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_STRING_EXIT);
 IS_STRING_TRUE:
  MOV(R0, SOB_TRUE);
 IS_STRING_EXIT:
  POP(FP);
  RETURN;

/*---------------------------------------------------------------------*/
IS_SYMBOL: 
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_SYMBOL);
  JUMP_EQ(IS_SYMBOL_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_SYMBOL_EXIT);
 IS_SYMBOL_TRUE:
  MOV(R0, SOB_TRUE);
 IS_SYMBOL_EXIT:
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/
SYMBOL_TO_STRING:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 , 1);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5));
  CMP(IND(R1) ,T_SYMBOL);
  JUMP_NE(GENERAL_ERROR);

  MOV(R1 , INDD(R1 ,1));
  MOV(R1 ,IND(R1))
  CMP(IND(R1) ,T_STRING);
  JUMP_NE(GENERAL_ERROR); 

  MOV(R0 , R1);
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/ 
VECTOR_LENGTH:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 ,1);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5))
  CMP(IND(R1) ,T_VECTOR);
  JUMP_NE(GENERAL_ERROR);
    
  PUSH(IMM(3));
  CALL(MALLOC);
  DROP(1);
  MOV(IND(R0), T_NUMBER);
  MOV(INDD(R0, 1), INDD(R1,1));
  MOV(INDD(R0, 2), IMM(1)); 
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/	 	 
 VECTOR_REF:
  PUSH(FP);
  MOV(FP, SP);
  PUSH(R1);
  PUSH(R2);
  PUSH(R3);

  MOV(R2 , STACK(FP - 4));
  CMP(R2 ,2);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R1 , STACK(FP - 5));
  CMP(IND(R1) ,T_VECTOR);
  JUMP_NE(GENERAL_ERROR);
  
  MOV(R2 , STACK(FP - 6));
  CMP(IND(R2) ,T_NUMBER);
  JUMP_NE(GENERAL_ERROR); 
  CMP(INDD(R2 , 2) ,1);
  JUMP_NE(GENERAL_ERROR); 
  MOV(R2, INDD(R2 , 1)); 
  
  CMP(INDD(R1 , 1) ,R2);
  JUMP_LE(GENERAL_ERROR); 

  MOV(R0, INDD(R1,2 + R2));
 
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;
/*---------------------------------------------------------------------*/	
VECTOR_SET:
	PUSH(FP);   
	MOV(FP, SP);  
	PUSH(R1);
	PUSH(R2);
	PUSH(R3);
	PUSH(R4);
	
	MOV(R1,FPARG(2)); 
	MOV(R2,FPARG(3)); 
	MOV(R3,FPARG(4)); 

	CMP(INDD(R1,1),INDD(R2,1)); 
	JUMP_LE(GENERAL_ERROR);
	
	CMP(INDD(R2,1),IMM(0)); 
	JUMP_LT(GENERAL_ERROR);
	MOV(R4, INDD(R2, 1));
	MOV(INDD(R1, R4 + 2),R3); 
	ADD(R4, R1 + 2); 	
	MOV(IND(R4),R3);
		
	
	MOV(R0,SOB_VOID)
	POP(R4); 
	POP(R3);
	POP(R2);
	POP(R1);
	POP(FP);  
	RETURN;     
/*---------------------------------------------------------------------*/
IS_VECTOR: 	
  PUSH(FP);
  MOV(FP, SP);
  MOV(R0, FPARG(2));
  CMP(IND(R0), T_VECTOR);
  JUMP_EQ(IS_VECTOR_TRUE);
  MOV(R0, SOB_FALSE);
  JUMP(IS_VECTOR_EXIT);
 IS_VECTOR_TRUE:
  MOV(R0, SOB_TRUE);
 IS_VECTOR_EXIT:
  POP(FP);
  RETURN;
  
/*---------------------------------------------------------------------*/ 
