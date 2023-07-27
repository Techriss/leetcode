#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

// simulation
int numberOfSteps(int num) {
    int c = 0;
    while (num > 0) {
        if (num % 2 == 0) num /= 2;
        else --num;
        ++c;
    }

    return c;
}


// recursion
int numberOfSteps(int num) {
    if (num == 0) return 0;
    return 1 + ((num % 2 == 0) ? numberOfSteps(num/2) : numberOfSteps(num-1));
}


// bitwise
int numberOfSteps (int num) {
    if (!num) return 0;
    int res = 0;
    while (num) {
        res += (num & 1) + 1;       // if 1, 2 steps (subtract and divide); if 0, 1 step (divide)
        num >>= 1;
    }
    return res - 1;          // last 1 is the exception, we simply subtract and get 0, not divide more
}


// or even shorter
// count ones, add 31 (omitting last bit) and subtract leading zeros
// (fastest)
int numberOfSteps(int num) {
    return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
}


// or even even shorter
// total number of bits + 1s
// log2 rounds down, so omits last 1
int numberOfSteps (int num) {
    return num ? log2(num) + bitset<32>(num).count() : 0;
}