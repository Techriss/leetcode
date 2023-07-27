#include <iostream>
#include <vector>
using namespace std;


vector<int> getRow(int rowIndex) {
    vector<vector<int>> v({{1}});
    for (int row = 1; row <= rowIndex; row++) {
        int l = 0, r = v[0].size() - 1;
        vector<int> rv;
        rv.push_back(v[0][l]);
        while (l < r) {
            rv.push_back(v[0][l] + v[0][l+1]);
            l++;
        }
        rv.push_back(v[0][r]);

        v[0] = rv;
    }

    return v[0];
}


int main() {
    auto v = getRow(3);
    for (auto x : v) cout << x << " ";

}