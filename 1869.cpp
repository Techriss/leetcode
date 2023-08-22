#include <iostream>
#include <vector>
using namespace std;

bool checkZeroOnes(string s) {
    int ones = 0, zeros = 0, curr = 0;
    char prev = '2';

    for (auto &c : s) {
        if (c == '0') zeros = max(zeros, prev == c ? ++curr : curr = 1);
        else ones = max(ones, prev == c ? ++curr : curr = 1);

        prev = c;
    }

    return ones > zeros;
}


// shorter
bool checkZeroOnes(string s) {
    vector<int> v(2, 0); int curr = 0;
    int prev = 2;

    for (auto &c : s) {
        int b = c-'0';
        v[b] = max(v[b], prev == b ? ++curr : curr = 1);

        prev = b;
    }

    return v[1] > v[0];
}

int main() {
    cout << checkZeroOnes("0111010011");
}