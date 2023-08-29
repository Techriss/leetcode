#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> v{
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};


// recursive, but it isn't really needed
vector<string> rec(string &digits, int i, vector<string> &ans) {
    vector<string> res;
    if (i == digits.size()) return ans;

    for (auto &s : ans) {
        for (auto &c : v[digits[i]-'0']) {
            res.push_back(s + c);
        }
    }

    ans = res;
    return rec(digits, i+1, ans);
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans({""});
    return rec(digits, 0, ans);
}



// iterative
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans({""});
    
    for (auto &d : digits) {
        vector<string> res;
        
        for (auto &s : ans)
            for (auto &c : v[d-'0'])
                res.push_back(s + c);

        ans = res;
    }

    return ans;
}




int main() {
    auto c = letterCombinations("23");
    for (auto &x : c) cout << x << ", ";
}