#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
    int prev = n%2;
    n /= 2;
    
    while (n > 0) {
        int rem = n%2;
        if (rem == prev) return false;
        prev = rem;
        n /= 2;
    }

    return true;
}