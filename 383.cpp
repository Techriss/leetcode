#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for (auto c : magazine) m[c]++;
    for (auto c : ransomNote) {
        if (m[c]) m[c]--;
        else return false;
    }

    return true;
}