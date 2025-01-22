// Condition : Sum of subarray equals k
// Negative values ALLOWED in Input
#include <unordered_map>
#include <vector>
using namespace std;
// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> mp;
        mp[0] = 1;   // mostly for sinlkge element like if we want to find 2 inm subarray with sum 2 (2-2 =0) so then we need to add 0 to map
        int sum = 0, count = 0;

        for (int x : nums) {
            sum += x;

            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count; 
    }
};