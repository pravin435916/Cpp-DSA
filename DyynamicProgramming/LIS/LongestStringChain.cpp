// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
class Solution {
    public:
    //    int dp[1001][1001]; 
       vector<vector<int>> dp;
       bool checkPredecessor(string s1,string s2) {
           int l1 = s1.size();
           int l2 = s2.size();
           if(l1 +1 != l2) return false;
           int i=0,j=0;
           bool skip = false;
           while(j < l2) {
               if(i < l1 && s1[i] == s2[j]) {
                   i++;
               }else if(!skip) {
                   skip = true;
               }else{
                   return false;
               }
               j++;
           }
           return true;
       }
        int solve(int idx,int prev,int n ,vector<string> &words) {
           if(idx == n) return 0;
           
           if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
           int nottake = solve(idx+1,prev,n,words);
           int take =0;
           
           if(prev == -1 || checkPredecessor(words[prev],words[idx])) {
               take = 1+solve(idx+1,idx,n,words);
           }
           
           return dp[idx][prev+1] = max(take,nottake);
       }
        int longestStrChain(vector<string>& words) {
            int n = words.size();
            dp.assign(n,vector<int>(n+1,-1));
            // memset(dp,-1,sizeof(dp));
            sort(words.begin(),words.end(),[](string &a,string &b){
                return a.size() < b.size();  // sort by length
            });
            return solve(0,-1,n,words);
        }
    };