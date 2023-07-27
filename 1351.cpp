#include <iostream>
#include <vector>
using namespace std;

// binary search
int countnegrow(vector<int> &v, int &r) {
    int l = 0;
    while (l <= r) {
        int mid = (l+r)/2;
        if (v[mid] < 0) r = mid-1;
        else l = mid+1;
    }

    return v.size()-l;
}

// since rows are sorted, find number of neg elements with binsearch
int countNegatives(vector<vector<int>>& grid) {
    int c = 0;
    int newr = grid[0].size()-1;
    for (auto &r : grid) c += countnegrow(r, newr);
    return c;
}


// but it can be even faster, as the matrix is also sorted by rows, so we dont need to find r in binsearch each time
// ==> added int &r






// or traverse from bottom left to top right adding count
int countNegatives(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    
    int i = m-1;
    int j = 0;
    // to start from the grid[m-1][0] position
    int count = 0;
    
    while (i >= 0 && i < m && j >= 0 && j < n){
        if (grid[i][j] < 0) {
            count += (n-j);
            i--;
        }
        else j++;
    }       
    
    return count;
}



/*

[[4, 3, 2, -1],
 [3, 2, 1, -1],
 [1, 1,-1, -2],
 [-1,-1,-2,-3]]
*/