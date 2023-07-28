#include <iostream>
using namespace std;

int countOdds(int low, int high) {
    return (low % 2 || high % 2) + (high-low)/2;
}

int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
}




/*

    2,4: 1
    3,4: 1
    2,5: 1
    3,5: 2


*/