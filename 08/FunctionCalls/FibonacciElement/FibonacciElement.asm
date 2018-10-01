@256
D = A
@SP
M = D
@Sys.init$ret0
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@5
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Sys.init
0; JMP
(Sys.init$ret0)
//writeFunction Main.fibonacci
(Main.fibonacci)
@0
D = A
@Main.fibonaccinolocal
D; JEQ
@R13
M = D
(Main.fibonacciloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Main.fibonacciloop
D; JGT
(Main.fibonaccinolocal)
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
//lt
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@LT0
D; JLT
@SP
A = M
M = 0
@LT_END0
0; JMP
(LT0)
@SP
A = M
M = -1
(LT_END0)
@SP
M = M+1
// If-GotoIF_TRUE
@SP
M = M-1
A = M
D = M
@Main.Main.fibonacci$IF_TRUE
D; JLT
// GotoIF_FALSE
@Main.Main.fibonacci$IF_FALSE
0; JMP
// LabelIF_TRUE
(Main.Main.fibonacci$IF_TRUE)
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
// writeReturn
@LCL
D = M
@endFrame
M = D
@5
D = D - A
A = D
D = M
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
@retaddr
A = M
0; JMP
// LabelIF_FALSE
(Main.Main.fibonacci$IF_FALSE)
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
//writecallMain.fibonacci
@Main.fibonacci$ret1
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@6
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(Main.fibonacci$ret1)
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
//writecallMain.fibonacci
@Main.fibonacci$ret2
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@6
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(Main.fibonacci$ret2)
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
// writeReturn
@LCL
D = M
@endFrame
M = D
@5
D = D - A
A = D
D = M
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
@retaddr
A = M
0; JMP
//
//writeFunction Sys.init
(Sys.init)
@0
D = A
@Sys.initnolocal
D; JEQ
@R13
M = D
(Sys.initloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Sys.initloop
D; JGT
(Sys.initnolocal)
//1 constant 4
@4
D = A
@SP
A = M
M = D
@SP
M = M + 1
//writecallMain.fibonacci
@Main.fibonacci$ret3
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@6
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(Main.fibonacci$ret3)
// LabelWHILE
(Sys.Sys.init$WHILE)
// GotoWHILE
@Sys.Sys.init$WHILE
0; JMP
//
