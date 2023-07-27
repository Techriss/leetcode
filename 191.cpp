#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int w = 0;
    while (n != 0) {
        w += n&1;
        n >>= 1;
    }

    return w;
}


int main() {
    cout << hammingWeight(31) << endl;

}