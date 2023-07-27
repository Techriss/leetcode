#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for (auto &row : image) {
        reverse(row.begin(), row.end());
        for (auto &x : row) x ^= 1;
    }

    return image;
}


int main() {
    vector<vector<int>> v({
        {1,1,0,0},
        {1,0,0,1},
        {0,1,1,1},
        {1,0,1,0}
    });

    auto r = flipAndInvertImage(v);
    for (auto x : r) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}