class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set;
        for(int x : nums) set.insert(x);
        priority_queue<int> maxHeap; 
        for(auto x : set){
            maxHeap.push(x);
        }
        int k = 2;
        if(set.size() <= 2) {
            return maxHeap.top();
        }
        while(k--) {
            int mx = maxHeap.top();
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};