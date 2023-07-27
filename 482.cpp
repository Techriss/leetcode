#include <iostream>
#include <algorithm>
using namespace std;

string licenseKeyFormatting(string s, int k) {
    string vals = "";
    string key = "";
    for (auto c : s) {
        if (c != '-') {
            if (c >= 'a' && c <= 'z') c -= 32;
            vals += c;
        }
    }

    for (int i = vals.size()-1, c = 1; i >= 0; i--, c++) {
        key += vals[i];
        if (c == k && i != 0) { 
            key += '-';
            c = 0;
        }
    }

    reverse(key.begin(), key.end());
    return key;
}

int main() {
    cout << licenseKeyFormatting("2-5g-3-J", 2) << endl;
}