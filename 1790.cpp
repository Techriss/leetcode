#include <iostream>
using namespace std;

// one after the other
bool areAlmostEqual(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        // search for first wrong
        if (s1[i] != s2[i]) {

            // search for second wrong and swap
            for (int j = i+1; j < s1.size(); j++) {
                if (s1[j] != s2[j]) {
                    swap(s1[i], s1[j]);
                    break;
                }
            }

            // check after swap
            return s1 == s2;
        }
    }

    // no swap needed
    return true;
}


// from left and from right
bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2)
    return true;

    int l = 0, r = s1.size()-1;
    while (s1[l] == s2[l]) l++;
    while (s1[r] == s2[r]) r--;

    swap(s2[r], s2[l]);
    return s1 == s2;
}