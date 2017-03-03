
(define code-gen-lambda-opt-body
  (lambda (sexpr envLevel paramsLevel)
    (let ((numberOfParams (length (cadr sexpr)))
          (body (cadddr sexpr))
          (loopLabel (string-append "optLambdaCopyLabel" (labelNumberInString)))
          (loopEndLabel (string-append "optLambdaCopyEndLabel" (labelNumberInString)))
          (pushLabel (string-append "optLambdaCopyLabel" (labelNumberInString)))
          (pushEndLabel (string-append "optLambdaCopyEndLabel" (labelNumberInString)))
          (EndLabel (string-append "EndLabel" (labelNumberInString)))
          (noParamsLabel (string-append "noParamsLabel" (labelNumberInString)))
          (parameterLoopEndLabel (string-append "closureParameterLoopEndLabel" (labelNumberInString)))
          (pushLoopLabel (string-append "closurePushLoopLabel" (labelNumberInString)))
          )
      (string-append
      "/* lambda var body */" nl
      "/* pop old fp */"nl
      "POP(R10);"nl
      "/* pop return address */"nl
      "POP(R11);"nl
      "/* pop env */"nl
      "POP(R12);"nl
      "/* pop number of arguments */"nl
      "POP(R13);"nl nl

      
      "MOV(R5,R13);" nl
      "ADD(R5, IMM("(number->string (* -1 numberOfParams))"));" nl
      "/* no params */" nl
      "CMP(R5,IMM(0));" nl
      "JUMP_EQ("noParamsLabel");" nl
      "/* with params */" nl
      "MOV(R14,R13);" nl
      "MOV(R15,R13);" nl
      "MOV(R4, IMM(0));" nl
      "ADD(R15,IMM(1));" nl
      "ADD(R14,IMM(2));" nl
      pushLoopLabel ":" nl
      "CMP(R4,R5);"nl
      "JUMP_EQ("parameterLoopEndLabel");"nl
      "MOV(R1, FPARG(R14));" nl
      "PUSH(R1);" nl
      "MOV(R1, FPARG(R15));" nl
      "PUSH(R1);" nl
      "CALL(MAKE_SOB_PAIR);" nl
      "DROP(IMM(2));" nl
      "MOV(FPARG(R14),R0);" nl
      ;"INFO;" nl
      "INCR(R4);" nl
      "DECR(R15);" nl
      "JUMP("pushLoopLabel");"
      parameterLoopEndLabel ":" nl
      ;"CALL(PRINT_R0);" nl 
      "MOV(R15, IMM("(number->string (+ 2 numberOfParams))"));" nl
      "MOV(FPARG(R15), FPARG(R14));" nl
      ;"INFO;" nl
      "JUMP("EndLabel");" nl
      nl
      noParamsLabel ":" nl
      "MOV(R1, "(number->string (getConstAddress '()))")" nl
      "MOV(FPARG(IMM(1)),R1);" nl
      EndLabel ":" nl
      "PUSH(R13);" nl
      "PUSH(R12);" nl
      "PUSH(R11);" nl
      "PUSH(R10);" nl
      "MOV(FP, SP);" nl
      "/* code-gen on body */" nl
      (code-gen body (+ 1 envLevel) numberOfParams)
))))

