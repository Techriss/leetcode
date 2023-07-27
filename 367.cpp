#include <iostream>
using namespace std;

int findSquare(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int l = 2, r = n/2;
    while (l <= r) {
        unsigned long long  mid = (l+r)/2;
        auto product = mid*mid;
        if (product == n) return mid;
        else if (product < n) l = mid+1;
        else r = mid-1;
    }

    return l-1;
}

bool isPerfectSquare(int num) {
    if (num == 0 || num == 1) return true;
    if (num == 2 || num == 3) return false;
    int s = findSquare(num);

    return ((num/s) == s) && (double)num/(double)s == num/s;
}

int main() {
    cout << isPerfectSquare(16) << endl;
    cout << isPerfectSquare(15) << endl;
    cout << isPerfectSquare(256) << endl;
}