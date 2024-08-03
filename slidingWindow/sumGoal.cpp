#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums,int goal) {
        int n = nums.size();
        int i=0;
        int j=0;
        int cur =0;
        int ct =0;
        while(j<n) { 
           cur+=nums[j];
           while(cur > goal) {
            cur-=nums[i];
            i++;
           }
           if(cur == goal) ct++;
           j++;
        }
        return ct;
    }
};
int main() {
    Solution s1;
    vector<int> nums = {1,2,3,2};
    int sum = s1.numSubarraysWithSum(nums,5);
    cout<<sum<<endl;
    return 0;
}