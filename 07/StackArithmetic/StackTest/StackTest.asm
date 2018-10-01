//1 constant 17
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 17
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
//eq
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@EQUAL0
D; JEQ
@SP
A = M
M = 0
@EQUAL_END0
0; JMP
(EQUAL0)
@SP
A = M
M = -1
(EQUAL_END0)
@SP
M = M+1
//1 constant 17
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 16
@16
D = A
@SP
A = M
M = D
@SP
M = M + 1
//eq
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@EQUAL1
D; JEQ
@SP
A = M
M = 0
@EQUAL_END1
0; JMP
(EQUAL1)
@SP
A = M
M = -1
(EQUAL_END1)
@SP
M = M+1
//1 constant 16
@16
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 17
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
//eq
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@EQUAL2
D; JEQ
@SP
A = M
M = 0
@EQUAL_END2
0; JMP
(EQUAL2)
@SP
A = M
M = -1
(EQUAL_END2)
@SP
M = M+1
//1 constant 892
@892
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 891
@891
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
//1 constant 891
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 892
@892
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
@LT1
D; JLT
@SP
A = M
M = 0
@LT_END1
0; JMP
(LT1)
@SP
A = M
M = -1
(LT_END1)
@SP
M = M+1
//1 constant 891
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 891
@891
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
@LT2
D; JLT
@SP
A = M
M = 0
@LT_END2
0; JMP
(LT2)
@SP
A = M
M = -1
(LT_END2)
@SP
M = M+1
//1 constant 32767
@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 32766
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
//gt
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@GT0
D; JGT
@SP
A = M
M = 0
@GT_END0
0; JMP
(GT0)
@SP
A = M
M = -1
(GT_END0)
@SP
M = M+1
//1 constant 32766
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 32767
@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1
//gt
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@GT1
D; JGT
@SP
A = M
M = 0
@GT_END1
0; JMP
(GT1)
@SP
A = M
M = -1
(GT_END1)
@SP
M = M+1
//1 constant 32766
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 32766
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
//gt
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
D = M - D
@GT2
D; JGT
@SP
A = M
M = 0
@GT_END2
0; JMP
(GT2)
@SP
A = M
M = -1
(GT_END2)
@SP
M = M+1
//1 constant 57
@57
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 31
@31
D = A
@SP
A = M
M = D
@SP
M = M + 1
//1 constant 53
@53
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
//1 constant 112
@112
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
//neg
@SP
M = M-1
A = M
M = -M
@SP
M = M+1
//and
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = M & D
@SP
M = M+1
//1 constant 82
@82
D = A
@SP
A = M
M = D
@SP
M = M + 1
//or
@SP
M = M-1
A = M
D = M
@SP
M = M-1
A = M
M = M | D
@SP
M = M+1
//not
@SP
M = M-1
A = M
M = !M
@SP
M = M+1
