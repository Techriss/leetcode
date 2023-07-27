#include <iostream>
#include <vector>
using namespace std;

// popcount
vector<int> countBits(int n) {
    vector<int> bits(n+1);
    for (int i = 0; i <= n; i++) {
        bits[i] = __builtin_popcount(i);
    }

    return bits;
}

// if even, num of bits same if we right shift (i/2 <=> i>>1)
// if not even, it's simply the even before + 1 on the lsb
vector<int> countBits(int n) {
    vector<int> bits(n+1);
    if (n == 0) return bits;
    bits[0] = 0;
    bits[1] = 1;
    if (n == 1) return bits;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) bits[i] = bits[i/2];
        else bits[i] = bits[i-1] + 1;
    }

    return bits;
}

// same as above, but simpler
vector<int> countBits(int n) {
    vector<int> bits(n+1);
    if (n == 0) return bits;
    bits[0] = 0;
    bits[1] = 1;
    if (n == 1) return bits;

    for (int i = 2; i <= n; i++) {
        bits[i] = bits[i/2] + i % 2;
    }

    return bits;
}


int main() {
    auto v = countBits(100);
    for (auto x : v) cout << x << " ";

}