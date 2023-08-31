#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";

    auto s = countAndSay(n-1);
    char prev = ' ';
    int count = 0;
    string res = "";
    s += ' ';

    for (auto &c : s) {
        if (c != prev && prev != ' ') { res += to_string(count) + prev; count = 0; }
        ++count, prev = c;
    }

    return res;
}


/*
    1: 1
    2: 11
    3: 21
    4: 1211
    5: 111221
    6: 312211
    7: 13112221
    8: 1112213211
    9: 


*/