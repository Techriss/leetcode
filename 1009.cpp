#include <iostream>
#include <bitset>
using namespace std;

int bitwiseComplement(int n) {
    if (n == 0) return 1;     // special case

    // we create a mask of all 1s (111111111111)
    unsigned mask = ~0; 

    // we leftshift till the first one (11111111000)
    // as mask&n will always be true except for when mask covers only the leading 0s
    while (mask & n) mask <<= 1;

    // we flip the bits and add the mask bits (xor of leading 1s and 1s in mask will output 0, same as ~(n ^ mask) - first adding mask and then flipping)
    return ~n ^ mask;
}

int main() {
    cout << bitwiseComplement(5) << endl;
}