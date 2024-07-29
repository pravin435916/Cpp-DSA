class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 1) sorting
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n-k];
        // 2)maxHeap
        priority_queue<int> maxHeap; 
        for(int x : nums){
            maxHeap.push(x);
        }
        // int i=1;
        // while(!maxHeap.empty() && i < k) {
        //     maxHeap.pop();
        //     i++;
        // }
        k--;
        while(k--) {
            int mx = maxHeap.top();
            maxHeap.pop();
        }
        return maxHeap.top();
        // 3) Min Heap
        // priority_queue<int, vector<int>,greater<int>> minHeap; 
        // for(int x : nums){
        //     minHeap.push(x);
        //     if(minHeap.size() > k){
        //         minHeap.pop();
        //     }
        // }
        // return minHeap.top();
    }
};