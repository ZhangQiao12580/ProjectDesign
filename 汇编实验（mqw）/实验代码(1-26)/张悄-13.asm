DATAS SEGMENT
    A1 DW 10 DUP(?);�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV SI,OFFSET A1
    MOV BL,10
    CALL WRITE
    
    MOV SI,OFFSET A1
    CALL GET
    
    MOV AH,4CH
    INT 21H
    
    WRITE PROC	;д�뺯������ڲ�����SI BL
    	PUSH AX
    	PUSH CX
    	PUSH DX
    	
    	MOV CL,1
    	PANDUAN:
    		CMP CL,BL
    		JA LAST
    		ADD CL,1
    		CALL SCANF
    		MOV [SI],AX
    		ADD SI,2
    		JMP PANDUAN
    LAST:
    	POP DX
    	POP CX
    	POP AX
    	RET
    WRITE ENDP
    

	SCANF PROC	;���뺯�� ��ڲ����ޣ����ڲ���AX
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
    
    GET PROC	;��ʾ������������ڲ���SI,BL
	    	PUSH CX
	    	PUSH AX
	    	PUSH DX
	    	
	    	MOV CL,1
	    	MOV DH,0
	    	MOV DL,0
	    BIJIAO:
			ADD SI,DX
			MOV AX,[SI]
			SUB SI,DX	;�ָ�SI�Ĵ���
			CALL FUN
			
			PUSH DX
			MOV DL,','	;��ӡ����
			MOV AH,2
			INT 21H
			POP DX
			
			ADD CL,1
			ADD DL,2
			CMP CL,BL
			JA LAST
			JMP BIJIAO
	    LAST:
	    	POP DX
	    	POP AX 
	    	POP CX
	    	RET
    GET ENDP
    
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



