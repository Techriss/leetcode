#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int trim = arr.size() * 0.05;

    unsigned long long sum = 0;
    for (int i = trim; i < arr.size()-trim; i++) sum += arr[i];
    return sum / (double)(arr.size()-2*trim); 
}