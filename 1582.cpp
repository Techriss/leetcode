#include <iostream>
#include <vector>
using namespace std;

// brute
int numSpecial(vector<vector<int>>& mat) {
    int res = 0;
    const int n = mat.size(), m = mat[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            if (mat[i][j] == 1) {
                bool single = true;
                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    if (mat[k][j] == 1) { single = false; break; }
                }
                if (!single) continue;
                for (int k = 0; k < m; k++) {
                    if (k == j) continue;
                    if (mat[i][k] == 1) { single = false; break; }
                }
                if (!single) continue;

                ++res;
            }
        }
    }

    return res;
}


// count and see
int numSpecial(vector<vector<int>>& mat) {
    vector<int> rows(mat.size()), cols(mat[0].size());
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j) {
            if (mat[i][j])
                ++rows[i], ++cols[j];
        }
    int res = 0;
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j)
            if (mat[i][j] && rows[i] == 1 && cols[j] == 1)
                ++res;
    return res;
}

/*

[0,0,0,0,0,1,0,0],
[0,0,0,0,1,0,0,1],
[0,0,0,0,1,0,0,0],
[1,0,0,0,1,0,0,0],
[0,0,1,1,0,0,0,0]



*/