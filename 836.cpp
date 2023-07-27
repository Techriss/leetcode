#include <iostream>
#include <vector>
using namespace std;

// when does a 1D line overlap => do it for xs and ys
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
}

// or think of cases when they don't overlap (there are fewer of them - 4) and negate the result