class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            // standard template Q 
            // approach just sliding window + hashmap
            int n = nums.size();
            unordered_set<int> st(nums.begin(),nums.end());
            int totalDistinct = st.size();
    
            int left = 0;
            unordered_map<int,int> mp; 
            int count = 0;
            for(int right = 0;right<n;right++) {
                mp[nums[right]]++;
    
                while(mp.size() == totalDistinct) {
                    count += (n-right);
                    mp[nums[left]]--;
                    if(mp[nums[left]] == 0) mp.erase(nums[left]);
                    left++;
                }
            }
            return count;
        }
    };