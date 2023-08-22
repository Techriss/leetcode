#include <iostream>
#include <vector>
using namespace std;


// rotate physically
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    if (mat == target) return true;
    const int n = mat.size();
    int k = 3;

    while (k --> 0) {
        vector<vector<int>> mat2(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat2[j][n-i-1] = mat[i][j];
            }
        }

        if (mat2 == target) return true;
        mat = mat2;
    }

    return false;
}


// check for rotations
/*
    0deg rotation : i, j will point to i, j
    90deg rotation : i, j will point to j, n - i - 1
    180deg rotation : i, j will point to n - i - 1, n - j - 1
    270deg rotation : i, j will point to n - j - 1, i


    if found how a 90 deg rotation correlates with original position,
    we can rotate the 90 deg rotation correlation by 90 deg,
    and the 180 deg rotation by 90 deg
*/
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    if (mat == target) return true;
    const int n = mat.size();
    vector<bool> v(4, true);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j]) v[0] = false;
            if (mat[i][j] != target[j][n-i-1]) v[0] = false;
            if (mat[i][j] != target[n-i-1][n-j-1]) v[0] = false;
            if (mat[i][j] != target[n-j-1][i]) v[0] = false;
        }
    }

    return v[0] || v[1] || v[2] || v[3];
}