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
					    
	MOV AX,65534
	
	CALL TRANSB
					    
	MOV AH,4CH
	INT 21H
					    
	TRANSB PROC	;��ڲ���:AX
		PUSH BX
		PUSH CX
		PUSH DX
						    	
		MOV BL,0
		MOV BH,128	;
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
			MOV DL,CL
			MOV AH,2
			INT 21H
			MOV BH,128
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
	CODES ENDS
END START

