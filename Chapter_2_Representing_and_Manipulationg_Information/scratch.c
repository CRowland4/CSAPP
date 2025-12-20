#include <stdio.h>


int sum(int x, int y) {
    return x + y;
}

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}

int main() {
    // Integer overflow, will produce result in -884,901,888
    // int foo = 300 * 400 * 500 * 200;  Commenting out so the rest will compile
    // printf(foo);


    // Finite precision of floating point arithmetic
    float bar = (3.14 + 1e20) - 1e20;  // This will evaluate to 0
    printf("%.2e\n", bar);

    float baz = 3.14 + (1e20 - 1e20);  // This will evaluate to 3.14
    printf("%.2e\n", baz);


    // Casting demonstration, page 70
    short int v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v, uv);


    // Another demo, page 70 and onto 71
    unsigned u = 4294967295u;  // 4294967295 is the max for a 32-bit unsigned integer: 1111 1111 1111 1111 1111 1111 1111 1111 
    int tu = (int) u;  // So converting to makes the most significant bit negative, resulting in -1 in two's complement form
    printf("u = %u, tu = %d\n", u, tu);


    // Demonstratio of printing variables of one type with a formatting directive of another type, page 75
    // The bit representations don't change, but the way they're interpreted depends on the formatting directive
    int negative_one = -1;
    unsigned two_to_thirty_one = 2147483648;  // 2 to the 31st

    printf("negative_one = %u = %d\n", negative_one, negative_one);
    printf("two_to_thirty_one = %u = %d\n", two_to_thirty_one, two_to_thirty_one);


    // Bit shifts with casting
    printf("%d\n", 0x80000000);

    printf("%d\n", fun1(0x80000000));
    printf("%d\n", fun2(0x80000000));


    // Truncating example
    int tx = 53191;
    short stx = (short) tx;
    int y = stx;

    printf("tx: %d\n", tx);
    printf("stx: %d\n", stx);
    printf("y: %d\n", y);

    return 0;
}







