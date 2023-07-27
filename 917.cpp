#include <iostream>
using namespace std;

string reverseOnlyLetters(string s) {
    int i = 0, j = s.size()-1;
    while (i < j) {
        while (i < s.size() && (s[i] > 'z' || (s[i] < 'a' && s[i] > 'Z') || s[i] < 'A')) i++;
        while (j >= 0 && (s[j] > 'z' || (s[j] < 'a' && s[j] > 'Z') || s[j] < 'A')) j--;
        if (i < s.size() && j >= 0 && i < j) swap(s[i], s[j]);
        i++; j--;
    }

    return s;
}

int main() {
    cout << reverseOnlyLetters("?6C40E");
}