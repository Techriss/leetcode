#include <iostream>
using namespace std;

// ones only at odd positions (eg. 4-3rd, 16-5th etc.)
// must be power of 2, otherwise might fail (20 - 1s only at odd positions);
bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    int mask = 0b01010101010101010101010101010101;
    return ((mask | n) == mask) && !(n & (n-1));
}

int main() {
    cout << isPowerOfFour(1) << endl;
    cout << isPowerOfFour(2) << endl;
    cout << isPowerOfFour(3) << endl;
    cout << isPowerOfFour(4) << endl;
    cout << isPowerOfFour(6) << endl;
    cout << isPowerOfFour(256) << endl;
    cout << isPowerOfFour(64) << endl;
    cout << isPowerOfFour(32) << endl;
}