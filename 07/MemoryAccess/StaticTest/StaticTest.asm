//1 constant 111
@111
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 333
@333
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 888
@888
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 static 8
@8
D = A
@16
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
//2 static 3
@3
D = A
@16
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
//2 static 1
@1
D = A
@16
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
//1 static 3
@19
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 static 1
@17
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
//1 static 8
@24
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
