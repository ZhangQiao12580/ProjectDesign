DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV Ax,1023

    CALL TRANSB
    
    MOV AH,4CH
    INT 21H
    
    TRANSB PROC	;AXת2���ƣ���ڲ���:AX
    	PUSH BX
    	PUSH CX
    	PUSH DX
    	
    	MOV BL,0
    	MOV BH,0
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
    	CALL FUN
    	ADD BH,1
    	CMP BH,16
    	JB LAST
    	
    	POP DX
    	POP CX
    	POP BX
    	RET
    TRANSB ENDP
    
    X0 PROC
	    PUSH AX
	    PUSH DX
	    MOV DL,'0'
	    MOV AH,2
	    INT 21H
	    POP DX
	    POP AX
	    RET
    X0 ENDP
    
    X1 PROC
    	PUSH AX
	    PUSH DX
	    MOV DL,'1'
	    MOV AH,2
	    INT 21H
	    POP DX
	    POP AX
	    RET
    X1 ENDP
    
    FUN PROC ;��ʾAX�Ĵ�����������ڲ���AX�����ڲ�����
    
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

