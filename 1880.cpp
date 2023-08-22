#include <iostream>
#include <string>
using namespace std;

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    for (auto &c : firstWord) c -= 49;
    for (auto &c : secondWord) c -= 49;
    for (auto &c : targetWord) c -= 49;
    
    int s1 = stoi(firstWord);
    int s2 = stoi(secondWord);
    int st = stoi(targetWord);
    
    return s1 + s2 == st;
}