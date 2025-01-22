#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum = (sum + i) % k;
            if (sum < 0)
                sum = sum + k; // ADD k if sum negative to make it positive
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};