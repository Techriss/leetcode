#include <iostream>
#include <vector>
using namespace std;

// get to know the pattern here (long work)
string convert(string s, int numRows) {
    const int n = s.size();
    vector<bool> was(n, false);
    int x = numRows*2 - 2;
    if (x == 0) return s;
    string res = "";


    for (int i = 0; i < n; i++) {
        for (int j = 0; j-i < n; j += x) {
            cout << j-i << ", " << j+i << endl;
            if (j-i >= 0 && !was[j-i]) res += s[j-i], was[j-i] = true;
            if (j+i < n && !was[j+i]) res += s[j+i], was[j+i] = true;
        }
    }
    
    return res;
}


int main() {
    cout << convert("abcd", 3);
}


/*
    numRows = 7;
    x = 12;

    A           N           Z
    B         M O         Y
    C       K   P       X
    D     J     Q     W
    E   I       R   V 
    F H         S U
    G           T


    0, 12, 24,   1, 11, 13, 23,   2, 10, 14, 22,   3, 9, 15, 21,   4, 8, 16, 20,   5, 7, 17, 19,   6, 18
    0, 12, 12, 24,   1, 11, 13, 23,   2, 10, 14, 22,   3, 9, 15, 21,   4, 8, 16, 20,   5, 7, 17, 19,   6, 6, 18, 18

    0, x--, x++, 2x--, 2x++, 3x--, 3x++
    0: [0, x, x, 2x, 2x, 3x, 3x, 4x, 4x]
    1: [1, x-1, x+1, 2x-1, 2x+1, 3x-1, 3x+1, 4x-1, 4x+1]
    2: [2, x-2, x+2, 2x-2, 2x+2, 3x+2, 3x+2, 4x-2, 4x+2]

*/






// or don't get to know the pattern (shorter work)
string convert(string s, int numRows) {
    vector<string> vs(numRows, "");
    int n = s.length(), i = 0;

    // always increment i
    while (i < n) {
        // vertically down, row by row (n in total)
        for (int j = 0; j < numRows && i < n; j++)
            vs[j].push_back(s[i++]);

        // diagonally up, row by row (n-2 in total)
        for (int j = numRows - 2; j >= 1 && i < n; j--)
            vs[j].push_back(s[i++]);
    }

    string zigzag;
    for (auto &v : vs) zigzag += v;
    return zigzag;
} 