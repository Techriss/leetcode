#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int p = 0;
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            if (grid[y][x] == 0) continue;
            int pl = 4;
            if (x-1 >= 0 && grid[y][x-1] == 1) pl--;
            if (y-1 >= 0 && grid[y-1][x] == 1) pl--;
            if (x+1 < grid[y].size() && grid[y][x+1] == 1) pl--;
            if (y+1 < grid.size() && grid[y+1][x] == 1) pl--;
            p += pl;
        }
    }

    return p;
}

int main() {
    vector<vector<int>> grid(
        {
            {1, 1}
        }
    );

    cout << islandPerimeter(grid) << endl;
}

