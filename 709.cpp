#include <iostream>
using namespace std;

string toLowerCase(string s) {
    for (auto &c : s) {
        if (c >= 65 && c <= 90) c += 32;
    }

    return s;
}