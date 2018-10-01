(SimpleFunction.test)
@2
D = A
@SimpleFunction.testnolocal
D; JEQ
@temp
M = D
(SimpleFunction.testloop)
@SP
A = M
M = 0
@SP
M = M+1
@temp
M = M - 1
D = M
@SimpleFunction.testloop
D; JGT
(SimpleFunction.testnolocal)
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
//1 local 1
@1
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
//not
@SP
M = M-1
A = M
M = !M
@SP
M = M+1
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
@LCL
D = M
@endFrame
M = D
@5
D = D - A
@retaddr
M = D
@SP
M = M-1
A = M
D = M
@ARG
A = M
M = D
@ARG
D = M + 1
@SP
M = D
@endFrame
M = M - 1
A = M
D = M
@THAT
M = D
@endFrame
M = M - 1
A = M
D = M
@THIS
M = D
@endFrame
M = M - 1
A = M
D = M
@ARG
M = D
@endFrame
M = M - 1
A = M
D = M
@LCL
M = D
