#include <iostream>
using namespace std;

// O(N) time
int xorOperation(int n, int start) {
    int res = start;
    for (int i = 1; i < n; i++) res ^= (start + 2*i);
    return res;
}

// we can xor with O(1) time as xoring a range of numbers makes patterns every 4 numbers, defined below
int XORforN(int val)
{
    switch (val & 3) {
        case 0:
            return val;
        case 1:
            return 1;
        case 2:
            return (val + 1);
        case 3:
            return 0;
    }
    // printf("\n\tshouldn't reach here!");
    return 0;
}

//
// here, we xor xored ranges to get xored range [start/2, ((start / 2) + n - 1)] since xoring removes duplicates
// then, we multiply the result by 2 (leftshift)
// and then or with the LSB
int xorOperation(int n, int start){
    return (start & 1 & n) | ((XORforN((start >> 1) + n - 1) ^ XORforN((start >> 1) - 1)) << 1);
}

/*
    core: we simplify
    start ^ (start + 2) ^ (start + 4) ^ ... (start + 2*i)
    to:
    start/2 ^(start/2 + 1)^...^(start + i)

    by remembering LSB and rightshifting

*/






// may be easier to understand
int xorOperation(int n, int start) {
    int first = start & 1;
    start = start >> 1;

    if (start % 2 == 0) {
        switch (n % 4) {
            case 0: return 0;
            case 1: return ((start + n - 1) << 1) + first;
            case 2: return 2;
            case 3: return ((1 ^ (start + n - 1)) << 1) + first;
        } 
    } else {
        switch (n % 4) {
            case 0: return (start ^ 1 ^ (start + n - 1)) << 1;
            case 1: return (start << 1) + first;
            case 2: return (start ^ (start + n - 1)) << 1;
            case 3: return ((start ^ 1) << 1) + first;
        } 
    }

    return 0; //unreachable
}