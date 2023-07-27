#include <iostream>
#include <bitset>
using namespace std;

bool prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int countPrimeSetBits(int left, int right) {
    int res = 0;
    for (int i = left; i <= right; i++) {
        int p = prime(__builtin_popcount(i));
        res += p;
    }

    return res;
}


int main() {
    cout << countPrimeSetBits(10, 15);
}
