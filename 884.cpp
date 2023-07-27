#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// using sets
vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_set<string> w1, blacklist;
    vector<string> v;
    s1 += ' '; s2 += ' ';

    string w = "";
    for (auto &c : s1) {
        if (c == ' ') {
            if (w1.count(w)) blacklist.insert(w);
            else w1.insert(w);
            w = "";
        }
        else w += c;
    }
    for (auto &c : s2) {
        if (c == ' ') {
            if (w1.count(w)) blacklist.insert(w);
            else w1.insert(w);
            w = "";
        }
        else w += c;
    }

    for (auto &w : w1) {
        if (!blacklist.count(w)) v.push_back(w);
    }

    return v;
}

// or hashmap
vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> m;
    vector<string> v;
    s1 += ' '; s2 += ' ';

    string w = "";
    for (auto &c : s1) {
        if (c == ' ') {
            m[w]++;
            w = "";
        }
        else w += c;
    }
    for (auto &c : s2) {
        if (c == ' ') {
            m[w]++;
            w = "";
        }
        else w += c;
    }

    for (auto &w : m) {
        if (w.second == 1) v.push_back(w.first);
    }

    return v;
}