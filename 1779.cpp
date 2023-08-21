#include <iostream>
#include <vector>
using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int dist = INT_MAX, index = INT_MAX;
    for (int i = 0; i < points.size(); i++) {
        if (points[i][0] == x || points[i][1] == y) {
            int d = abs(x-points[i][0]) + abs(y-points[i][1]);
            if (d < dist || (d == dist && i < index)) dist = d, index = i;
        }
    }

    return index == INT_MAX ? -1 : index;
}