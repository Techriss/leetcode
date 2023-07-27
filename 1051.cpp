#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort and compare
int heightChecker(vector<int>& heights) {
    int count = 0;
    const int n = heights.size();
    auto e = heights;
    sort(e.begin(), e.end());

    for (int i = 0; i < n; i++) {
        if (heights[i] != e[i]) ++count;
    }

    return count;
}

// or map-like (basically counting sort) since the values range from 0-100
int heightChecker(vector<int>& heights) {
    vector<int> freq(101, 0);
    for (int &h : heights) freq[h]++;
    
    int res = 0, curr = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        while (freq[curr] == 0) curr++;
        if (curr != heights[i]) res++;
        freq[curr]--;
    }
    
    return res;
}