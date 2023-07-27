#include <iostream>
#include <vector>
using namespace std;

// brute
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int n = grid.size(), m = grid[0].size();

    while (k --> 0) {
        vector<vector<int>> v = grid;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m-1; j++)
                v[i][j+1]  = grid[i][j];

        for (int i = 0; i < n-1; i++) 
            v[i+1][0] = grid[i][m-1];

        v[0][0] = grid[n-1][m-1];

        grid = v;
    }

    return grid;
}


// convert to 1D
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int n = grid.size(), m = grid[0].size(), nm = n*m;
    vector<int> v, v2(nm);

    // convert to 1D
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.push_back(grid[i][j]);
        }
    }


    // shift by k
    for (int i = 0; i < nm; i++) {
        v2[(i + k) % nm] = v[i];
    }


    // convert back to 2D
    for (int k = 0, i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = v2[k++];
        }
    }

    return grid;
}


// observe something instead
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    const int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int newJ = (j + k) % m; // (j + numbers of columns added)%m
            int newI = (i + (j + k) / m) % n; // (i + numbers of rows added)%n 
            
            ans[newI][newJ]=grid[i][j];
        }
    }
    return ans;
}