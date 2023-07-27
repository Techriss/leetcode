#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q;
    int x, y;

    for (auto &x : stones) q.push(x);
    while (q.size() > 1) {
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        if (x != y) q.push(x-y);
    }

    return q.empty() ? 0 : q.top();
}