//leetcode : 494. Target Sum
#include <bits/stdc++.h>
class Solution {
public:
    int totalWays = 0;
    int findTargetSumWays(std::vector<int>& nums, int target) {
        countWays(nums, 0, 0, target);
        return totalWays;
    }

private:
    void countWays(std::vector<int>& nums, int curIdx, int curSum, int target) {
        if (curIdx == nums.size()) {
            if (curSum == target) {
                totalWays++;
            }
            return;
        }
        countWays(nums, curIdx + 1, curSum + nums[curIdx], target); // add
        countWays(nums, curIdx + 1, curSum - nums[curIdx], target); // sub
    }
};