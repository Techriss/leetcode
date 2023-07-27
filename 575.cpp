#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    int maxn = candyType.size()/2;
    int types = 0;
    unordered_map<int, bool> m;

    for (auto c : candyType) {
        if (types == maxn) break;
        if (!m[c]) {
            m[c] = true;
            types++;
        }
    }

    return types;
}