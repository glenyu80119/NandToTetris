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
//1 constant 4000
@4000
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 5000
@5000
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//writecallSys.main
@Sys.main$ret1
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
@Sys.main
0; JMP
(Sys.main$ret1)
//2 temp 1
@1
D = A
@5
D = A + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
// LabelLOOP
(Sys.Sys.init$LOOP)
// GotoLOOP
@Sys.Sys.init$LOOP
0; JMP
//writeFunction Sys.main
(Sys.main)
@5
D = A
@Sys.mainnolocal
D; JEQ
@R13
M = D
(Sys.mainloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Sys.mainloop
D; JGT
(Sys.mainnolocal)
//1 constant 4001
@4001
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 5001
@5001
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 200
@200
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 local 1
@1
D = A
@1
D = M + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 40
@40
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 local 2
@2
D = A
@1
D = M + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 6
@6
D = A
@SP
A = M
M = D
@SP
M = M + 1
//2 local 3
@3
D = A
@1
D = M + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 123
@123
D = A
@SP
A = M
M = D
@SP
M = M + 1
//writecallSys.add12
@Sys.add12$ret2
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
@Sys.add12
0; JMP
(Sys.add12$ret2)
//2 temp 0
@0
D = A
@5
D = A + D
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
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
//1 local 2
@2
D = A
@1
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 local 3
@3
D = A
@1
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 local 4
@4
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
//writeFunction Sys.add12
(Sys.add12)
@0
D = A
@Sys.add12nolocal
D; JEQ
@R13
M = D
(Sys.add12loop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Sys.add12loop
D; JGT
(Sys.add12nolocal)
//1 constant 4002
@4002
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
A = M
M = D
//1 constant 5002
@5002
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
@R13
M = D
@SP
M = M - 1
A = M
D = M
@R13
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
//1 constant 12
@12
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
