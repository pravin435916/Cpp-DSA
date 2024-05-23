#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findLength(vector<int>& nums, int k) {
    // curr is the current sum of the window
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 2, 7, 4, 2, 1, 1, 5};
    int k = 8;
    int res = findLength(nums,k);
    cout<<res;
    return 0;
}