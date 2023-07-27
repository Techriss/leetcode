#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int mind = INT_MAX;
    vector<vector<int>> v;

    // sort first
    sort(arr.begin(), arr.end());

    // then 
    for (int i = 0; i < arr.size()-1; i++) {
        const int diff = abs(arr[i+1]-arr[i]);

        // if better diff found, clear the vector
        if (diff < mind) {
            mind = diff;
            v.clear();
            v.push_back({arr[i], arr[i+1]});
        }

        // if same, add answer
        else if (diff == mind) {
            v.push_back({arr[i], arr[i+1]});
        }
    }

    return v;
}


// or: use counting sort since range is small