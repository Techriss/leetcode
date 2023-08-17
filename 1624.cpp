#include <iostream>
#include <vector>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    vector<int> mins(26, 301), maxs(26, -1);
    for (int i = 0; i < s.size(); i++) {
        mins[s[i]-'a'] = min(mins[s[i]-'a'], i);
        maxs[s[i]-'a'] = max(maxs[s[i]-'a'], i);
    }

    int maxd = -1;
    for (int i = 0; i < 26; i++) {
        maxd = max(maxd, maxs[i]-mins[i]-1);
    }

    return maxd;
}