#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// the relation must be preserved
bool checkStraightLine(vector<vector<int>>& coordinates) {
    const int dx = coordinates[0][0]-coordinates[1][0];
    const int dy = coordinates[0][1]-coordinates[1][1];

    for (int i = 0; i < coordinates.size()-1; i++) {
        int ndx = coordinates[i][0]-coordinates[i+1][0];
        int ndy = coordinates[i][1]-coordinates[i+1][1];

        if (ndx*dy != dx*ndy) return false;
    }

    return true;
}


/*

    dx/dy == ndx/ndy
    ndx*dy == dx*ndy

*/