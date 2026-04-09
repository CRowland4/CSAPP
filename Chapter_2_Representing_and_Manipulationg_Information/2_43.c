//
// Created by Caleb Rowland on 4/8/26.
//

#include <stdio.h>

#define M 31  // Mystery number 1
#define N 8 // Mystery number 2


int arith(const int x, const int y) {
    int result = 0;
    result = x*M + y/N;  // M and N are mystery numbers
    return result;
}


// This is the compiled code, translated back into C
int optarith(int x, int y) {
    int t = x;
    x <<= 5;  // x = 2*2*2*2*2*x = 32x
    x -= t;  // x = 32x - x = 31x          -----> M = 31
    if (y < 0) y += 7;
    y >>= 3;  // Arithmetic shift -- y = y/8    -------> N = 8
    return x+y;
}

int main() {
    printf("%d\n\n", arith(M, N));
    printf("%d\n\n", optarith(M, N));
}