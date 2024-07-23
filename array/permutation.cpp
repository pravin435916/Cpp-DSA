class Solution {
    private:
    // void solve(vector<int> nums, vector<vector<int>> &ans,int index) {
    //     if(index >= nums.size()) {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int j=index;j<nums.size();j++) {
    //         swap(nums[index],nums[j]);
    //         solve(nums,ans,index+1);
    //         swap(nums[index],nums[j]);
    //     }
    // } 
void permu(vector<int> &nums, vector<vector<int>> &ans, vector<int> &list, vector<bool> &check) {
    if (list.size() == nums.size()) {
        ans.push_back(list);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (check[i] == false) {
            check[i] = true;
            list.push_back(nums[i]);
            permu(nums, ans, list, check);
            check[i] = false;
            list.pop_back();
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list; // Initialize list as an empty vector
        vector<bool> check(nums.size(), false); // Initialize check vector with false values
        permu(nums, ans, list, check);
        return ans;

    } 
};