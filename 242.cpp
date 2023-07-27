#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> ms;

    for (auto c : s) {
        if (ms.find(c) == ms.end()) ms[c] = 1;
        else ms[c]++;
    }

    for (auto c : t) {
        if (ms.find(c) == ms.end()) return false;
        else ms[c]--;
    }

    for (auto c : ms) {
        if (c.second != 0) return false;
    }

    return true;
}

int main() {
    cout << isAnagram("anagram", "nagarax") << endl;
}

