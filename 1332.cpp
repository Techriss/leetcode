#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;


// input only as and bs, so:
//
// only 3 cases: empty, palindrome, not a palindrome
// if empty: 0
// if palindrome: 1
// if not: 2 palindromes (all as and all bs)
int removePalindromeSub(string s) {
    return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
}

// or early exit
int removePalindromeSub(string S) {
    if (S == "") return 0;
    for (int i = 0, j = S.size() - 1; i < j; i++, j--)
        if (S[i] != S[j]) return 2;
    return 1;
}
