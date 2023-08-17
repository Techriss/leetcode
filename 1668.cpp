#include <iostream>
using namespace std;

// manual
int maxRepeating(string sequence, string word) {
    int k = 0, maxk = 0;

    // starting from every index
    for (int j = 0; j < sequence.size(); j++) {

        // search for longest substring consisting of word
        for (int i = j; i < sequence.size();) {
            bool good = true;
            for (auto &c : word) {
                if (i == sequence.size() || c != sequence[i++]) { maxk = max(maxk, k); good = false; }
            }

            // if thats it go on
            if (!good) break;
            k++;
        }

        maxk = max(maxk, k);
        k = 0;
    }

    return max(k, maxk);
}

// using find
int maxRepeating(string sequence, string word) {
    int count = 0;
    string sub = word;

    while (sequence.find(sub) != string::npos) {
        ++count;
        sub += word;
    }

    return count;
}

// self made
int maxRepeating(string s, string w) {
    int n = s.length(), ans =0;
    for (int i = 0, j = 0, k = 0, l = 0; i < n; i++, j = 0, k = 0, l = 0){
        while (i + j < n && s[i+j] == w[l]){
            j++; l++;
            if (l == w.length()) l = 0, k++;
        }
        ans = max(ans, k);
    }
    return ans;
}