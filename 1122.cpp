#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

// unordered map + rest vector
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> v;
    vector<int> res;
    unordered_map<int, int> m;

    // store every e from arr2 in map, count their occurance also in map, push others to v
    for (auto &x : arr2) m[x]++;
    for (auto &x : arr1) {
        if (m.find(x) != m.end()) m[x]++;
        else v.push_back(x);
    }

    // add every occurance of e from arr2 by arr2 order, append sorted v (rest)
    sort(v.begin(), v.end());
    for (auto &x : arr2) {
        while (m[x]-- > 1) res.push_back(x);
    }

    res.insert(res.end(), v.begin(), v.end());
    return res;
}


// or ordered map
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;

        // first count every element in arr1
        for (auto &x : arr1) m[x]++;

        // then add every element from arr2 from map first
        int pos = 0;
        for (auto &x : arr2) {
            while (m[x] --> 0) arr1[pos++] = x;
        }

        // and add other elements later (since they're sorted)
        for (auto &p : m) {
            while (p.second --> 0) arr1[pos++] = p.first;
        }
        return arr1;
    }
};