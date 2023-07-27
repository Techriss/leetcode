#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int total = duration;
    int last = timeSeries[0];

    for (int i = 1; i < timeSeries.size(); i++) {
        total += duration;
        int add = duration - (timeSeries[i] - last);
        cout << "add: " << add << endl;
        if (add > 0) total -= add;
        last = timeSeries[i];
    }

    return total;
}

int main() {
    vector<int> ts({1, 2, 3, 4, 5});
    cout << findPoisonedDuration(ts, 5) << endl;
}