#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n-1));
}

int main() {
    cout << isPowerOfTwo(1) << endl;
    cout << isPowerOfTwo(2) << endl;
    cout << isPowerOfTwo(4) << endl;
    cout << isPowerOfTwo(8) << endl;
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(17) << endl;
}