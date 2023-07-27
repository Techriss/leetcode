#include <iostream>
#include <vector>
using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s) {
    const int maxw = 100;
    int chars = 0, w = 0, lines = 1;
    for (auto c : s) {
        if ((w + widths[c-97]) > maxw) { chars = w = 0; lines++; }
        chars++; w += widths[c-97];
    }

    return {lines, w};
}