#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxSubarray(vector<int> nums, int n) {
    int maxi = INT8_MIN;
    int sum =0;
    for (int i = 0; i < n; i++) {
        sum+=nums[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) {
            sum =0;
        }
    }
    return maxi;
}
// int maxSubarray(vector<int> nums, int n) {
//     int maxi = INT8_MIN;
//     int sum =0;
//     for (int i = 0; i < n; i++) {
//         sum =0;
//         for(int j=i;j<n;j++) {
//             sum+=nums[j];
//         maxi = max(maxi, sum);
//         }
//     }
    
//     return maxi;
// }

int main()
{
    vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
    int n = nums.size();
    int res = maxSubarray(nums,n);
    cout<<res;
    return 0;
}