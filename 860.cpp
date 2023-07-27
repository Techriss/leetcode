#include <iostream>
#include <vector>
using namespace std;

// we do not need to store 20s
bool lemonadeChange(vector<int>& bills) {
    int fives = 0, tens = 0;
    for (auto &x : bills) {
        if (x == 5) ++fives;
        else if (x == 10) {
            if (fives > 0) { --fives; ++tens; }
            else return false;
        }
        else {
            if (fives > 0 && tens > 0) { --fives; --tens; }
            else if (fives > 2) { fives -= 3; }
            else return false;
        } 
    }

    return true;
}