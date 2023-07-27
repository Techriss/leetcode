#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) return false;
    if (arr[0] > arr[1]) return false;

    bool dec = false;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i-1] == arr[i]) return false;
        if (arr[i] < arr[i-1]) dec = true;
        else if (dec) return false;
    }

    return dec;
}