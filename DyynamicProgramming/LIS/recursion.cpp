int solve(int idx, int prev, vector<int>& nums) {
    if (idx == nums.size()) return 0; // Base case

    // Option 1: Skip current element
    int nottake = solve(idx + 1, prev, nums);

    // Option 2: Take current element (only if it forms an increasing subsequence)
    int take = 0;
    if (prev == -1 || nums[prev] < nums[idx]) {
        take = 1 + solve(idx + 1, idx, nums);
    }

    return max(take, nottake);
}
