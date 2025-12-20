#include <stdio.h>

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


void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}


void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


void main() {
    int val = 5;
    test_show_bytes(val);

    // Example on page 68 demonstrating two's complement representation
    short x = 12345;
    short mx = -x;

    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));

    
    // Expansion of two's complement number by sign extension - signed numbers are expanded by adding copies of the most significant
    //    bit to the left-hand side of the binary representation, where unsigned numbers are expanded by adding 0s to the left-hand side
    //    of the binary representation
    short sx = -12345;
    unsigned short usx = sx;
    int ix = sx;
    unsigned ux = usx;

    printf("sx = %d:\n", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));

    printf("usx = %u:\n", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));

    printf("ix = %d:\n", ix);
    show_bytes((byte_pointer) &ix, sizeof(int));

    printf("ux = %u:\n", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}


/* Explanation of the above, and why the cast to byte_pointer (or unsigned char *) is necessary:

Example 1:

int x = 0x12345678;
int *p = &x;

*p        // Reads 4 bytes as one integer: 0x12345678 - this is dereferencing p, which is a pointer. In other words, it's giving the value of the thing stored
                at the address location that p holds.

p[0]      // Same as *p - reads the whole int. Since p is an int pointer, it retrieves and moves through data at a byte-interval that matches the size of type int.
                In this case, treating p as an array, it's first 'element' is a string of sizeof(int) bytes, which is in fact the integer x which is stored at the
                address held in p.

p[1]      // Jumps 4 bytes forward (sizeof(int)), reads next int - this is the 'next element' of p, which is the next string of sizeof(int) bytes adjacent to the
                previous string of sizeof(int) bytes.

p + 1     // Advances by 4 bytes (one int's worth) - since sizeof(int) is 4



Example 2:

int x = 0x12345678;
unsigned char *p = (unsigned char *) &x;

*p        // Reads 1 byte: maybe 0x78 (depends on endianness) - this is dereferencing p, which is a pointer. But in this case, the pointer is an unsigned char
                pointer, so it points to something of size sizeof(unsigned char), which is 1. So we get 1 byte, which happens to be the first byte of the
                integer x (again, depending on endianness), which is 0x78.

p[0]      // First byte: 0x78 - Analagous to the int example above, here p is an unsigned char pointer, so it retrieves and moves through data at a byte-interval
                that matches the size of type unsigned char, which is 1. So if we treat p as an array, it's first 'element' is the first single byte, 0x78.

p[1]      // Second byte: 0x56 - And the second 'element' is the next single byte, which is 0x56.

p[2]      // Third byte: 0x34 - And so on.
p[3]      // Fourth byte: 0x12 - And on.

p + 1     // Advances by 1 byte

The second explainer for each example really captures the essence of why the type casting is necessary - the movement through and retrieval of data via pointers
is executed at a byte-interval that matches the size of the type of data to which the pointer points.
*/