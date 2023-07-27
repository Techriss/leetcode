#include <iostream>
#include <vector>
using namespace std;

int thirdMax(vector<int>& nums) {
    long long m1 = LLONG_MIN, m2 = LLONG_MIN, m3 = LLONG_MIN;

    for (auto x : nums) {
        if (x > m1) {
            m3 = m2;
            m2 = m1;
            m1 = x;
        }
        else if (x > m2 && x != m1) {
            m3 = m2;
            m2 = x;
        }
        else if (x > m3 && x != m2 && x != m1) {
            m3 = x;
        }
    }

    if (m3 != LLONG_MIN) return (int)m3;
    else return (int)m1;
}


int main() {
    vector<int> v({1,-2147483648, 2});
    cout << thirdMax(v) << endl;
}