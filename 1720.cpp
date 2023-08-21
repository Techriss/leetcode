#include <iostream>
#include <vector>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> arr(encoded.size()+1);
    arr[0] = first;
    for (int i = 1; i < arr.size(); i++) arr[i] = arr[i-1]^encoded[i-1];
    return arr;
}

/*

    for every a^b = c
              b = a^c

*/