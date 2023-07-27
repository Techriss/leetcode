#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v({{1}});
    for (int row = 1; row < numRows; row++) {
        int l = 0, r = v[row-1].size() - 1;
        vector<int> rv;
        rv.push_back(v[row-1][l]);
        while (l < r) {
            rv.push_back(v[row-1][l] + v[row-1][l+1]);
            l++;
        }
        rv.push_back(v[row-1][r]);

        v.push_back(rv);
    }

    return v;
}


int main() {
    auto v = generate(6);
    for (auto r : v) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }

}