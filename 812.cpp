#include <iostream>
#include <vector>
using namespace std;

// brute (even worse though sounds as if it was better)
double largestTriangleArea(vector<vector<int>>& points) {
    double area = 0;
    for (auto &p1 : points) {
        for (auto &p2 : points) {
            if (p2 == p1) continue;
            for (auto &p3 : points) {
                if (p3 == p2 || p3 == p1) continue;
                area = max(area, abs(p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1]))/(double)2);
            }
        }
    }

    return area;
}

// brute
double largestTriangleArea(vector<vector<int>>& points) {
    double area = 0;
    for (auto &p1 : points) {
        for (auto &p2 : points) {
            for (auto &p3 : points) {
                area = max(area, abs(p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1]))/(double)2);
            }
        }
    }

    return area;
}


// convex hull: 

/*

        to be implemented

*/