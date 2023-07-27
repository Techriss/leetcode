#include <iostream>
using namespace std;

// by strings
uint32_t reverseBits(uint32_t n) {
    string b = "";
    while (n > 0) {
        b += (n%2)+48;
        n /= 2;
    }

    while (b.size() != 32) b.push_back('0');

    cout << b << endl;

    uint32_t n2 = 0;
    for (auto c : b) {
        n2 = n2*2 + (((int)c)-48);
    }

    return n2;
}


// by bitwise divide and conquer
uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);  // 11001100, 00110011
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);  // 10101010, 01010101

    return n;
}

// by bitwise each bit
uint32_t reverseBits(uint32_t n) {
    int result = 0;
    for(int i = 0; i < 32; i++){
        int lsb = n&1;               // get lsb
        int revLsb = lsb<<(31-i);    // move it to the leftmost
        result = result | revLsb;    // add it to result
        n = n>>1;                    // shift n, next bit
    }
    return result;
}

// by bitwise each bit without string conversion
uint32_t reverseBits(uint32_t n) {
    uint32_t x = 0;
    int d = 0;
    while (n > 0){
        x += (n % 2) << (31 - d);
        n >>= 1;
        d++;
    }
    return x;
}


int main() {
    cout << reverseBits(43261596);
}