#include <iostream>
using namespace std;

// check index
int minOperations(string s) {
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++) res += (s[i] - 48 != i % 2);
    return min(res, n-res);
}

// alternate
int minOperations(string s) {
    int n = s.size(), res = 0, v = 0;
    for (auto &x : s) res += (x - 48 != v), v ^= 1;
    return min(res, n-res);
}


/*

    can either be
    10101010101
    or
    01010101010

    so we have to check whether the 1s are always on odd indices and 0s on evens or the opposite

*/