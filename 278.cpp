#include <iostream>
using namespace std;

bool isBadVersion(int n) {
    return n >= 3;
}

int firstBadVersion(int n) {
    if (n == 1 && isBadVersion(1)) return 1;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l+r)/2;
        if (isBadVersion(mid)) r = mid-1;
        else l = mid+1;
    }

    if (isBadVersion(l)) {
        if (isBadVersion(l-1)) return l-1;
        else return l;
    }
    else return l+1;
}

int main() {
    cout << firstBadVersion(4);
}