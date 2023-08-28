#include <iostream>
#include <vector>
using namespace std;

// recursive (way too slow) [TLE]
bool palindrome(string &s, int &l, int &r) {
    while (l < r)
        if (s[l++] != s[r--]) return false;

    return true;
}

string longestPalindrome(string s) {
    return rec(s, 0, s.size()-1);
}

string rec(string &s, int l, int r) {
    if (palindrome(s, l, r)) return s.substr(l, r-l+1);
    string s1 = rec(s, l+1, r);
    string s2 = rec(s, l, r-1);

    return s1.size() > s2.size() ? s1 : s2;
}




// iterative (O(N^3) - two loops + check if palindrome) - acceptable, but too slow
string longestPalindrome(string s) {
    string p = "";
    const int n = s.size();

    for (int i = 0; i < n; i++) {
        for (int j = s.size()-1; j >= i; j--) {
            if (palindrome(s, i, j)) {
                string sub = s.substr(i, j-i+1);
                p = p.size() >= sub.size() ? p : sub;
            }
        }
    }    

    return p;
}



// DP (much better, but still not the best way)
string longestPalindrome(string s) {
    const int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) dp[i][i] = true;
    int maxstart = 0, maxlength = 1;

    for (int end = 0; end < n; end++) {
        for (int start = end-1; start >= 0; start--) {
            if ((s[start] == s[end]) && (end - start == 1 || dp[start+1][end-1])) {
                dp[start][end] = true;
                int l = end-start+1;

                if (maxlength < l) {
                    maxlength = l;
                    maxstart = start;
                }
            }
        }
    }

    return s.substr(maxstart, maxlength);
}



// two pointers (o(1) space)
/*
    a palindromic substring consists of
        - the core (e.g. a, aa, aaa)
        - the shell (e.g. b_b, bb_bb, bc_cb)

    we could've just expand outwards, but then we would miss cases when the core's length is even
    so first we have to expand the core one by one
    then expand the shell by 2 every time

*/
string longestPalindrome(string s) {
    const int n = s.size();
    int maxstart = 0, maxlength = 1;
    

    for (int i = 0; i < n; i++) {
        int r = i;
        while (r < n && s[r] == s[i]) ++r;

        // we've just got a palindromic substring [i, r-1]

        int l = i-1;
        while (l >= 0 && r < n && s[l] == s[r]) --l, ++r;

        // we've just got a palindromic substring [l+1, r-1]

        ++l, --r;
        int len = r-l+1;
        if (maxlength < len) {
            maxlength = len;
            maxstart = l;
        }
    }

    return s.substr(maxstart, maxlength);
}