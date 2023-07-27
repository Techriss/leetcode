#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>
using namespace std;

unordered_map<int, vector<int>> bitcount(int n) {
    vector<int> v(n+1);
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = v[i/2] + i%2;
    }

    unordered_map<int, vector<int>> m;
    for (int i = 0; i <= n; i++) {
        if (m.find(v[i]) == m.end()) m[v[i]] = vector<int>({i});
        else m[v[i]].push_back(i);
    }

    return m;
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;
    auto bc = bitcount(59);

    for (int i = 0; i <= 4 && i <= turnedOn; i++) {
        for (auto x : bc[i]) {
            if (x >= 12) continue;
            for (auto y : bc[turnedOn-i]) {
                string s = "";
                s += to_string(x);
                s += ':';
                if (y < 10) s += '0';
                s += to_string(y);
                res.push_back(s);
            }
        }
    }

    return res;
} 


// easier to understand solution
vector<string> readBinaryWatch(int num) {
    vector<string> res;

    // iterate through all possible times
    for (int h = 0; h < 12; h++) 
    for (int m = 0; m < 60; m++)
        // Now store the time in bitset of size 10
        // where first 4 digits represent hours and
        // last 6 digits represent minutes, that's why
        // hours is left shifted 6 bits. If the count of
        // set bits equals num then append this time in our result
        if (bitset<10>(h << 6 | m).count() == num)
            // if minutes is single digit append 0 in front of it
            res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

    return res;
}



int main() {
    auto v = readBinaryWatch(9);
    for (auto x : v) {
        cout << x << endl;
    }
}