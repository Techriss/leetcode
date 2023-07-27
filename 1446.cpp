#include <iostream>
#include <vector>
using namespace std;

int maxPower(string s) {
    int gmax = 0, lmax = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) ++lmax;
        else { gmax = max(gmax, lmax); lmax = 0; }
    }

    return max(gmax, lmax);
}