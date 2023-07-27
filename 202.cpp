#include <iostream>
#include <unordered_set>
using namespace std;

int sum_of_dig_sq(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n > 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sum_of_dig_sq(n);
    }

    return n == 1;
}


// OR FLOYD'S CYCLE FINDING: HARE AND TURTLE POINTERS

int main() {
    cout << isHappy(19) << endl;

}