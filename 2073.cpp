#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// he has to wait for every ticket less than his
// and tickets equal before him
int timeRequiredToBuy(vector<int>& tickets, int k) {
    int less = 0, same = 0;
    for (auto &x : tickets) less += min(x, tickets[k]-1);
    for (int i = 0; i <= k; i++) same += tickets[i] >= tickets[k];
    return less + same;
}

