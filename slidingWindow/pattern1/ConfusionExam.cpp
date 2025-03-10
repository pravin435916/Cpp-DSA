class Solution {
    public:
        int maxConsecutiveChar(string answerKey, int k,char ch) {
            int n = answerKey.length();
            int left =0,count=0,maxi=INT_MIN;
    
             for(int right =0;right<n;right++) {
                if(answerKey[right] != ch) {
                    count++;
                }
    
                if(count > k) {  //k size window
                    if(answerKey[left] != ch) count--;
                    left++; // move right
                }
                maxi = max(maxi,right-left+1);
             }
            return maxi;
        }
        int maxConsecutiveAnswers(string answerKey, int k) {
            return max(maxConsecutiveChar(answerKey, k, 'T'), 
                       maxConsecutiveChar(answerKey, k, 'F'));
    
        }
    };

//     Input: answerKey = "TTFF", k = 2
// Output: 4
// Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
// There are four consecutive 'T's.
// Example 2:

// Input: answerKey = "TFFT", k = 1
// Output: 3