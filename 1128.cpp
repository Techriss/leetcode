#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// simply count pairs
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> m;

    // but using a great function
    for (auto &x : dominoes) {
        m[min(x[0], x[1]) * 10 + max(x[0], x[1])]++;
    }

    // and count pairs to be made (n(n-1)/2)
    int c = 0;
    for (auto &p : m) {
        c += p.second*(p.second-1)/2;
    }

    return c;
}