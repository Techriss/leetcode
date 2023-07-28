#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// simple sorting (slow)
bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    const int diff = arr[1]-arr[0];

    for (int i = 2; i < arr.size(); i++) {
        if (arr[i]-arr[i-1] != diff) return false;
    }

    return true;
}

// O(N) time, O(1) space
bool canMakeArithmeticProgression(vector<int>& arr) {
    const int n = arr.size();
    if (n <= 2) return true;

    int min = INT_MAX, max = INT_MIN;
    for (int num : arr) min = std::min(min, num), max = std::max(max, num);

    if ((max - min) % (n - 1) != 0) return false;
    int d = (max - min) / (n - 1);

    int i = 0;
    while (i < n) {
        if (arr[i] == min + i * d) i++;
        else if ((arr[i] - min) % d != 0) return false;
        else {
            int pos = (arr[i] - min) / d;
            if (pos < i || arr[pos] == arr[i]) return false;
            swap(arr[i], arr[pos]);
        }
    }

    return true;
}


// or use set
bool canMakeArithmeticProgression(vector<int>& arr) {
    unordered_set<int> uset(arr.begin(), arr.end());
    
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    
    if ((max - min) % (arr.size() - 1) != 0) return false;
    int diff = (max-min) / (arr.size()-1);
    if (diff != 0 && arr.size() != uset.size()) return false;

    for (int i = 1; i < arr.size(); i++){
        if (!uset.count(min + i * diff)){
            return false;
        }
    }

    return true;
}

// O(1) space better version
bool canMakeArithmeticProgression(vector<int>& arr) {
        //Assume arr can be rearranged to form an arithemetic progression.
        //Then, the line formed by arr has slope mx-mn (or any two points!).
        int mx = *max_element(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        int dx = (mx-mn)/(arr.size()-1);
        
        //Correct for division errors (mx%arr.size()-1 != 0)
        if (mn + dx * (arr.size()-1) != mx)
            return false;

        //If the minimum and maximum are equal, all indices are equal --> the difference is always 0
        if (dx == 0) return true;
        
        //Because f'(x) deletes constants in x, we can change the x intercept to 0
        //We then increment the element by 1. This is a tool we're saving for later :p
        //Also notice, every element should now be POSITIVE
        for (int i = 0; i < arr.size(); i++){
            arr[i] -= mn;
            arr[i]++;
        }

        //F: "If the array is valid, then each value from 1 to 1 + dx*(arr.size()-1) must exist in arr"
        //F and canMakeArithmeticProgression are equivalent (the proof is trivial)
        //If a point falls off the line or is repeated, then we CANNOT satisfy F as we cannot satisfy n
        //criteria using n-1 elements

        //Here's the trick you (probably) came for... NEGATIVE MARKING!
        //Because there are exactly arr.size() points on the line, we can represent seeing an element
        //by marking the value at index value/dx as negative!
        //This is also why we incremented arr[i]! (-0=0)
        for (int i =  0; i < arr.size(); i++) {
            //Find the value of arr[i] without negative marking AND remove the increment.
            int c = abs(arr[i]) - 1;

            //If c isn't divisible by dx, it CANNOT be on our line. Proof by contradiction.
            if (c % dx) return false;
            
            //If we have seen c before, return false. Proof by contradiction.
            if (arr[c/dx] < 0) return false;

            //Negative marking
            arr[c/dx] = -arr[c/dx];
        }
        
        return true;
    }


bool canMakeArithmeticProgression(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    int dx = (mx-mn)/(arr.size()-1);
    
    if (mn + dx * (arr.size()-1) != mx) return false;
    if (dx == 0) return true;

    for (int i = 0; i < arr.size(); i++) {
        arr[i] -= mn;
        arr[i]++;
    }

    for (int i =  0; i < arr.size(); i++) {
        int c = abs(arr[i]) - 1;
        if (c % dx) return false;
        if (arr[c/dx] < 0) return false;
        arr[c/dx] = -arr[c/dx];
    }
    
    return true;
}