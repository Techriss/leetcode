#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> constructRectangle(int area) {
    for (int w = sqrt(area); w >= 1; w--) {
        if (area % w == 0) return vector<int>({area/w, w});
    }

    return vector<int>({0, 0});
}