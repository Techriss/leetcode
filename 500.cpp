#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findWords(vector<string>& words) {
    unordered_map<char, int> m({
        {'q', 1},
        {'w', 1},
        {'e', 1},
        {'r', 1},
        {'t', 1},
        {'y', 1},
        {'u', 1},
        {'i', 1},
        {'o', 1},
        {'p', 1},
        {'a', 2},
        {'s', 2},
        {'d', 2},
        {'f', 2},
        {'g', 2},
        {'h', 2},
        {'j', 2},
        {'k', 2},
        {'l', 2},
        {'z', 3},
        {'x', 3},
        {'c', 3},
        {'v', 3},
        {'b', 3},
        {'n', 3},
        {'m', 3},
    });

    vector<string> res;
    for (auto w : words) {
        if (w.size() == 1) res.push_back(w);
        else {
            int r = w[0] < 'a' ? m[w[0]+32] : m[w[0]];
            for (int i = 1; i < w.size(); i++) {
                if (m[w[i]] != r && m[w[i]+32] != r) { r = 0; break; }
            }
            
            if (r != 0) res.push_back(w);
        }
    }

    return res;
}