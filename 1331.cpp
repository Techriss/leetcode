#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

// map of indices
vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, vector<int>> m;
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < arr.size(); i++) {
        if (m.find(arr[i]) == m.end()) m[arr[i]] = vector<int>();
        m[arr[i]].push_back(i);
    }

    if (arr.size() > 0) arr[m[sorted[0]][0]] = 1;
    for (int i = 1, r = 1, c = 0; i < sorted.size(); i++) {
        if (sorted[i-1] != sorted[i]) { ++r; c = 0; }
        else ++c;

        arr[m[sorted[i]][c]] = r;
    }

    return arr;
}

// map of ranks
vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, int> m;
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    for (auto &x : sorted)
        m.emplace(x, m.size() + 1);    // insert if not already there
    
    for (auto &x : arr)
        x = m[x];

    return arr;
}

// or set (not to deal with duplicates)
vector<int> arrayRankTransform(vector<int>& arr) {
	set<int> s(arr.begin(),arr.end());
	unordered_map<int, int> m;
	int rank = 1;
	for (auto &x: s)  m[x] = rank++;
	for (auto &x: arr) x = m[x];
	return arr;
}

