class Solution {
private:
    void permu(vector<int> &nums, vector<vector<int>> &ans, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]); // Swap to fix the current element
            permu(nums, ans, index + 1); // Recurse for the next index
            swap(nums[index], nums[i]); // Backtrack to restore the original order
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permu(nums, ans, 0); // Start recursion from index 0
        return ans;
    }
};
