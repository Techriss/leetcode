#include <iostream>
using namespace std;

// count and compare
bool halvesAreAlike(string s) {
    const int half = s.size()/2;
    int v = 0;
    for (int i = 0; i < half; i++) {
        char &c1 = s[i];
        char &c2 = s[i+half];

        if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u' || c1 == 'A' || c1 == 'E' || c1 == 'I' || c1 == 'O' || c1 == 'U') v++;
        if (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u' || c2 == 'A' || c2 == 'E' || c2 == 'I' || c2 == 'O' || c2 == 'U') v--;
    }

    return v == 0;
}


// or set
string vowels = "aeiouAEIOU";

bool halvesAreAlike(string S) {
    int mid = S.size() / 2, ans = 0;
    for (int i = 0, j = mid; i < mid; i++, j++) {
        if (~vowels.find(S[i])) ans++;
        if (~vowels.find(S[j])) ans--;
    }
    return ans == 0;
}