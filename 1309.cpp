#include <iostream>
#include <string>
using namespace std;

string freqAlphabets(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        // if hash, read as j-z
        if (i+2 < s.size() && s[i+2] == '#') { res += ('j' + stoi(s.substr(i, 2)) - 10); i += 2; }

        // else read as a-i
        else res += (s[i] + 48);
    }

    return res;
}