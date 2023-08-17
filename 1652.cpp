#include <iostream>
#include <vector>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    const int n = code.size();
    vector<int> v(n, 0);
    if (k == 0) return v;

    for (int i = 0; i < n; i++) {
        int k2 = abs(k);

        if (k > 0) {
            for (int j = (i+1)%n; k2 --> 0; j = (j+1)%n) v[i] += code[j];
        }
        else {
            for (int j = i-1; k2 --> 0; j--) { 
                if (j < 0) j = n-1;
                v[i] += code[j];
            }
        }
    }

    return v;
}

int main() {
    vector<int> code({5, 7, 1, 4});
    decrypt(code, -3);
}