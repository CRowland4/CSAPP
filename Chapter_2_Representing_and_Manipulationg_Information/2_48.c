//
// Created by Caleb Rowland on 4/9/26.
//

/*

3,510,593 to binary --> 1101011001000101000001

1101011001000101000001 to normalized form --> 1.101011001000101000001 x 2^21

Fractional bit is 101011001000101000001 (21 bits), and we add two 0s to get 10101100100010100000100

E = e - Bias, and E is 21, so e = 21 + Bias = 21 + 127 = 148, which in binary is 10010100.

Sign bit is positive, so 0, and our entire number is 01001010010101100100010100000100


Integer binary:      000000000011010   11001000101000001

Floating point binary: 0 10010100 1010_11001000101000001_00

Lowest significance 21 bits of the integer binary match the highest order 21 bits of the fractional piece binary.
 */