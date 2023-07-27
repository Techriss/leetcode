/*
    9. ROMAN TO INTEGER
*/

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

unordered_map<char, int> m {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int romanToInt(string s) {
    int res = 0;
    auto curr = 0;
    for (int i = 1; i < s.size(); i++) {
        if (m[s[curr]] < m[s[i]]) {
            res += (m[s[i]] - m[s[curr]]);
            curr += 2;
            i++;
        }
        else {
            res += m[s[curr]];
            curr++;
        }
    }

    if (curr == s.size()-1) res += m[s[curr]];
    return res;
}


int main() {
    auto x = romanToInt("MCMXCIV");
    cout << x << endl;
}