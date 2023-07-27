#include <iostream>
using namespace std;

int findLUSlength(string a, string b) {
    int maxsize = max(a.size(), b.size());
    if (a.size() != b.size() || a != b) return maxsize;
    return -1;
}