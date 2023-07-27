#include <iostream>
#include <stack>
using namespace std;

int countBinarySubstrings(string s) {
    // zeros and ones 'stacks'
    int zeros = 0, ones = 0;
    int res = 0;
    char prev = ' ';


    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ones++;
            if (zeros > 0) { res++; zeros--; }
            if (prev == '0') ones = 1;
        }
        else {
            zeros++;
            if (ones > 0) { res++; ones--; }
            if (prev == '1') zeros = 1;
        }

        prev = s[i];
    }

    return res;
}