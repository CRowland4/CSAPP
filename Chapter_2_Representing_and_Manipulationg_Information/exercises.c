#include <stdio.h>
#include <string.h>

// Everything below is included for the sake of compilation and actually running problems

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
        printf("\n");
    }

    printf("\n");
}


void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}


void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}


void inplace_swap(int *x, int *y) {  // Function for exercise 2.10
    *y = *x ^ *y;  // Step 1
    *x = *x ^ *y;  // Step 2
    *y = *x ^ *y;  // Step 3

    /*
    Initially       a                           b
    Step 1          a                           a ^ b    
    Step 2          a ^ a ^ b = 0 ^ b = b       a ^ b
    Step 3          b                           b ^ a ^ b = b ^ b ^ a = 0 ^ a = a
    */
}


void reverse_array(int a[], int cnt) {  // Function for exercise 2.11
    int first, last;
    for (first = 0, last = cnt-1; first <= last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }

    /*
        A. If cnt = 2k - 1, on the final iteration both <first> and <last> will be k.

        B. On iteration i = (cnt - 1) / 2, both first and last land on the middle element of the array,
            which means that inplace_swap() is passed the same element twice. But inplace_swap() uses
            the exclusive or bit operator to execute the swap. And since a ^ a = 0, inplace_swap() just ends
            up setting 'both' of it's arguments - <first> and <last>, which are actually the same center element
            of the initial array - to 0.

        C. The for loop condition "first <= last" should be modified to "first < last" to avoid this problem.
    
    */
}


// Functions for exercise 2.13
int bis(int x, int m) {  // Sets bits in x to 1 wherever bits in m are 1
    return x | m;  // Just equivalent to the bitwise or operator
}

int bic(int x, int m) {  // Sets bits in x to 0 wherever bits in m are 0
    return x & ~m;
}

// Compute x|y using only calls to functions bis and bic.
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

// Compute x^y using only calls to functions bis and bic.
int bool_xor(int x, int y) {
    // This is the key property to use x ^ y = (x & ~y) | (~x & y)
    return bis(bic(x, y), bic(y, x));  // We could just stick an | between the two calls to bic(), but using bis() is true to the strict requirement
}


// Function for Exercise 2.23
int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >> 24;
}


// Intentionally buggy function for Exercise 2.25
float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i = 0; i <= length-1; i++) {
        result += a[i];
    }
    return result;
}

// Fixed by making <length> an int type
float sum_elements_fixed(float a[], int length) {
    int i;
    float result = 0;

    for (i = 0; i <= length-1; i++) {
        result += a[i];
    }
    return result;
}


// Exercise 2.27
int uadd_ok(unsigned x, unsigned y) {
    return x + y >= x;
}


