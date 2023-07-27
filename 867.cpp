#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    const int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> v(m, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[j][i] = matrix[i][j];
        }
    }

    return v;
}