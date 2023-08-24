#include <iostream>
#include <algorithm>
using namespace std;

// auto
string reversePrefix(string word, char ch) {
    auto x = word.find(ch);
    if (x == string::npos) return word;

    reverse(word.begin(), word.begin() + x + 1);
    return word;
}


// manual
string reversePrefix(string word, char ch) {
    string prefix = "";

    int i = 0;
    while (i < word.size()) {
        if (word[i] == ch) { prefix = word.substr(0, i+1); break; }
        ++i;
    }

    if (i == word.size()) return word;

    reverse(prefix.begin(), prefix.end());
    return prefix + word.substr(i+1);
}


string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ch) {
            reverse(begin(word), begin(word)+i+1);
            break;
        }
    }
    return word;
}