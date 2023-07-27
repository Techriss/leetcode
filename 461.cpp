#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int ans = 0;
    while (x > 0 || y > 0) {
        ans += (x%2) != (y%2);
        x /= 2;
        y /= 2;
    }

    if (x != y) ans++;

    return ans;
}

int main() {
    cout << hammingDistance(14, 2) << endl;

    // 14 1110
    // 2  0010   
}