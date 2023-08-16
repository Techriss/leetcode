#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    const int n = mat.size(), half = n/2;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];
        sum += mat[n-i-1][i];
    }

    if (n % 2 == 1) sum -= mat[half][half];
    return sum;
}