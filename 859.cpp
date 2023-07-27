#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;

    int x, y;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != goal[i]) {
            x = i++;
            while (i < s.size() && s[i] == goal[i]) i++;
            if (i < s.size()) {
                y = i;
                swap(s[x], s[y]);
                return s == goal;
            }
            return false; // found a difference unable to be solved by swapping
        }
    }

    // no difference found, checking for doubled chars at same positions
    // unordered_map<char, int> seen;
    // for (int i = 0; i < s.size(); i++) {
    //     if (seen.find(s[i]) != seen.end()) return s[seen[s[i]]] == goal[seen[s[i]]] && s[i] == goal[i];
    //     else seen[s[i]] = i;
    // }

    // but in fact it's not needed cause the strings are surely the same after the first loop
    // so only check if contains duplicates
    return (unordered_set<char>(s.begin(), s.end()).size() < s.size());
}


// more compact
bool buddyStrings(string A, string B) {
    if (A.length() != B.length()) return false;
    if (A == B && unordered_set<char>(A.begin(), A.end()).size() < A.size()) return true;
    vector<int> dif;
    for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) dif.push_back(i);
    return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
}

int main() {
    cout << buddyStrings("ab", "ab");
}