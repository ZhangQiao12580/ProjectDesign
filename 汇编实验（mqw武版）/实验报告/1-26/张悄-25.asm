DATAS SEGMENT
    S1 BYTE '520$';此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV SI,OFFSET S1

    MOV BL,0 
   	BEGAIN:
    		MOV AL,[SI]
    		CMP AL,'$'
    		JE LAST
    		CMP AL,'0'
    		JE QSHOW0
    		CMP AL,'1'
    		JE QSHOW1
    		CMP AL,'2'
    		JE QSHOW2
    		CMP AL,'4'
    		JE QSHOW4
    		CMP AL,'5'
    		JE QSHOW5
    		CMP AL,'3'
    		JE QSHOW3
    	QSHOW0:
    		MOV AL,BL
    		CALL SHOW0
			JMP THISEND
		QSHOW1:
    		MOV AL,BL
    		CALL SHOW1
			JMP THISEND 
		QSHOW2:
    		MOV AL,BL
    		CALL SHOW2
			JMP THISEND
		QSHOW4:
    		MOV AL,BL
    		CALL SHOW4
			JMP THISEND
		QSHOW3:
    		MOV AL,BL
    		CALL SHOW3
			JMP THISEND
		QSHOW5:
    		MOV AL,BL
    		CALL SHOW5
			JMP THISEND       	
    	THISEND:
    		ADD BL,1
    		ADD SI,1
    		JMP BEGAIN
    LAST:


    MOV AH,4CH
    INT 21H
    
    SHOW0 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,1
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
	    	
	    	MOV BH,0
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
		    
		    MOV BH,0
		    MOV DH,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
	    	
	    	MOV BH,0
		    MOV DH,4
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
	    
	    POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW0 ENDP
    
    SHOW1 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    
	    	ADD DL,2
	    	
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,1
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,4
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
    
		POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW1 ENDP
    
    SHOW2 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    	
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    MOV DH,1
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
		    
		    MOV BH,0
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    MOV DH,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV BH,0
		    MOV DH,4
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
	    
	    POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW2 ENDP
    
    SHOW3 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    	
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    MOV DH,1
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
		    
		    MOV BH,0
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    MOV DH,3
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
			
			MOV BH,0
		    MOV DH,4
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
	    
	    POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW3 ENDP
    
    SHOW4 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    	
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
		    
		    MOV BH,0
		    MOV DH,1
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
		    
		    MOV BH,0
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    MOV DH,3
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
			
			PUSH DX
		    MOV DH,4
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
	    
	    POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW4 ENDP
    
     SHOW5 PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    	
	    	MOV BH,0
		    MOV DH,0
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    MOV DH,1
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    
		    MOV DH,2
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
		    
		    PUSH DX
		    MOV DH,3
		    ADD DL,3
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,1
		    MOV AH,09H
		    INT 10H
		    POP DX
	    	
	    	MOV BH,0
		    MOV DH,4
		    MOV AH,2H
		    INT 10H
		    MOV AL,'*'
		    MOV BL,1100B
		    MOV CX,4
		    MOV AH,09H
		    INT 10H
	    
	    POP DX
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOW5 ENDP
    
    SHOWX PROC	;AL 第几个字符 初始为0
	    PUSH AX
	    PUSH BX
	    PUSH CX
	    PUSH DX
	    	
	    	MOV DL,6
	    	MUL DL
	    	MOV DL,AL
	    	
	    POP CX
	    POP BX
	    POP AX
	    RET
    SHOWX ENDP
    
CODES ENDS
    END START
