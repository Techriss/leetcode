#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// new set each time
int countGoodSubstrings(string s) {
    int res = 0;
    if (s.size() < 3) return 0;

    for (int i = 2; i < s.size(); i++) {
        unordered_set<char> c;
        c.insert(s[i-2]);
        c.insert(s[i-1]);
        c.insert(s[i]);

        if (c.size() == 3) ++res;
    }

    return res;
}

// equality
int countGoodSubstrings(string s) {
    int res = 0;
    if (s.size() < 3) return 0;

    for (int i = 2; i < s.size(); i++) {
        if (s[i] != s[i-1] && s[i-1] != s[i-2] && s[i] != s[i-2]) ++res;
    }

    return res;
}

// keep count of chars
int countGoodSubstrings(string s) {
    int res = 0;
    int dup = 0;                // whether any duplicates found
    if (s.size() < 3) return 0;
    vector<int> v(26, 0);

    for (int i = 0; i < s.size(); i++) {
        if (++v[s[i]-'a'] == 2) dup++;             // increment, note potential duplicate

        if (i < 2) continue;                       // for first two, simply note if any duplicate,
        if (dup == 0) res++;

        if (--v[s[i-2]-'a'] == 1) dup--;           // move to right, remove potential duplicate
    }

    return res;
}



int main() {
    cout << countGoodSubstrings("xyzzaz") << endl;
}