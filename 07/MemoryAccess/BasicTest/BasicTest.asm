//1 constant 10
@10
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
//1 constant 21
@21
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 22
@22
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 argument 2
@2
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
//2 argument 1
@1
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
//1 constant 36
@36
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 this 6
@6
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
//1 constant 42
@42
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 45
@45
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 that 5
@5
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
//1 constant 510
@510
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 temp 6
@6
D = A
@5
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
//1 that 5
@5
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
//1 this 6
@6
D = A
@3
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 this 6
@6
D = A
@3
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
//1 temp 6
@11
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