// Exercise 2.30
int tadd_ok(int x, int y) {
    // This (my first solution) doesn't work, because the compiler assumes integer overflow isn't a thing that can happen; it's "undefined behavior" in the
    //     C standard. If integer overflow doesn't exist, x + y will always be >= x if x and y are both >= 0, because that's how integers work in a context
    //     with no integer overflow. So the compiler optimizes that to always return true (or 1), which defeates the purpose of the overflow check

    // if (x >= 0 && y >= 0) {      
    //     return x + y >= x;
    // } else if (x < 0 && y >= 0) {
    //     return x + y < y;
    // } else {
    //     return x + y < x;
    // }

    // The correct solution, that doesn't give the compiler the chance to optimize away the actual check; this isn't optimized because <sum> is a 
    //    preivously-stored value
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;

    return !neg_over && !pos_over;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
    printf("Exercise 2.1\n");
    /*
        A. 0x39A7F8 to Binary

            3: 0011
            9: 1001
            A: 1010
            7: 0111
            F: 1111
            8: 1000
            Final Binary: 001110011010011111111000


        B. 1100100101111011 to Hex

            1100: C
            1001: 9
            0111: 7
            1011: B
            Final Hex: 0xC97B


        C. 0xD5E4C to binary

            D: 1101
            5: 0101
            E: 1110
            4: 0100
            C: 1100
            Final Binary: 11010101111001001100


        D. 1001101110011110110101 to Hex

            0010: 2
            0110: 6
            1110: E
            0111: 7
            1011: B
            0101: 5
            Final Hex: 0x26E7B5
    */
    printf("\n\n\n\n");


    
    printf("Exercise 2.2\n\n");
    /*
        n       2^n (decimal)       2^n (hex)

        9       512                 0x100
        19      524,288             0x80000
        14      16,384              0x4000
        17      131,072             0x20000
        5       32                  0x20
        7       128                 0x80
    */
    printf("\n\n\n\n");



    printf("Exercise 2.5");
    /*
        Decimal         Binary          Hex

        0               0000 0000       0x00
        167             1010 0111       0xA7
        62              0011 1110       0x3E
        188             1011 1100       0xBC
        55              0011 0111       0x37
        136             1000 1000       0x88
        243             1111 0011       0xF3
        82              0101 0010       0x52
        172             1010 1100       0xAC
        231             1110 0111       0xE7
    */
    printf("\n\n\n\n");



    printf("Exercise 2.4\n\n");
    /*
        A. 0x503C + 0x0008 = 0x5044

        B. 0x503C - 0x0040 = 0x0040

        C. 0x503C + 0x0064 = 0x50A0

        D. 0x50EA - 0x503C = 0x00AE
    */
    printf("\n\n\n\n");



    printf("Exercise 2.5");

    int val = 0x87654321;  // show_bytes is from show-bytes.c
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);  // A
    show_bytes(valp, 2);  // B
    show_bytes(valp, 3);  // C

    /*
        A. Little endian: 21            Big endian: 87

        B. Little endian: 21 43         Big endian: 87 65

        C. Little endian: 21 43 65      Big endian 87 65 43
    */
    printf("\n\n\n\n");



    printf("Exercise 2.6\n\n");

    int val_int = 3510593;
    show_int(val_int);  // 0x00359141

    float val_float = 3510593.0;
    show_float(val_float);    // 0x4A564504 

    /*
        A. show_int(val_int) = 0x00359141 in binary: 0000 0000 0011 0101 1001 0001 0100 0001

        show_float(val_float) = 0x4A564504 in binary: 0100 1010 0101 0110 0100 0101 0000 0100

        B.           00000000001 101011001000101000001
                                =====================
                    010010100 101011001000101000001 00

                When aligned to maximize the number of matching bits, 21 bits match.

        C. The highest order non-zero bit of the int doesn't match, whereas the float has several higher-order bits that don't match
    */
    printf("\n\n\n\n");



    printf("Exercise 2.7\n\n");

    const char *s = "abcdef";
    show_bytes((byte_pointer) s, strlen(s));  // This will print 66 65 64 63 62 61

    int test_one = 123;
    show_bytes((byte_pointer) &test_one, sizeof(int));



    printf("Exercise 2.8\n\n");
    /*
    a           [01101001]
    b           [01010101]   
    ~a          [10010110]
    ~b          [10101010]
    a & b       [01000001]
    a | b       [01111101]
    a ^ b       [00111100]
    */
    printf("\n\n\n");



    printf("Exercise 2.9\n\n");
    /*
         A. Complements
             ~Black = White
             ~Blue = Yellow
             ~Green = Magneta
             ~Cyan = Red
             ~Magenta = Green
             ~Yellow = Blue
             ~White = Black

         B. Blue | Green = 0 1 1 = Cyan
            Yellow & Cyan = 0 1 0 = Green
            Red ^ Magenta = 0 0 1 = Blue
    */
    printf("\n\n\n");



    printf("Exercise 2.10\n\n");
    int a = 3;
    int b = 7;
    inplace_swap(&a, &b);  // See this function for exercise
    printf("\n\n\n");



    printf("Exercise 2.11\n\n");
    int arr[] = {1, 2, 3};
    reverse_array(arr, 3);  // See this function for exercise
    printf("\n\n\n");



    printf("Exercise 2.12\n\n");
    int val_x = 0x87654321;

    // A.
        printf("A: 0x%08X\n", val_x & 0xFF);

    // B.
        printf("B: 0x%08X\n", val_x ^ ~0xFF);
        /*
        My takeaway from part B here is that the XOR bit operator is like a "keep or flip" operator in relation to the bits
            of the first operand. If you want to keep the original bits, do an XOR with 0. Want to flip the original bit? Do an XOR
            with 1.
        */

    // C.
        printf("C: 0x%08X\n", val_x | 0xFF);
    printf("\n\n\n");



    printf("Exercise 2.13\n\n");
    printf("bool_or(12, 33) = %d\n", bool_or(12, 33));  // See bool_or() and bool_xor() for this exercise
    printf("bool_xor(12, 33) = %d\n", bool_xor(12, 33));
    printf("\n\n\n");



    printf("Exercise 2.14\n\n");
    int x = 0x66;  // 0110 0110
    int y = 0x39;  // 0011 1001

    /*
        x & y       0010 0000 = 0x20
        x | y       0111 1111 = 0x7F
        ~x | ~y     1101 1111 = 0xDF
        x & !y      0000 0000 = 0x00
        x && y      0x01
        x || y      0x01
        !x || !y    0x00
        x && ~y     0x01
        */
    printf("\n\n\n");



    printf("Exercise 2.15\n\n");
    printf("%d\n", !(~((x & y) | (~x & ~y))));  // Returns 0x01 if x == y and 0x00 otherwise
    // My solution works, but below is the book's much more concise solution
    printf("%d\n", !(x ^ y));

    printf("%d\n", 0b01110101 >> 2);

    printf("Exercise 2.16\n\n");
    /*
        x-Hex           x-Binary            x << 3-Binary       x << 3-Hex          x >> 2-Logical Binary           x >> 2-Logical Hex          x >> 2-Arithmetic Binary            x >> 2-Arithmetic Hex


        0xC3            1100 0011           0001 1000           0x18                0011 0000                       0x30                        1111 0000                           0xF0

        0x75            0111 0101           1010 1000           0xA8                0001 1101                       0x1D                        0001 1101                           0x1D

        0x87            1000 0111           0011 1000           0x38                0010 0001                       0x21                        1110 0001                           0xE1

        0x66            0110 0110           0011 0000           0x30                0001 1001                       0x19                        0001 1001                           0x19
    
    */
    printf("\n\n\n");



    printf("Exercise 2.17\n\n");
    /*
        Hex                 Binary              B2U             B2T


        0xE                 1110                14              -2

        0x0                 0000                0               0

        0x5                 0101                5               5

        0x8                 1000                8               -8

        0xD                 1101                13              -3

        0xF                 1111                15              -1
    */
    printf("\n\n\n");



    printf("Exercise 2.18\n\n");
    /*
        0x2e0 -->  2 * 16 squared + 14 * 16 = 736
        
        -0x58 --> -1*(5 * 16 + 8) = -88

        0x28 --> 2 * 16 + 8 = 40

        -0x30 --> -1 * (3 * 16) = -48

        0x78 --> 7 * 16 + 8 = 120

        0x88 --> 8 * 16 + 8 = 136

        0x1f8 --> 16 squared + 15 * 16 + 8 = 504

        0xc0 --> 16 * 12 = 192

        -0x48 --> -1 * 4 * 16 + 8 = -72
    */
    printf("\n\n\n");



    printf("Exercise 2.19\n\n");
    /*
        x           4-bit T2U(x)


        -8          8
        
        -3          13

        -2          14

        -1          15

        0           0

        5           5
    */
    printf("\n\n\n");



    printf("Exercise 2.20\n\n");
    /*
    Every entry in the 4-bit T2U(x) column from exercise 2.19 follows equation 2.5 - if x is nonnegative, the number is the same as x, otherwise
    it's x + 2^w = x + 2^4 = x + 16.
    */
    printf("\n\n\n");



    printf("Exercise 2.21\n\n");
    /*
    Expression                              Type                Evaluation

    
    -2147483647 - 1 == 2147483648U          Unsigned            1
    
    -2147483647 - 1 < 2147483647            Signed              1
    
    -2147483647 - 1U < 2147483647           Unsigned            0
    
    -2147483647 - 1 < -2147483647           Signed              1
    
    -2147483647 - 1U < -2147483647          Unsigned            1
    */
    printf("\n\n\n");



    printf("Exercise 2.22\n\n");
    /*
        A.      1011 = -(2^3) + 2 + 1 = -5

        B.      11011 = -(2^4) + 2^3 + 2 + 1 = -5

        C.      111011 = -(2^5) + 2^4 + 2^3 + 2 + 1 = -5
    */
    printf("\n\n\n");



    printf("Exercise 2.23\n\n");
    /*
    See fun1() and fun2() at top
        A.

        w                       fun1(w)                     fun2(w)


        0x00000076              0x00000076                  0x00000076
            I messed up on this one initially - 0x76000000 has, in binary, a most significant bit
                of 0, not 1 - so the right shift adds only 0s.

        0x87654321              0x21000000                  0x00000021

        0x000000C9              0xC9000000                  0xFFFFFFC9

        0xEDCBA987              0x87000000                  0xFFFFFF87


        B. fun1() converts a word to the numerical equivalent of a single unsigned byte, and fun2() converts a word
            into the numerical equivalent of a single signed byte, where the raw value is determined by the lowest-order
            8 bits of w.
    */




    printf("Exercise 2.24\n\n");
    /*
        Unsigned OG         Truncated       Two's Complement OG         Truncated


        0                   0               0                           0

        2                   2               2                           2

        9                   1               -7                          1

        11                  3               -5                          3

        15                  7               -1                          -1


        Equation 2.9 applies to the truncated unsigned numbers but just taking the original value mod8.
        Equation 2.10 applies to the truncated signed numbers, where first we truncate them the same way as the unsigned
            values, then just convert the result to two's complement representation.
    */
    printf("\n\n\n");



    printf("Exercise 2.25\n\n");
    float var[1];
    unsigned int length = 0;

    /*
    The buggy function, commented out (along with its usage) so the rest will compile

        float sum_elements(float a[], unsigned length) {
            int i;
            float result = 0;

            for (i = 0; i <= length-1; i++) {
                result += a[i];
            }
            return result;
        }
    
        sum_elements(var, length);

    Since <length> is unsigned, the operation length - 1, where 1 is signed by default, will implicitly cast the integer 1
        to an unsigned integer. So then length - 1 doesn't result in -1, it results in an 'underflow', producing the maximum value
        of an unsigned int, which is greater than 4 billion.

    Then the loop tries to access these billions of elements, which is way beyond the bounds of the memory accessed by the array.

    This could be fixed by making the parameter <length> a normal int type, which is signed by default, so there will be no implicit
        casting.
    */

    printf("sum_elements_fixed(var, length) = %f\n", sum_elements_fixed(var, length));
    printf("\n\n\n");



    printf("Exercise 2.26\n\n");
    /*
    The buggy function, commented out (along with its usage) so the rest will compile

    Prototype for library function strlen
    size_t strlen(const char *s);

    int strlonger(char *s, char *t) {
        return strlen(s) - strlen(t) > 0;
    }

        A. This will produce an incorrect result for all cases where t is a longer string than s.
        
        B. In these cases, the subtraction of the lengths should be negative, but due to the unsigned types, will 'underflow' into a huge
            positive value, causing the compariso to return the opposite of the expected result.

        C. This could be fixed by changing the way the comparison is made: strlen(s) > strlen(t);
    */
    printf("\n\n\n");



    printf("Exercise 2.27\n\n");
    // Function solution uadd_ok() defined above
    printf("\n\n\n");



    printf("Exercise 2.28\n\n");
    /* Table of additive inverses
    Hex      Decimal         Hex Inv.        Decimal Inv


    0        0               0               0

    5        5               B               11

    8        8               8               8

    D        13              3               3

    F        15              1               1
    */
    printf("\n\n\n");
   
   

    printf("Exercise 2.29 - Liquid Text\n\n");
    /*
    I decided to move to working a lot of problems in Liquid Text, there are more 'fill in the table' type problems than there are 'write some code'
    type problems so far.
    */
    printf("\n\n\n");



    printf("Exercise 2.30\n\n");  // Function definition at top
    printf("tadd_ok(1, 2) = %d\n", tadd_ok(1, 2));
    printf("tadd_ok(2147483647, 590) = %d\n", tadd_ok(2147483647, 590));
    printf("\n\n\n");



    printf("Exercise 2.31\n\n");
	// The buggy function
	/*
    int buggy_tadd_ok(int x, int y) {
        int sum = x + y;
        return (sum - x == y) && (sum - y == x);
    }

	(INCORRECT)
	My thought here is that the issue will be the same compiler optimization issue present in my first answer to
		Exercise 2.30. The compiler will just assume that sum - x == y and sum - y == x, because sum is x + y and then
		of course the next two statements would be true mathematically.

	(CORRECT)
	My next thought is that due to the way modular arithmetic works, the overflow won't get caught here. For example,
		consider this example with 3-bit signed integers: buggy_tadd_ok(2, 2). <sum> would overflow to -4, but then
		sum - x == -4 - 2 == -6 which would wrap to 2, and sum - y would be the same calculation, so the checks would
		pass but overflow would still be occuring.
	*/
    printf("\n\n\n");



	printf("Exercise 2.32\n\n");
    /*
    Here is the buggy tsub_ok
        int tsub_ok(int x, int y) {
            return tadd_ok(x, -y);
        }
    */
   
    /*
    This will fail when y = TMin, since -TMin = TMin (negation in binary two's complement is accomplished by inverting
    all bits and then adding one - carrying this out with TMin results in TMin again).

    Example 1: x < 0, y = TMin
        The real math result here is x - TMin, but since TMin is negative, this turns into x + abs(TMin), which will not cause
          an overflow in Two's Complement arithmetic since x < 0; we want a return value of 1 from tsub_ok.
        But tsub_ok(x, TMin) turns into tadd_ok(x, TMin) which returns 0, because x + TMin results in a negative number less than
          TMin.

    Example 2: x = 0, y = TMin
        The real math result of subtraction here is 0 - TMin, but since TMin is negative, we get abs(TMin) as the answer.
          But in Two's Complement arithmetic, we can store this large of a positive number in an int, so we want tsub_ok to return 0.
        But tsub_ok(0, TMin) turns into tadd_ok(0, TMin), which returns 1 because 0 + TMin = TMin, which is fine.

    Example 3: x > 0, y = TMin.
        The real math result here is x - TMin, but since TMin is negative, this turns into x + abs(TMin), which will result in
          an overflow in Two's Complement arithmetic since TMax < abs(TMin). We want a return value of 0 from tsub_ok.
        But tsub_ok(x, TMin) turns into tadd_ok(x, TMin) which returns 1, because TMin + x returns a number in the range of int.
        
    
        After this problem I had a pretty mind blowing conversation with Claude: https://claude.ai/share/e0c7373f-a726-4ba6-8602-2887114f5f53
    */
   printf("\n\n\n");



   printf("Exercise 2.33\n\n");
   /* Table filled out in Liquid Text
   
   The takeaway here is that, if you take any binary sequence, convert the binary to a two decimal numbers - one via a Two's complement
   interpretation of the binary and one via an unsigned interpretation - then take the arithmetic inverse of those two decimal numbers and convert those
   inverses back to binary using the same binary interpretation used to generate the original decimal number, those two bit patterns will be
   the same.
   */
  printf("\n\n\n");



  printf("Exercise 2.34");















    
   

    return 0;
}

