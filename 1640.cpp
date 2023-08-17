#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    // save indices of pieces by their first element
    unordered_map<int, int> m;
    for (int i = 0; i < pieces.size(); i++) m[pieces[i][0]] = i;

    // go through the piece, exit if they dont match
    for (int i = 0; i < arr.size(); i) {
        for (auto &x : pieces[m[arr[i]]]) {
            if (arr[i++] != x) return false;
        }
    }

    return true;
}