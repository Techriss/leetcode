#include <iostream>
using namespace std;

// simulation
int numWaterBottles(int numBottles, int numExchange) {
    int sum = 0;
    
    int full = numBottles, empty = 0;
    while (full > 0) {
        sum += full;       // drink full bottles
        empty += full;     // make them empty
        full = empty / numExchange;    // exchange all empty for fulls
        empty %= numExchange;    // leave the non-exchangeable
    }

    return sum;
}


// math
int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
}

// mutliple explanations possible, each one hard to understand