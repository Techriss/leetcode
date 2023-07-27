#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// does not work, complicated
vector<int> addToArrayForm(vector<int>& num, int k) {
    int pos = num.size()-1;
    while (k > 0) {
        int newval = k % 10 + num[pos];
        if (pos < 0) { num.insert(num.begin(), 0); pos++; }

        int pos2 = pos;
        do {
            num[pos2] = (newval % 10);
            if (pos2-1 >= 0) num[pos2-1] += (newval/10);
            else if (newval > 9) { num.insert(num.begin(), (newval)/10); pos2++; }
            newval = num[--pos2];
        } while (newval > 9); 

        k /= 10;
        pos--;
    }

    return num;
}

// still much more complicated, but works
vector<int> addToArrayForm(vector<int>& num, int k) {
    int carry = 0;
    for (int j = num.size()-1; j >= 0; j--) {
        int sum = num[j] + (k % 10) + carry;
        k /= 10;

        num[j] = sum % 10;
        carry = sum / 10;
    }

    // leftovers
    while (k > 0 || carry > 0) {
        int sum = (k % 10) + carry;
        k /= 10;

        num.insert(num.begin(), sum % 10);
        carry = sum / 10;
    }
    
    return num;
}


// much simpler, entire k as a carry
vector<int> addToArrayForm(vector<int>& num, int k) {
    for (int i = num.size()-1; i >= 0 && k > 0; i--) {
        num[i] += k;        // add entire k 
        k = num[i]/10;      // cut last digit off the number (since it'll be added already)
        num[i] %= 10;       // set the digit to the last digit of the number (cause the rest is preserved in k)
    }

    // add remaining leftovers
    while (k > 0) {
        num.insert(num.begin(), k % 10);
        k /= 10;
    }

    return num;
}

int main() {
    vector<int> v({1, 2, 3});
    v = addToArrayForm(v, 900000);
    for (auto x : v) cout << x << " ";
}