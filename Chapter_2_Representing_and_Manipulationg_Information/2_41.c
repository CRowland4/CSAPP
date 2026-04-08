//
// Created by Caleb Rowland on 4/7/26.
//

/*
 * For a run of ones starting at bit position n down to bit position m (n >= m),
 * how should the compiler decide which form to use?
 *
 * (x<<n) + (x<<(n - 1)) + ... (x<<m) Form A
 *
 * (x<<(n + 1)) - (x<<m) Form B
 *
 * My answer (Incorrect, I was thinking along the wrong lines): If n is the most significant bit, use Form B to speed up
 *      the process, since x<<(n + 1) then becomes 0.
 *
 *
 * Correct answer: When n = m, choose form A - this results in only 1 shift operation, namely x<<n, while Form B
 *      would require 2.
 *
 *      When n = m + 1, either form is ok; each form simplifies down to two shifts and one add/sub.
 *
 *      When n > m + 1, use form B, as it will have only 2 shifts and one add/sub, while form A will have >= 3 shifts
 *          and >= 2 add/subs.
 */