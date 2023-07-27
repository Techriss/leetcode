#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    unordered_map<char, int> m;
    for (auto c : licensePlate) {
        if (c >= 97 && c <= 122) m[c]++;
        else if (c >= 65 && c <= 90) m[c+32]++;
    }

    for (auto p : m) cout << "(" << p.first << ", " << p.second << ")" << endl;

    size_t minl = INT_MAX;
    string minw;
    bool skip = false;

    for (auto w : words) {
        unordered_map<char, int> lm;
        for (auto c : w) lm[c]++;
        cout << w << ": " << endl;
        for (auto p : lm) cout << "(" << p.first << ", " << p.second << ")" << endl;

        for (auto p : m) if (lm[p.first] < m[p.first])  { skip = true; break; }
        if (!skip && minl > w.size()) { minw = w; minl = w.size(); }
        skip = false;
    }

    return minl == INT_MAX ? words[0] : minw;
}

int main() {
    vector<string> words({"measure","other","every","base","according","level","meeting","none","marriage","rest"});
    string lp = "GrC8950";
    cout << shortestCompletingWord(lp, words);
}