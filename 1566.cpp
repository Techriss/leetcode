#include <iostream>
#include <vector>
using namespace std;

bool containsPattern(vector<int>& arr, int m, int k) {
    if (m*k > arr.size()) return false;

    // get first pattern
    vector<int> p;
    for (int i = 0; i < m; i++) p.push_back(arr[i]);
    int n = 1;
    
    // starting from first index after pattern
    for (int i = m; i+(m*(k-n))-1 < arr.size(); i++) {

        // search for pattern k times
        while (n < k) {
            bool same = true;
            for (int j = i, k = 0; j < arr.size(); j++, k++) {
                if (arr[j] != p[k]) { same = false; break; }
                if (k == m-1) { n++; k = -1; }
            }

            if (!same) break;
        }

        // found
        if (n == k) return true;

        // if not, 'move' pattern by one
        else {
            n = 1;
            p.erase(p.begin());
            p.push_back(arr[i]);
        }
    }

    return false;
}


// or compare adjacent chunks of size m, count numbers
bool containsPattern(vector<int>& arr, int m, int k) {
    int cnt = 0;
    for (int i = 0; i + m < arr.size(); i++){
        if (arr[i] != arr[i+m]) cnt = 0;
        else ++cnt;

        if (cnt == (k-1)*m) return true;
        
    }
    return false;
}




int main() {
    vector<int> v({2,1,2,1,1,2,1,2,2,1,2,2,2});
    cout << containsPattern(v, 1, 4);
}


