#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;


bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> m;
    int res = 0;
    for (auto &card : deck) m[card]++;
    for (auto &x : m) res = __gcd(x.second, res);
    return res > 1;
}