class Solution {
public:
    int first(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int idx = -1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                idx = mid;
                end = mid-1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return idx;
    }
     int second(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int idx = -1;
        while (start <= end) {
             int mid = start + (end - start)/2;
            if (nums[mid] == target) {
                idx = mid;
                start = mid+1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = first(nums,target);
        int idx2 = second(nums,target);
        return {idx1,idx2};
    }
};