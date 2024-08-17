class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
       int n = nums.size();
       vector<long long int> res;
       for(int i=0;i<n;i++) {
           long long int prod =1;
           for(int j=0;j<n;j++) {
               if(i!=j) {
                   prod *= nums[j];
               }
           }
           res.push_back(prod);
       }
       return res;
    }
};