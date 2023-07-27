#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// count everything (slow)
vector<string> commonChars(vector<string>& words) {
    unordered_map<string, int> m;
    vector<string> v;

    for (auto &w : words) {
        unordered_map<char, int> lm;
        for (auto &c : w) {
            m[c + to_string(lm[c])]++;   // add char and its occurance number to map to differenciate
            lm[c]++;
        }
    }

    for (auto &p : m) {
        if (p.second == words.size()) {
            string s = "";
            s += p.first[0];
            v.push_back(s);
        }
    }
    
    return v;
}


// or use this way
vector<string> commonChars(vector<string>& words) {
    vector<string> v;

    // for every char of the first word
    for (int i = 0; i < words[0].size(); i++) {
        bool common = true;

        // for every other word check if the char is present   
        for (int j = 1; j < words.size(); j++) {
            if (words[j].find(words[0][i]) == string::npos) { common = false; break; }
            else words[j].erase(words[j].find(words[0][i]), 1); // if it is, erase it to make next searches faster and find duplicates
        }

        if (common) v.push_back(string(1, words[0][i]));
    }
    
    return v;
}



// or use two vectors (maps) again, but faster (and actually somehow beats 99% from what leetcode tells me)
vector<string> commonChars(vector<string>& A) {
    vector<int> cnt(26, INT_MAX);
    vector<string> res;

    for (auto &s : A) {
        vector<int> cnt1(26, 0);
        for (auto &c : s) ++cnt1[c - 'a'];
        for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
    }

    for (auto i = 0; i < 26; ++i)
        for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));

    return res;
}