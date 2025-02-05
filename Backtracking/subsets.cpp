class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int idx, vector<int>& curr) {
        result.push_back(curr); // Store current subset

        for (int i = idx; i < nums.size(); i++) {
            // Include the current number
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr);
            curr.pop_back(); // Backtrack to remove the last element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        return result;
    }
};
