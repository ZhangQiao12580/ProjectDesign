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
    
    MOV AX,-1234
    CALL FUNPRO

    MOV AH,4CH
    INT 21H
    
    FUNPRO PROC	;AX
    	PUSH BX
    	PUSH CX
    	PUSH DX
    	
    	TEST AX,8000H
    	JZ ZHENG
    	
		MOV DL,'-'
    	PUSH AX
    	MOV AH,2
    	INT 21H
    	POP AX
    	NEG AX
    	
		ZHENG:
			CALL FUN
    	POP DX
    	POP CX
    	POP BX
    	RET
    FUNPRO ENDP
    
    FUN PROC ;显示AX寄存器函数，入口参数AX，出口参数无
    
    	PUSH BX
    	PUSH CX
    	PUSH DX
    	MOV CL,1
    	MOV BL,10
    	
		BIJIAO1:
		    DIV BL
		    MOV DL,AH
		    PUSH DX
		    ADD CL,1
		    MOV AH,0
		    CMP AL,0
		    JE PRINT
		    JMP BIJIAO1
	
		PRINT:
			CMP CL,1
			JE LAST1
			POP DX
			ADD DL,48
			MOV AH,2
			INT 21H
			SUB CL,1
			JMP PRINT
			
		LAST1:
		POP DX
		POP CX
		POP BX
		    RET
	FUN ENDP
CODES ENDS
    END START
