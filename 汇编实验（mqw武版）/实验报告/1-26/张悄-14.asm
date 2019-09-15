DATAS SEGMENT
    A1 DW 23,3,34,2,461,78,41,58,6,14;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV BL,10
    MOV SI,OFFSET A1
    
    CALL ORDER
    
    CALL GET
    
    MOV AH,4CH
    INT 21H
    
    ORDER PROC	;排序SI,BL
    	PUSH AX
    	PUSH CX
    	PUSH DX
    	
    	PUSH SI	;保存初始化的SI
    	
	    	BEGAN:
	    		POP SI
	    		MOV CH,2
	    		PUSH SI
    		PANDUAN:
    			CMP CH,BL
    			JA LAST
    			
	    		MOV AX,[SI]
	    		ADD SI,2
	    		MOV DX,[SI]
	    		CMP AX,DX
	    		JA JIAOHUAN
	    		ADD CH,1
	    		JMP PANDUAN
	    		
    		JIAOHUAN:
    			SUB SI,2
    			CALL SWAP
    			JMP BEGAN
    		
    	LAST:
    		POP SI
    		POP DX
    		POP CX
    		POP AX
    		RET
    ORDER ENDP
    
    SWAP PROC	;交换SI
    	PUSH AX
    	PUSH CX
    	
    	MOV AX,[SI]
    	ADD SI,2
    	MOV CX,[SI]
    	MOV [SI],AX
    	SUB SI,2
    	MOV [SI],CX
    	
    	POP CX
    	POP AX
    		RET
    
    SWAP ENDP
    
    GET PROC	;显示变量函数，入口参数SI,BL
	    	PUSH CX
	    	PUSH AX
	    	PUSH DX
	    	
	    	MOV CL,1
	    	MOV DH,0
	    	MOV DL,0
	    BIJIAO:
			ADD SI,DX
			MOV AX,[SI]
			SUB SI,DX	;恢复SI寄存器
			CALL FUN
			
			PUSH DX
			MOV DL,','	;打印逗号
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
