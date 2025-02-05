class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        makeCombination(candidates, target, 0, cur, 0, res);
        return res;
    }

private:
    void makeCombination(vector<int>& arr, int target, int idx,vector<int>& cur, int total,vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(cur);
            return;
        }

        if (total > target || idx >= arr.size()) {
            return;
        }

        cur.push_back(arr[idx]);
        makeCombination(arr, target, idx, cur, total + arr[idx], res);
        cur.pop_back();

        // now for next index
        makeCombination(arr, target, idx + 1, cur, total, res);
    }
};