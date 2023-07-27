#include <iostream>
using namespace std;

// from front - stack-like 0(N) space
bool backspaceCompare(string s, string t) {
    string s1, t1;
    for (auto c : s) {
        if (c == '#') { if (!s1.empty()) s1.pop_back(); }
        else s1.push_back(c);
    }

    for (auto c : t) {
        if (c == '#') { if (!t1.empty()) t1.pop_back(); }
        else t1.push_back(c);
    }

    return s1 == t1;
}

// from back - O(1) space
bool backspaceCompare(string S, string T) {
    int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0; // count # in s and t
    while (i >= 0 || j >= 0){
        while (i >= 0 && (S[i] == '#' || countA > 0)) S[i--] == '#' ? ++countA : --countA; // skip chars if any #s in s
        while (j >= 0 && (T[j] == '#' || countB > 0)) T[j--] == '#' ? ++countB : --countB; // skip chars if any #s in t
        if (i < 0 || j < 0) return i == j; // if all skipped, check if equally
        if (S[i--] != T[j--]) return false; // if left, check if same chars
    }
    return i == j;
}

int main() {
    cout << backspaceCompare("y#fo##f", "y#f#o##f") << endl;
}