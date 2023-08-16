#include <iostream>
using namespace std;

// when dec
int maxDepth(string s) {
    int maxd = 0, d = 0;

    for (auto &c : s) {
        if (c == '(') ++d;
        else if (c == ')') { maxd = max(maxd, d); --d; }
    }

    return maxd;
}

// when inc
int maxDepth(string s) {
    int maxd = 0, d = 0;

    for (auto &c : s) {
        if (c == '(') maxd = max(maxd, ++d);
        else if (c == ')') --d;
    }

    return maxd;
}