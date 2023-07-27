#include <iostream>
#include <vector>
using namespace std;

bool nozero(int n) {
    while (n > 0) {
        if (n % 10 == 0) return false;
        n /= 10;
    }

    return true;
}

vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n-i; i++) {
        if (nozero(i) && nozero(n-i)) return {i, n-i};
    }

    return {0, 0};
}