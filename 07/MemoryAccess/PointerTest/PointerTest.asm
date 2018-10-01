//1 constant 3030
@3030
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 pointer 0
@0
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
//1 constant 3040
@3040
D = A
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
//1 constant 32
@32
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 this 2
@2
D = A
@3
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
//1 constant 46
@46
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 that 6
@6
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
//1 pointer 0
@3
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 pointer 1
@4
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
//1 this 2
@2
D = A
@3
A = M + D
D = M
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
//1 that 6
@6
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
