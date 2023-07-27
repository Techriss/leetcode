#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if (r*c != mat.size()*mat[0].size()) return mat; 
    vector<vector<int>> v(r, vector<int>(c));
    int i1 = 0, j1 = 0;


    for (int i2 = 0; i2 < mat.size(); i2++) {
        for (int j2 = 0; j2 < mat[i2].size(); j2++) {
            v[i1][j1] = mat[i2][j2];
            if (++j1 == c)  {
                j1 = 0;
                i1++;
            }
        }
    }

    return v;
}