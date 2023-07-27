#include <iostream>
#include <vector>
using namespace std;


// brute
int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (auto &x : indices) {
        for (int i = 0; i < n; i++) v[x[0]][i]++;
        for (int i = 0; i < m; i++) v[i][x[1]]++;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cnt += v[i][j] % 2;
        }
    }

    return cnt;
}


// count odd rows and cols
int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<bool> oddrow(m, false);
    vector<bool> oddcol(n, false);

    // alternate
    for (auto &p : indices) {
        oddrow[p[0]] = oddrow[p[0]] ^ 1;
        oddcol[p[1]] = oddcol[p[1]] ^ 1;
    }

    // count odd rows and odd cols
    int r = 0, c = 0;
    for (auto x : oddrow) r += x;
    for (auto x : oddcol) c += x;

    // the answer is (odd rows * cols) + (odd cols * rows) - (doublecounted intersections [exactly r*c doubledounted elements] + now even values) 
    return r*n + c*m - 2*r*c;
}