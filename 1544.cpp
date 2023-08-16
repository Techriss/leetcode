#include <iostream>
using namespace std;

bool diffcase(char c1, char c2) {
    return c1 == c2 + 32 || c1 == c2 - 32;
}

string makeGood(string s) {
    string good = "";
    good += s[0];

    for (int i = 1; i < s.size(); i++) {
        if (good.empty() || !diffcase(good[good.size()-1], s[i])) good.push_back(s[i]);
        else good.pop_back();
    }

    return good;
}