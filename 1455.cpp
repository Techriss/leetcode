#include <iostream>
using namespace std;

// every word
int isPrefixOfWord(string sentence, string searchWord) {
    string word = "";
    sentence += ' ';
    int count = 1;

    for (auto &c : sentence) {
        if (c == ' ') {
            if (word.rfind(searchWord, 0) == 0) return count;
            word = "";
            ++count;
        }
        else word += c;
    }

    return -1;
}



// or entire sentence (search with space so only prefixes)
int isPrefixOfWord(string sentence, string searchWord) {
    sentence = ' ' + sentence;
    searchWord = ' ' + searchWord;

    int pos = sentence.find(searchWord);
    if (pos != string::npos) {
        return count(sentence.begin(), sentence.begin() + pos + 1, ' ');
    }

    return -1;
}