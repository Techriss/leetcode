#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// two steps
string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> m;
    unordered_set<string> b(banned.begin(), banned.end());

    string w = "";
    for (auto &c : paragraph) {
        if (c >= 'a' && c <= 'z') w += c;
        else if (c >= 'A' && c <= 'Z') w += (c+32);
        else if (w != "" && !b.count(w)) { m[w]++; w = ""; }
        else w = "";
    }


    if (w != "" && !b.count(w)) m[w]++;

    string maxs;
    int max = 0;

    for (auto p : m) if (max < p.second) { max = p.second; maxs = p.first; }
    return maxs;
}



// one step
string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> m;
    unordered_set<string> b(banned.begin(), banned.end());

    string maxs;
    int max = 0;

    string w = "";
    for (auto &c : paragraph) {
        if (c >= 'a' && c <= 'z') w += c;
        else if (c >= 'A' && c <= 'Z') w += (c+32);
        else if (w != "" && !b.count(w)) {
            if (++m[w] > max) { maxs = w; max = m[w]; }
            w = "";
        }
        else w = "";
    }


    if (w != "" && !b.count(w) && ++m[w] > max) return w;
    return maxs;
}

int main() {
    string p = "a.";
    vector<string> banned({});
    cout << mostCommonWord(p, banned) << endl;
}