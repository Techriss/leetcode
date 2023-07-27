#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// using maps
int projectionArea(vector<vector<int>>& grid) {
    // count of all diff pairs of coords
    // sum of highest on diff xs
    // sum of highest on diff ys
    const int n = grid.size();

    unordered_map<int, int> mx;
    unordered_map<int, int> my;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) continue;
            sum++;
            mx[i] = max(mx[i], grid[i][j]);
            my[j] = max(my[j], grid[i][j]);
        }
    }

    for (auto &x : mx) sum += x.second;
    for (auto &x : my) sum += x.second;

    return sum;
}


// O(1) space
int projectionArea(vector<vector<int>>& grid) {
    // count of all diff pairs of coords
    // sum of highest on diff xs
    // sum of highest on diff ys
    const int n = grid.size();
    int sum = 0, x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        x = y = 0;
        for (int j = 0; j < n; j++) {
            x = max(x, grid[i][j]);
            y = max(y, grid[j][i]);
            if (grid[i][j]) ++sum;  // now we cannot skip as it also checks grid[j][i] which might not be 0
        }

        sum += (x + y);
    }

    return sum;
}