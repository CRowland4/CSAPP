//
// Created by Caleb Rowland on 4/7/26.
//

/*
    For (x<<(n + 1)) - (x<<m),  if n is the most significant bit, (x<<(n + 1)) becomes 0, because you're
    shifting all bits "out" of the word.

    So the expression can be rewritten as -(x<<m).
 */




