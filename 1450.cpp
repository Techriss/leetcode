#include <iostream>
#include <vector>
using namespace std;

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int c = 0;
    for (int i = 0; i < startTime.size(); i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) ++c;
    }

    return c;
}


// or prefix sums for multiple queries, but that's not the problem described