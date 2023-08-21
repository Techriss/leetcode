#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// brute
string longestNiceSubstring(string s) {
    const int n = s.size();
    string substr = "";

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            vector<bool> v1(26, 0);
            vector<bool> v2(26, 0);
            int problems = 0;

            for (int k = i; k <= j; k++) {
                auto l = tolower(s[k]), u = toupper(s[k]);

                if (s[k] == l && !v1[l-'a']) {
                    if (v2[u-'A']) problems--;
                    else problems++;
                    v1[l-'a'] = true;
                }
                else if (s[k] == u && !v2[u-'A']) {
                    if (v1[l-'a']) problems--;
                    else problems++;
                    v2[u-'A'] = true;
                }
            }

            if (!problems) {
                auto sub = s.substr(i, j-i+1);
                if (sub.size() > substr.size()) substr = sub;
            } 
        }
    }

    return substr;
}



// divide and conquer
string longestNiceSubstring(string s) {
    const int n = s.size();
    if (n < 2) return "";

    // add each char to set
    unordered_set<char> st(s.begin(), s.end());

    // for each char
    for (int i = 0; i < n; i++) {

        // if only one case is present
        if (!st.count(toupper(s[i])) || !st.count(tolower(s[i]))) {

            // get max from either left or right substrings
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i+1));
            return s1.size() >= s2.size() ? s1 : s2;
        }
    }

    return s;
}


/*

we eliminate characters which appear only in one case
and move the search to either left of it or right

YazaAay

Y: ok
a: ok
z: not present:
    Ya:
        Y: not present => ""
    aAay:
        a: ok
        A: ok
        a: ok
        y: not present:
            aAa:
                a: ok
                A: ok
                a: ok
            ""

*/