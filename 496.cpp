#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//more time consuming
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> next_greater({{nums2[nums2.size()-1], -1}});
    vector<int> ans(nums1.size());

    for (int i = 0; i < nums2.size()-1; i++) {
        next_greater[nums2[i]] = -1;
        for (int j = i+1; j < nums2.size(); j++) {
            if (nums2[i] < nums2[j]) {
                next_greater[nums2[i]] = nums2[j];
                break;
            }
        }
    }

    for (int i = 0; i < nums1.size(); i++) ans[i] = next_greater[nums1[i]];
    return ans;
}   

// or stacks
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    stack<int> st;
    unordered_map<int,int> mp;

    for (int i = m-1; i >= 0; i--){
        while (!st.empty() && st.top() <= nums2[i]) st.pop(); // we never pop anything important off the stack, as the current is bigger than right ones so would be chosen instead of the deleted ones
        if (st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = mp[nums1[i]];
    }
    return ans;
}

int main() {
    vector<int> n1({3,1,5,7,9,2,6});
    vector<int> n2({1,2,3,5,6,7,9,11});
    auto ans = nextGreaterElement(n1, n2);
    for (auto x : ans) cout << x << " ";
}


// 8 6 4 5 2 7 9