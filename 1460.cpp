#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> m;
    for (auto &x : target) ++m[x];
    for (auto &x : arr) --m[x];
    for (auto &x : m) if (x.second != 0) return false;
    return true;
}

bool canBeEqual(vector<int>& target, vector<int>& A) {
    return unordered_multiset<int>(A.begin(), A.end()) == unordered_multiset<int>(target.begin(),target.end());
}