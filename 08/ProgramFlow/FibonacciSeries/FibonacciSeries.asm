//1 argument 1
@1
D = A
@2
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//2 pointer 1
@1
D = A
@3
D = A + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
//1 constant 0
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 that 0
@0
D = A
@4
D = M + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
//1 constant 1
@1
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 that 1
@1
D = A
@4
D = M + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
//1 argument 0
@0
D = A
@2
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 2
@2
D = A
@SP
A = M
M = D
@SP
M = M + 1
//sub
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = M - D
@SP
M = M+1
//2 argument 0
@0
D = A
@2
D = M + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
// LabelMAIN_LOOP_START
(MAIN_LOOP_START)
//1 argument 0
@0
D = A
@2
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
// If-GotoCOMPUTE_ELEMENT
@SP
M = M-1
A = M
D = M
@COMPUTE_ELEMENT
D; JGT
// GotoEND_PROGRAM
@END_PROGRAM
0; JMP
// LabelCOMPUTE_ELEMENT
(COMPUTE_ELEMENT)
//1 that 0
@0
D = A
@4
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 that 1
@1
D = A
@4
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//add
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = D + M
@SP
M = M+1
//2 that 2
@2
D = A
@4
D = M + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
//1 pointer 1
@4
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 1
@1
D = A
@SP
A = M
M = D
@SP
M = M + 1
//add
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = D + M
@SP
M = M+1
//2 pointer 1
@1
D = A
@3
D = A + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
//1 argument 0
@0
D = A
@2
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 1
@1
D = A
@SP
A = M
M = D
@SP
M = M + 1
//sub
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = M - D
@SP
M = M+1
//2 argument 0
@0
D = A
@2
D = M + D
@temp
M = D
@SP
M = M - 1
A = M
D = M
@temp
A = M
M = D
// GotoMAIN_LOOP_START
@MAIN_LOOP_START
0; JMP
// LabelEND_PROGRAM
(END_PROGRAM)
