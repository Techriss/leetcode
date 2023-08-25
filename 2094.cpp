#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// brute
vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> v;
    for (auto &x : digits) {

        // no leading zeros
        if (x == 0) continue;
        for (auto &y : digits) {

            // different digits
            if (&x == &y) continue;
            for (auto &z : digits) {

                // different digits
                if (&x == &z || &y == &z) continue;
                if (z % 2) continue;
                
                v.insert(100*x + 10*y + z);
            }
        }
    }

    return vector<int>(v.begin(), v.end());
}


// but actually, since we know the range of numbers [100, 999]
// we can check for all of them in a constant amount of time
vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> v;
    vector<int> count(10, 0);
    for (auto &d : digits) ++count[d];

    for (int i = 100; i < 999; i += 2) {
        vector<int> ds(10, 0);
        int x = i;

        while (x > 0) {
            ++ds[x % 10];
            x /= 10;
        }

        // for each even number from [100, 999] we check if we can make it with out digits
        bool ok = true;
        for (int d = 0; d < 10; d++)
            if (count[d] < ds[d]) { ok = false; break; }

        if (ok) v.push_back(i);
    }

    return v;
}



// we can also have 3 loops, one for each digit, adding the number only if we have enough digits
vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> res;
    vector<int> cnt(10, 0);
    for (auto d : digits) ++cnt[d];

    for (int i = 1; i < 10; ++i)
        for (int j = 0; cnt[i] > 0 && j < 10; ++j)
            for (int k = 0; cnt[j] > (i == j) && k < 10; k += 2)
                if (cnt[k] > (k == i) + (k == j))
                    res.push_back(i * 100 + j * 10 + k);
                    
    return res;
}