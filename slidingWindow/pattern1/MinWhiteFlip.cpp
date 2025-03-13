// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// You are given a 0-indexed string blocks of length n and an integer k. Each character in the string is either 'W' (representing a white block) or 'B' (representing a black block).


// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
// so that blocks = "BBBBBBBWBW". 
// It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.
// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.
class Solution {
    public:
    //brute force sliding window
        int minimumRecolors(string blocks, int k) {
            // appraoch1 brute force  
            int n = blocks.length();
            // int mini = INT_MAX;
            // for(int i=0;i<=n-k;i++) {
            //     int ct=0;
            //     for(int j=i;j<i+k;j++) {
            //         if(blocks[j] == 'W') {
            //             ct++;
            //         }
            //     }
            //     mini = min(ct,mini);
            // }
            // return mini;
    
             // appraoch 2 sliding window 
             int left =0,whiteCount=0,mini=INT_MAX; 
    
             for(int right =0;right<n;right++) {
                 if(blocks[right] == 'W') {
                        whiteCount++;
                 }
    
                 if(right - left + 1 == k) {  //k size window
                    mini = min(mini,whiteCount);
                    
                    if(blocks[left] == 'W') whiteCount--;
                    left++; // move right
                 }
             }
             return mini;
        }
    };