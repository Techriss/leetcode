#include <iostream>
using namespace std;

int subtractProductAndSum(int n) {
    unsigned long long p = 1, s = 0;
    while (n > 0) {
        int rem = n%10;
        p *= rem;
        s += rem;
        n /= 10;
    }

    return (int)p-s;
}