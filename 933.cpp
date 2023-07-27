#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        requests.push(t);
        while (requests.front() < t-3000) requests.pop();         // it pops linearly
        return requests.size();
    }

private:
    queue<int> requests;
};


// could also be done in binary search since sorted