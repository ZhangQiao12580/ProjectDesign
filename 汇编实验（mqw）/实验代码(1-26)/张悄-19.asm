DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV AX,65534

    CALL TRANSB
    
    MOV AH,4CH
    INT 21H
    
    TRANSB PROC	;AX转16进制，入口参数:AX
    	PUSH BX
    	PUSH CX
    	PUSH DX
    	
    	MOV BL,0
    	MOV BH,8	;转16进制乘数
    	BIJIAO:
    		TEST AL,01H
    		JZ PRINT0
    		JNZ PRINT1
    		
    		PRINT0:
	    		MOV CX,0
	    		PUSH CX
	    		JMP THISEND
    		
    		PRINT1:
    			MOV CX,1
	    		PUSH CX

	    	THISEND:
    			ADD BL,1
    			CMP BL,16
    			JE LAST
    			ROR AX,1
    			JMP BIJIAO
    	LAST:
	    	POP AX
	    	
	    	MUL BH
	    	MOV CL,AL
	    	ADD CH,CL
	    	
	    	MOV AH,0
	    	MOV AL,BH
	    	MOV BH,2
	    	DIV BH
	    	MOV BH,AL
	    	
	    	CMP BH,0
	    	JE XIANSHI16
	    	JNE OTHER
	    	
	    	XIANSHI16:
	    		MOV CL,CH
	    		CALL TRANSHELP
	    		MOV BH,8
	    		MOV CH,0
	    		
	    	OTHER:
	    	SUB BL,1
	    	CMP BL,0
	    	JA LAST
    	
    	POP DX
    	POP CX
    	POP BX
    	RET
    TRANSB ENDP
    
    TRANSHELP PROC ;CL
	    PUSH AX
	    PUSH BX
	    PUSH DX
	    
	    CMP CL,10
	    JB ZHIJIE
		    SUB CL,10
		    MOV DL,CL
		    ADD DL,65
		    MOV AH,2
		    INT 21H
	    	JMP LAST
	    	
	    ZHIJIE:
	    	MOV DL,CL
	    	ADD DL,48
	    	MOV AH,2
	    	INT 21H
	    
	    LAST:
		    POP DX
		    POP BX
		    POP AX
		    RET
    TRANSHELP ENDP
    
CODES ENDS
    END START



