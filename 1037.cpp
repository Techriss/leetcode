#include <iostream>
#include <vector>
using namespace std;

// if 3 points are not in one line, then they form a triangle (with area bigger than 0)
// so check if area is not 0
bool isBoomerang(vector<vector<int>>& points) {
    return 0.5*(points[0][0]*(points[1][1]-points[2][1]) + points[1][0]*(points[2][1]-points[0][1]) + points[2][0]*(points[0][1]-points[1][1])) != 0;
}