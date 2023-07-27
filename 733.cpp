#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (image[p.first][p.second] == color) continue;

        if (p.first > 0 && image[p.first-1][p.second] == image[p.first][p.second]) q.push({p.first-1, p.second});
        if (p.second > 0 && image[p.first][p.second-1] == image[p.first][p.second]) q.push({p.first, p.second-1});
        if (p.first < image.size()-1 && image[p.first+1][p.second] == image[p.first][p.second]) q.push({p.first+1, p.second});
        if (p.second < image[p.first].size()-1 && image[p.first][p.second+1] == image[p.first][p.second]) q.push({p.first, p.second+1});

        image[p.first][p.second] = color;
    }

    return image;
}

int main() {
    vector<vector<int>> v(
        {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1},
        }
    );

    floodFill(v, 1, 1, 2);

    for (auto x : v) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}