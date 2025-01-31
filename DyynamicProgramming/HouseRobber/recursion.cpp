#include <iostream>
#include <vector>
using namespace std;
// Time Complexity :- o(2^n) for each node we r exploring 2 paths
// Space :- o(n) for recursion stack
class Solution {
public:
    // Recursion for House Robber 1
    int helper(int i, vector<int> &nums) {
        int n = nums.size();
        if (i >= n) return 0;
        int take = nums[i] + helper(i + 2, nums);
        int notTake = helper(i + 1, nums);
        return max(take, notTake);
    }

    int rob(vector<int> &nums) {
        return helper(0, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}