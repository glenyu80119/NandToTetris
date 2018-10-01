//1 constant 0
@0
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 local 0
@0
D = A
@1
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
// LabelLOOP_START
(LOOP_START)
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
//1 local 0
@0
D = A
@1
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
//2 local 0
@0
D = A
@1
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
// If-GotoLOOP_START
@SP
M = M-1
A = M
D = M
@LOOP_START
D; JGT
//1 local 0
@0
D = A
@1
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
