#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    long long l = 0, r = n;

    while (l <= r) {
        long long mid = (l+r)/2;
        if (mid*(mid+1)/2 > n) r = mid-1;
        else l = mid+1;
    }

    return l-1;
}

int main() {
    cout << arrangeCoins(5) << endl;
}