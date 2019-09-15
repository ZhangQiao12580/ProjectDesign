DATAS SEGMENT
    A1 BYTE 'FEUY234..WER$';此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV SI,OFFSET A1
    CALL GETSTR
    
    MOV AH,4CH
    INT 21H
    
    GETSTR PROC ;显示以$结束的字符串，入口参数SI
    	PUSH AX
    	PUSH SI
    	
    	BEGAIN:
    		MOV AX,[SI]
    		CMP AL,'$'
    		JE LAST
    		MOV DL,AL
    		MOV AH,2
    		INT 21H
    		ADD SI,1
    		JMP BEGAIN
    	LAST:
    		POP SI
    		POP AX
    		RET
    GETSTR ENDP
    
CODES ENDS
    END START
