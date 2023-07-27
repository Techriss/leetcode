#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() != unordered_set(nums.begin(), nums.end()).size();
    }
}