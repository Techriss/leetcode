#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    int f1 = 0, f2 = 1, f3;
    while (n --> 0) {
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }

    return f3;
}

int main() {
    cout << climbStairs(30) << endl;
}