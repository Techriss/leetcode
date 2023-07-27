#include <iostream>
#include <vector>
using namespace std;

// all
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> v;
    const int n = matrix.size();
    const int m = matrix[0].size();

    vector<pair<int, int>> rmin(n, { 100001, 0});
    vector<pair<int, int>> cmax(m, { 0, 0 });

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rmin[i].first > matrix[i][j]) rmin[i] = { matrix[i][j], j };
            if (cmax[j].first < matrix[i][j]) cmax[j] = { matrix[i][j], i };
        }
    }

    for (auto &p : rmin) {
        if (p.first == cmax[p.second].first) v.push_back(p.first);
    }

    return v;
}



// but actually there's only one
vector<int> luckyNumbers (vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    int maxMin = INT_MIN;
    for (int i = 0; i < m; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++)
            min = std::min(min, matrix[i][j]);
        maxMin = std::max(maxMin, min);
    }

    int minMax = INT_MAX;
    for (int j = 0; j < n; j++) {
        int max = INT_MIN;
        for (int i = 0; i < m; i++)
            max = std::max(max, matrix[i][j]);
        minMax = std::min(minMax, max);
    }
    
    if (maxMin != minMax) return vector<int> { };
    return vector<int> { maxMin };
}


int main() {
    vector<vector<int>> v({{7, 8}, {1, 2}});
    luckyNumbers(v);
}