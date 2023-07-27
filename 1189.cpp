#include <iostream>
#include <vector>
using namespace std;

// vector of chars
int maxNumberOfBalloons(string text) {
    vector<int> v(26, 0);
    for (auto &c : text) v[c-'a']++;

    return min(v['b'-'a'], min(v['a'-'a'], min(v['l'-'a']/2, min(v['o'-'a']/2, v['n'-'a']))));
}

// or count only balloons
int maxNumberOfBalloons(string text) {
    int b = 0, a = 0, l = 0, o = 0, n = 0;
    for (auto &c : text) {
        if (c == 'b') ++b;
        else if (c == 'a') ++a;
        else if (c == 'l') ++l;
        else if (c == 'o') ++o;
        else if (c == 'n') ++n;
    }

    return min(b, min(a, min(o/2, min(l/2, n))));
}

// or use array min
int maxNumberOfBalloons(string text) {
    int b = 0, a = 0, l = 0, o = 0, n = 0;
    for (auto &c : text) {
        if (c == 'b') ++b;
        else if (c == 'a') ++a;
        else if (c == 'l') ++l;
        else if (c == 'o') ++o;
        else if (c == 'n') ++n;
    }

    return min({b, a, l/2, o/2, n});
}