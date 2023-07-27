#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// idea: find a way to store weakness of row while distinguishing between indices and being able to retrieve index later
// solution: map each index to number of soldiers * 1000 (cause m <= 100) and add index, then sort by that value
// addition: count soldiers not linearly but with binary search
int countsoldiers(vector<int> &v) {
    int l = 0, r = v.size()-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (v[mid] == 1) l = mid+1;
        else r = mid-1;
    }

    return l;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> v(mat.size());
    for (int i = 0; i < mat.size(); i++) {
        int c = countsoldiers(mat[i]);
        v[i] = 1000*c + i;
    }

    sort(v.begin(), v.end());
    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        res[i] = v[i] % 1000;
    }

    return res;
}

// or sort the matrix after appending index, then retrieve index
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    const int n = mat[0].size();
    for (int i = 0; i < mat.size(); i++){
        mat[i].push_back(i);
    }
    sort(mat.begin(), mat.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++){
        ans[i] = mat[i][n];            
    }
    return ans;
}




// // or use a priority queue (long)
// // CompareHeapElements is used for modifying the comparator of priority queue, as per question
// struct CompareHeapElements {
//     bool operator()(pair<int, int> const& p1, pair<int,int> const& p2)
//     {
//         if(p1.first<p2.first){
//             return true;
//         }
//         else if(p1.first==p2.first && p1.second<p2.second){
//             return true;
//         }
//         return false;
//     }
// };

// class Solution {
//     // calculate the soldier count using binary search
//     int calculateSoldierCount(vector<int>& v) {
//         int l=0; int h=v.size()-1;
//         while(l<=h) {
//             int mid=l+(h-l)/2;
//             if(v[mid]==0) {
//                 h=mid-1;
//             } else {
//                 l=mid+1;
//             }
//         }
//         return l;
//     }
    
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
//         // We will use max_heap of pairs because we need the top k minimum strength row index(s)
//         // each element of max_heap will contain {each row soldier count, that row index}.
//         priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;
        
//         // Iterating the matrix and find the total number of soldiers in each row,
//         // then push {soldier_count,row_index} to the min_heap
//         for(int i=0;i<mat.size();++i){
//             max_heap.push({calculateSoldierCount(mat[i]),i});
//             if(max_heap.size()>k){
//                 max_heap.pop();
//             }
//         }
        
//         vector<int>ans;
//         while(max_heap.size()){ // pushing the top k smallest elements of min_heap to "ans"
//             ans.push_back(max_heap.top().second);
//             max_heap.pop();
//         }
		
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };