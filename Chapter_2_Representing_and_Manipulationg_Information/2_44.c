//
// Created by Caleb Rowland on 4/8/26.
//

/*
 * x and y are arbitrary values
 *
 * unsigned ux = x;
 *
 * unsigned uy = y;
 */

/*

A. (x > 0) || (x-1 < 0)
    FALSE when x = TMIN32, then (x > 0) is false, and x-1 overflows to 0 so (x-1 < 0) is also false

B. (x & 7) != 7 || (x<<29 < 0)
    TRUE For (x & 7) != 7 to be false, we need (x & 7) == 7, which only happens when the last four bits of x are 1111, since

    0000 0000 0000 0000 0000 0000 0000 0111   (7)
    ____ ____ ____ ____ ____ ____ ____ 1111
  &
    0000 0000 0000 0000 0000 0000 0000 0111   (7)

    But then x<<29 < 0 is true, so the statement is true.

    In the opposite direction, for (x<<29 < 0) to be false, we need the bit in position 3 of x to be 0, so that the most
    significant bit of the result of x<<29 is 0, and the value is >- 0. But if the position 3 bit of x is 0,
    (x & 7) != 7 is true, so the statement is true.

C. (x * x) >= 0
    FALSE when x = TMAX32, x * x will overflow and the most significant bit will flip, bringing the result below 0

D. x < 0 || -x <= 0
    TRUE because the range of Two's Complement 32-bit integers is -2^31 to 2^31 - 1, so whenever x is > 0, there is
    enough room to correctly store the negation.

E. x > 0 || -x >= 0
    FALSE when x = -2^31, since x > 0 is False and then -x overflows back to -2^31, so -x >= 0 is also false

F. x+y == uy+ux
    TRUE  Even though the decimal interpretation of x+y and uy+ux would be different for some numbers due to x+y
        overflow, the actual bit patterns of the two results would be identical, and == promotes the signed x+y value
        to an unsigned value before the comparison is made.

        Good bit from Claude, when I asked if the == operator in C is actually just comparing bits:
            == compares values, but after promotion forces both operands into the same type, the value comparison and the bit
            comparison happen to coincide for integers.

G. x*~y + uy*ux == -x
    TRUE because ~y = -y-1, and uy*ux = x*y (bit patterns are the same). So then the left side is x*(-y-1)+x*y, and so
    the left hand side becomes -xy-x+x*y, where -xy and xy cancel to give -x.

*/