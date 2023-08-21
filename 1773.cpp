#include <iostream>
#include <vector>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int m = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    int n = 0;

    for (auto &x : items) {
        if (x[m] == ruleValue) ++n;
    }

    return n;
}