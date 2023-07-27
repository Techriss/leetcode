#include <iostream>
using namespace std;

int balancedStringSplit(string s) {
    int st = 0, cnt = 0;
    for (auto &c : s) {
        if (c == 'L') ++st;
        else --st;
        
        if (st == 0) ++cnt;
    }

    return cnt;
}