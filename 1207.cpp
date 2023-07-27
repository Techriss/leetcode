#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// maps
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> m;
    unordered_map<int, int> om;

    for (auto &x : arr) m[x]++;
    for (auto &p : m) if (++om[p.second] > 1) return false;

    return true;
}


// or map + set
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> m;
    unordered_set<int> s;
    for (auto &x : arr) ++m[x];
    for (auto &p : m) s.insert(p.second);
    return m.size() == s.size();
}


// or array and sort
bool uniqueOccurrences(vector<int>& arr) {
    short m[2001] = {};
    for (auto n : arr) ++m[n + 1000];
    sort(begin(m), end(m));
    for (auto i = 1; i < 2001; ++i)
        if (m[i] && m[i] == m[i - 1]) return false;
    return true;
}

// or arrays
bool uniqueOccurrences(vector<int>& arr) {
    short m[2001] = {}, s[1001] = {};

    // count occurrences
    for (auto &n : arr) ++m[n + 1000];

    // early exit on occurs > 1, else increment
    for (auto i = 0; i < 2001; ++i)
        if (m[i] && ++s[m[i]] > 1) return false;
    return true;
}


// or manually count everything
bool uniqueOccurrences(vector<int>& arr) {
    int i = 0;
    sort(arr.begin(),arr.end());
    vector<int> ans;
    while (i < arr.size()){
        int count = 1;
        for (int j = i+1; j< arr.size(); j++){
            if (arr[i] == arr[j])
                count++;
        }
        ans.push_back(count);
        i = i + count;
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size() - 1; i++){
        if (ans[i] == ans [i+1])
            return false;
    }
    return true;
}


