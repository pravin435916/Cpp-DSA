/*Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.*/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int it : nums) {
            sum += it; 
            count += mp[sum - goal];
            mp[sum]++; 
        }
        return count;
    }
};