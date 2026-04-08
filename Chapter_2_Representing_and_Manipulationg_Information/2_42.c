//
// Created by Caleb Rowland on 4/7/26.
//

int div16(const int x) {
    /*
     * If x is nonnegative, then the arithmetic shift x >> 31 will leave a string of 0s, and then & with 0xF will also
     * leave 0s, so the bias is 0 as desired.
     *
     * If x is negative, x >> 31 will be all 1s, and the 0xF mask will produce 1111, or 15, which is the desire bias
     * value of 16 - 1.
     */
    const int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}