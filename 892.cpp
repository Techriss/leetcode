#include <iostream>
#include <vector>
using namespace std;

int surfaceArea(vector<vector<int>>& grid) {
    // for cube: 4h + 2
    // then subtract (max(h1, h1)-|h1-h1|) [which is the common area] twice from sum from right and bottom adjacent cubes
    int sum = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 0) continue;
            sum += (4*grid[i][j]) + 2;
            if (j+1 < grid[i].size() && grid[i][j+1] != 0) sum -= 2*(max(grid[i][j], grid[i][j+1])-abs(grid[i][j]-grid[i][j+1]));
            if (i+1 < grid.size() && grid[i+1][j] != 0) sum -= 2*(max(grid[i][j], grid[i+1][j])-abs(grid[i][j]-grid[i+1][j]));
        }
    }

    return sum;
}