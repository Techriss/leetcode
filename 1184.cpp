#include <iostream>
#include <vector>
using namespace std;

// two passes
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int d1 = 0, d2 = 0;
    const int n = distance.size();

    for (int i = start; i != destination; i = ((i+1)%n)) {
        d1 += distance[i];
    }

    for (int i = destination; i != start; i = ((i+1)%n)) {
        d2 += distance[i];
    }

    return min(d1, d2);
}


// or one pass (entire bus lane)
int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int sum1 = 0, sum2 = 0;

    // start at earlier
    if (start > destination) 
        swap(start, destination);

    // if currently outside normal route, add to sum2, else add to sum1
    for (int i = 0; i < distance.size(); ++i) {
        if (i >= start && i < destination) 
            sum1 += distance[i];
        else 
            sum2 += distance[i];
    }
    
    return min(sum1, sum2);
}


int main() {
    vector<int> v({1, 2, 3, 4});
    cout << distanceBetweenBusStops(v, 0, 1);
}