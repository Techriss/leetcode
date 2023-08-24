#include <iostream>
#include <vector>
using namespace std;


// use i/n and i%n as indices
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> v;
    const int on = original.size();
    if (on != n*m) return v;
    v = vector<vector<int>>(m, vector<int>(n));

    for (int i = 0; i < on; i++) {
        v[i/n][i%n] = original[i];
    }

    return v;
}


// push back fragments of array
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (m * n != original.size()) return {};
    
    vector<vector<int>> res;
    for (int i = 0; i < m*n; i+=n)
        res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
        
    return res;
}