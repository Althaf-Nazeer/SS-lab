data SEGMENT
    MSG1 DB 10,13,"ENTER THE NUMBER:$"
    FACT DW ?
data ENDS
code Segment
    ASSUME CS:CODE DS:DATA
    Start:
    MOV AX,DATA
    MOV DS,AX
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
    MOV AH,01H
    INT 21H
    SUB AX,30H
    MOV CL,AL
    MOV AX,0001H
    MOV BX,0001H
    AGAIN:
        MUL BX
        INC BX
        DEC CL
        JNZ AGAIN
        MOV BX,AX
        MOV FACT,AX
        MOV AH,4CH
        INT 21H
code ENDS
END start
