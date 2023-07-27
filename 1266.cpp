#include <iostream>
#include <vector>
using namespace std;

// explanation: move most diagonally (the min) + remaining either h or r (so in sum always move max)
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int cost = 0;
    for (int i = 0; i < points.size()-1; i++) {
        int dx = abs(points[i][0]-points[i+1][0]);
        int dy = abs(points[i][1]-points[i+1][1]);
        cost += max(dx, dy);
    }

    return cost;
}