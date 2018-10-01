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
//writeFunction Class1.set
(Class1.set)
@0
D = A
@Class1.setnolocal
D; JEQ
@R13
M = D
(Class1.setloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Class1.setloop
D; JGT
(Class1.setnolocal)
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
//2 static 0
@SP
M = M - 1
A = M
D = M
@Class1.0
M = D
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
//2 static 1
@SP
M = M - 1
A = M
D = M
@Class1.1
M = D
//1 constant 0
@0
D = A
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
//writeFunction Class1.get
(Class1.get)
@0
D = A
@Class1.getnolocal
D; JEQ
@R13
M = D
(Class1.getloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Class1.getloop
D; JGT
(Class1.getnolocal)
//1 static 0
@Class1.0
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 static 1
@Class1.1
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
//writeFunction Class2.set
(Class2.set)
@0
D = A
@Class2.setnolocal
D; JEQ
@R13
M = D
(Class2.setloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Class2.setloop
D; JGT
(Class2.setnolocal)
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
//2 static 0
@SP
M = M - 1
A = M
D = M
@Class2.0
M = D
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
//2 static 1
@SP
M = M - 1
A = M
D = M
@Class2.1
M = D
//1 constant 0
@0
D = A
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
//writeFunction Class2.get
(Class2.get)
@0
D = A
@Class2.getnolocal
D; JEQ
@R13
M = D
(Class2.getloop)
@SP
A = M
M = 0
@SP
M = M+1
@R13
M = M - 1
D = M
@Class2.getloop
D; JGT
(Class2.getnolocal)
//1 static 0
@Class2.0
D = M
@SP
A = M
M = D
@SP
M = M + 1
//1 static 1
@Class2.1
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
//1 constant 6
@6
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 8
@8
D = A
@SP
A = M
M = D
@SP
M = M + 1
//writecallClass1.set
@Class1.set$ret1
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
@7
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Class1.set
0; JMP
(Class1.set$ret1)
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
//1 constant 23
@23
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 15
@15
D = A
@SP
A = M
M = D
@SP
M = M + 1
//writecallClass2.set
@Class2.set$ret2
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
@7
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Class2.set
0; JMP
(Class2.set$ret2)
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
//writecallClass1.get
@Class1.get$ret3
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
@Class1.get
0; JMP
(Class1.get$ret3)
//writecallClass2.get
@Class2.get$ret4
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
@Class2.get
0; JMP
(Class2.get$ret4)
// LabelWHILE
(Sys.Sys.init$WHILE)
// GotoWHILE
@Sys.Sys.init$WHILE
0; JMP
//
