// according to higher frequency,store highest frequency elements to add first k highest frequency elements to the heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            int val=it.first;
            int freq=it.second;
            pq.push({freq,val});
        }
        vector<int> ans;
        while(!pq.empty() && k--){
            int curr=pq.top().second;
            pq.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};