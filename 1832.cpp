#include <iostream>
#include <unordered_set>
using namespace std;

// set size
bool checkIfPangram(string sentence) {
    unordered_set<char> s(sentence.begin(), sentence.end());
    return s.size() == 26;
}

// or 26 bits as chars
bool checkIfPangram(string sentence) {
    int seen = 0;
    for (auto &c : sentence) seen |= (1 << (c-'a'));
    return seen == ((1 << 26) - 1);
}