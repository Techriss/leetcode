#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// expand outwards from the center, adding points (too much work + doesn't work)
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    vector<vector<int>> v;
    v.push_back({ rCenter, cCenter });

    for (int i = 0; i < rows && (rCenter-i >= 0 || rCenter+i < rows); i++) {
        for (int j = 0; j <= cols && (cCenter-j >= 0 || cCenter+j < cols); j++) {
            auto last = v[v.size()-1];
            if (rCenter-i >= 0 && cCenter-j >= 0 && (last[0] != rCenter-i || last[1] != cCenter-j)) { v.push_back({rCenter-i, cCenter-j}); last = v[v.size()-1]; }
            if (rCenter-i >= 0 && cCenter+j < cols && (last[0] != rCenter-i || last[1] != cCenter+j)) { v.push_back({rCenter-i, cCenter+j}); last = v[v.size()-1]; }
            if (rCenter+i < rows && cCenter-j >= 0 && (last[0] != rCenter+i || last[1] != cCenter-j)) { v.push_back({rCenter+i, cCenter-j}); last = v[v.size()-1]; }
            if (rCenter+i < rows && cCenter+j < cols && (last[0] != rCenter+i || last[1] != cCenter+j)) v.push_back({rCenter+i, cCenter+j});
        }
    }

    return v;
}


// simply add every point, make custom sort comparator, sort points based on center
struct Comparator {
    int rc;
    int cc;

    Comparator(int rc, int cc): rc(rc), cc(cc) {}

    bool operator()(const vector<int>& left, const vector<int>& right) const
    {    
        return abs(left[0]-rc) + abs(left[1]-cc) < abs(right[0]-rc) + abs(right[1]-cc);
    }   
}; 


int rc, cc;

vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    rc = rCenter;
    cc = cCenter;

    vector<vector<int>> v;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            v.push_back({i, j});
        }
    }

    sort(v.begin(), v.end(), Comparator(rc, cc));

    return v;
}


int main() {
    allCellsDistOrder(2, 2, 0, 1);

}