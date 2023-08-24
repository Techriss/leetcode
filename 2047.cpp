#include <iostream>
#include <sstream>
using namespace std;

int countValidWords(string sentence) {
    istringstream iss(sentence);
    string w;
    int n = 0;

    while (iss >> w) {
        const char last = w[w.size()-1];
        if (w[0] == '-' || last == '-') continue;
        bool ok = true;
        int hyps = 0, p = 0;
        bool plast = false;
        if (last == '.' || last == '!' || last == ',') plast = true;
        if (plast && w.size() > 2 && w[w.size()-2] == '-') continue;

        for (auto &c : w) {
            if (isdigit(c)) { ok = false; break; }
            if (c == '-' && ++hyps > 1) { ok = false; break; }
            if ((c == '.' || c == '!' || c == ',') && ++p > 1) { ok = false; break; }
        }

        if (p == 1 && !plast) continue;
        if (ok) { cout << w << endl; }
    }

    return n;
}








bool valid(string &s) {
    int hyphen = 0, N = s.size();
    for (int i = 0; i < N; ++i) {
        if (isdigit(s[i])) return false; // no digit
        if (isalpha(s[i])) continue; // skip letters
        if (s[i] == '-') {
            if (++hyphen > 1) return false; // at most one hyphen allowed
            if (i - 1 < 0 || !isalpha(s[i - 1]) || i + 1 >= N || !isalpha(s[i + 1])) return false; // hyphen must be surrounded by letters
        } else if (i != N - 1) return false; // punctuation, if any, must be the last character of token
    }
    return true;
}


int countValidWords(string sentence) {
    istringstream iss(sentence);
    string w;
    int n = 0;

    while (iss >> w) n += valid(w);
    return n;
}

