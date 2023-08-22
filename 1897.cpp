#include <iostream>
#include <vector>
using namespace std;

// hyp: number of occurances of char must be a multiple of the number of words
// res: thats all that it needed to judge
bool makeEqual(vector<string>& words) {
    vector<int> v(26, 0);
    for (auto &w : words)
        for (auto &c : w)
            ++v[c-'a'];

    int c = words.size();
    for (auto &x : v) {
        if (x > 0 && x % c != 0) return false;
    }

    return true;
}