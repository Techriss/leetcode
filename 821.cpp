#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// idea: from the first c seen keep dist, repeat for reverse, merge by min
vector<int> shortestToChar(string s, char c) {
    const int n = s.size();                // improves runtime a bit
    vector<int> v(n);

    int dist = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) dist = 0;
        else if (dist != INT_MAX) dist++;
        v[i] = dist;
    }

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (s[i] == c) dist = 0;
        else if (dist != INT_MAX) dist++;
        v[s.size()-i-1] = min(v[n-i-1], dist);
    }

    return v;
}


int main() {
    shortestToChar("loveleetcode", 'e');
}