class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            // int n = nums.size();
            // int q = queries.size();
            // // If the array is already zero, return 0 immediately
            // bool isZeroArray = true;
            // for (int num : nums) {
            //     if (num != 0) {
            //         isZeroArray = false;
            //         break;
            //     }
            // }
            // if (isZeroArray)
            //     return 0;
            // brute force to pocess each query and apply operation
            // for (int k = 0; k < q; k++) {
            //     int l = queries[k][0], r = queries[k][1], val = queries[k][2];
    
            //     // Decrease values within range [l, r] by at most 'val'
            //     for (int i = l; i <= r; i++) {
            //         nums[i] = max(0, nums[i] - val);
            //     }
    
            //     // Check if array is zero
            //     bool isZeroArray = true;
            //     for (int num : nums) {
            //         if (num != 0) {
            //             isZeroArray = false;
            //             break;
            //         }
            //     }
            //     if (isZeroArray)
            //         return k + 1; // Found the minimum k
            // }
    
            // return -1; // If nums is not fully zero after all queries
    
            // optimized : Difference Array + Prefix sum
    
            int n = nums.size(), left = 0, right = queries.size();
    
            // Zero array isn't formed after all queries are processed
            if (!canFormZeroArray(nums, queries, right)) return -1;
    
            // Binary Search
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (canFormZeroArray(nums, queries, middle)) {
                    // result
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
    
            // Return earliest query that zero array can be formed
            return left;
        }
    
    private:
        bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries,int k) {
            int n = nums.size(), sum = 0;
            vector<int> diff(n,0);
    
            // Process query
            for (int queryIndex = 0; queryIndex < k; queryIndex++) {
                int l = queries[queryIndex][0];
                int r = queries[queryIndex][1];
                int val = queries[queryIndex][2];
    
                // Process start and end of range
                diff[l] += val;
                if(r + 1 < n)
                  diff[r + 1] -= val;
            }
            int curSum=0;
            // Check if zero array can be formed
            for (int i = 0; i < n; i++) {
                curSum += diff[i];
                diff[i] = curSum;;
                if (nums[i] - diff[i] > 0)  return false;  // it should be lesss than 0 
            }
            return true;
        }
    };


// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2

// Explanation:

// For i = 0 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [1, 0, 1].
// For i = 1 (l = 0, r = 2, val = 1):
// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
// The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.