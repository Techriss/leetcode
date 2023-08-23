#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// count on the go
int countTriples(int n) {
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int isquared = i*i;
        for (int j = 1; isquared + j*j <= n*n; j++) {
            double s = sqrt(isquared + j*j);
            if (trunc(s) == s) ++res;
        }
    }

    return res;
}

// we may start at i and count twice
int countTriples(int n) {
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int isquared = i*i;
        for (int j = i; isquared + j*j <= n*n; j++) {
            double s = sqrt(isquared + j*j);
            if (trunc(s) == s)  res += 2;
        }
    }

    return res;
}


// verify with array
int countTriples(int n) {
    vector<bool> squares(n * n + 1);

    // first calculate all squares up to n
    for (int i = 1; i <= n; ++i)
        squares[i * i] = true;


    // than for each pair, if makes square of sth, add twice
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; i * i + j * j <= n * n; ++j)
            res += squares[i * i + j * j] * 2;

    return res;
}


int main() {
    cout << countTriples(5) << endl;
}