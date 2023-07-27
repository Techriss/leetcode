#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int res = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (int i = 0, j = 0; i < s.size() && j < g.size(); i++, j++) {
        while (i < s.size() && s[i] < g[j]) i++;
        if (i < s.size() && g[j] <= s[i]) res++;
    }

    return res;
}

int main() {
    vector<int> g({1, 2, 3});
    vector<int> s({1, 1});
    cout << findContentChildren(g, s);
}