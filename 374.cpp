#include <iostream>
using namespace std;

int guess(int num) {
    return 1;
}

int guessNumber(int n) {
    if (n == 1) return n;
    int l = 1, r = n;

    while (l <= r) {
        unsigned long long mid = (l+(unsigned long long)r)/2;
        int g = guess(mid);

        if (g == 0) return mid;
        else if (g == 1) l = mid+1;
        else r = mid-1;
    }

    return l;
}