#include <iostream>
#include <vector>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;
    for (auto &o : operations) {
        x += (o[1] == '-') ? -1 : 1;
    }

    return x;
}