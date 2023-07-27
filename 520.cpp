#include <iostream>
using namespace std;

bool detectCapitalUse(string word) {
    if (word.size() == 1) return true;

    if (word[0] >= 'a') {
       for (int i = 1; i < word.size(); i++) {
            if (word[i] < 'a') return false;
       }
       return true;
    }
    if (word[0] < 'a') {
        if (word[1] < 'a') {
            for (int i = 2; i < word.size(); i++) {
                if (word[i] >= 'a') return false;
            }
            return true;
        }

        for (int i = 2; i < word.size(); i++) {
            if (word[i] < 'a') return false;
        }
        return true;
    }

    return true;
}