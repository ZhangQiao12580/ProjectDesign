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
    
    MOV BH,0
    MOV DH,1
    MOV DL,2
    MOV AH,2H
    INT 10H
    
    MOV AL,'*'
    MOV BL,1100B
    MOV CX,4
    MOV BH,0
    MOV AH,09H
    INT 10H
    
    MOV BH,0
    MOV DH,2
    MOV DL,4
    MOV AH,2H
    INT 10H
    
    MOV AL,'*'
    MOV BL,1100B
    MOV CX,1
    MOV BH,0
    MOV AH,09H
    INT 10H
    
    MOV BH,0
    MOV DH,3
    MOV DL,3
    MOV AH,2H
    INT 10H
    
    MOV AL,'*'
    MOV BL,1100B
    MOV CX,1
    MOV BH,0
    MOV AH,09H
    INT 10H
    
    MOV BH,0
    MOV DH,4
    MOV DL,2
    MOV AH,2H
    INT 10H
    
    MOV AL,'*'
    MOV BL,1100B
    MOV CX,1
    MOV BH,0
    MOV AH,09H
    INT 10H

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START



