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
    
    	CALL SCANF
	CALL FUN

    	MOV AH,4CH
		INT 21H
    	
    SCANF PROC
    	PUSH BX
    	PUSH CX
    	PUSH DX
    	
    	MOV AH,0
    	MOV AL,0
    	PUSH AX
    	MOV BL,10
    	MOV BH,0
    	
    	JISUAN:	    	
	    	MOV AH,1
	    	INT 21H
	    	CMP AL,'0'
	    	JB ZHIXING
	    	CMP AL,'9'
	    	JA ZHIXING
	    	
	    	MOV CH,AL
	    	
	    	POP AX
	    	MUL BX
	    	MOV DX,AX

	    	MOV AH,0
	    	MOV AL,CH
	    	SUB AL,48
	    	ADD DX,AX
	    	PUSH DX
	    	JMP JISUAN
    	ZHIXING:
    		POP AX
    		
    	
    		POP DX
    		POP CX
    		POP BX
    	RET
    SCANF ENDP
    	
    FUN PROC
    
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



