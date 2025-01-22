// C++ Implementation:

#include <vector>
using namespace std;


vector<int> computePrefixSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for(int i=1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    return prefixSum;
}