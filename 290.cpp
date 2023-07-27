#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<string, char> m1;
    unordered_map<char, string> m2;
    vector<string> words;

    string word = "";
    for (auto c : s) {
        if (c == ' ') { 
            words.push_back(word);
            word = "";
        }
        else word += c;
    }
    words.push_back(word);

    if (words.size() != pattern.size()) return false; 

    for (int i = 0; i < words.size(); i++) {
        if (m1.find(words[i]) == m1.end() && m2.find(pattern[i]) == m2.end()) {
            m1[words[i]] = pattern[i];
            m2[pattern[i]] = words[i];
        }
        else if (m1[words[i]] != pattern[i] || m2[pattern[i]] != words[i]) return false;
    }

    return true;
}

int main() {
    cout << wordPattern("abba", "dog cat cat dog") << endl;
    cout << wordPattern("abba", "dog cat cat fish") << endl;

}