#include <iostream>
#include <unordered_set>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    int res = 0;
    unordered_set<char> s;
    for (auto c : jewels) s.insert(c);
    for (auto stone : stones) res += s.count(stone);
    return res;
}