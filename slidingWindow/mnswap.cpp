class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = count(nums.begin(),nums.end(),1);
        if(totalOnes == 0) return 0;
        int i=0;
        int j=0;
        int curOnes =0;
        int maxCount =0;
        while(j<2*n) {  //its circular thats why 
           if(nums[j%n] == 1) curOnes++;
           if( j-i+1 > totalOnes) {
            curOnes-=nums[i%n];
            i++;
           }
           maxCount = max(maxCount,curOnes);
           j++;
        }
        return totalOnes - maxCount;
    }
};