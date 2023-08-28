#include <iostream>
#include <math.h>
using namespace std;

int reverse(int x) {
    if (x == -2147483648) return 0;
    int l = log10(x < 0 ? -x : x ? x : 1);
    string maxn = "7463847412";
    int x2 = l == 9 ? x > 0 ? x : -x : 0;
    int res = 0;
    cout << l << endl;

    // compare against the string of flipped max to see if at any point the flipped x would be greater than max
    while (x2 != 0) {
        int d1 = x2 % 10;
        int d2 = maxn[l--]-'0';
        if (d1 > d2) return 0;
        else if (d1 < d2) break;
        x2 /= 10;
    }

    x2 = x;
    while (x2) {
        res = res*10 + (x2%10);
        x2 /= 10;
    }

    return res;
}