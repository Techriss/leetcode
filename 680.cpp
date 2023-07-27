#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool validPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j]) {
            int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
            // cut right one, check till end
            while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};

            // cut left one, check till end
            while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};

            // if either end up crossing each other, it's good news, no problems
            return i1 >= j1 || i2 >= j2;
        }
    return true;
}

int main() {
    cout << validPalindrome("deeee") << endl;
}

