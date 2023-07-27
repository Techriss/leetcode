#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// class KthLargest {
// public:
//     KthLargest(int k, vector<int>& nums) {
//         ki = k-1;
//         v = nums;
//         sort(v.begin(), v.end(), greater());
//     }
    
//     int add(int val) {
//         int l = 0, r = v.size()-1;
//         while (l <= r) {
//             int mid = (l+r)/2;
//             if (v[mid] == val) { l = mid; break; }
//             if (v[mid] > val) l = mid+1;
//             else r = mid-1;
//         }

//         for (auto x : v) cout << x << " ";
//         cout << endl;

//         v.insert(v.begin() + l, val);
//         return v[ki];
//     }

// private:
//     vector<int> v;
//     int ki;
// };




class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;    // always keeps only kth largest elements
    int size;
public:
    KthLargest(int k, vector<int> nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);                         // pushes to the pq, keeping min element at the top()
            if (pq.size() > k) pq.pop();              // pops off min element, keeping the size = k and the top() = kth largest (smallest from the first k elements)
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > size) pq.pop();               // same logic as above
        return pq.top();
    }
};

int main() {
    int k = 7;
    vector<int> nums({-10,1,3,1,4,10,3,9,4,5,1});
    vector<int> adds({3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6});

    KthLargest* obj = new KthLargest(k, nums);
    for (auto x : adds) {
        cout << obj->add(x) << endl;
    }
}