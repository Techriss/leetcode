#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// string stream
string sortSentence(string s) {
    istringstream iss(s);
    string w, res = "";
    vector<string> ws(9);
    int c = 0;

    while (iss >> w) {
        ++c;
        ws[w[w.size()-1]-'1'] = w.substr(0, w.size()-1);
    }

    for (int i = 0; i < c; i++) res += ws[i], res += ' ';
    res.pop_back();
    return res;
}

// manual
string sortSentence(string s) {
    vector<string> ws(9);
    string w = "";
    for (auto &c : s) {
        if (c == ' ') continue;
        if (isdigit(c)) ws[c-'1'] = w, w = "";
        else w += c;
    }

    string res = "";
    for (auto &w : ws) {
        if (w.empty()) break;
        res += w;
        res += ' ';
    }

    res.pop_back();
    return res;
}