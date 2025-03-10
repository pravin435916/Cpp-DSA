// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

class Solution {
    public:
       vector<vector<int>> dp;
        // Function to compute the edit distance between two strings
        int solve(int m,int n,string &s1,string &s2) {
            if(m == 0){
                return n; // if first string is empty then n insertions
            }
            if(n==0) {
                return m; // if second string is empty then m deletions
            }
            
            if(dp[m][n] != -1) return dp[m][n];
            
            if(s1[m-1] == s2[n-1]) {
                return dp[m][n] = solve(m-1,n-1,s1,s2); // if last char matches then move to next
            }
            
            int insert = 1 + solve(m,n-1,s1,s2); // if insert then move to next char in s2
            int del = 1 + solve(m-1,n,s1,s2); // if delete then move to next char in s1
            int replace = 1+ solve(m-1,n-1,s1,s2);  // if replace then matched both char now move
            
            return dp[m][n] = min({insert,del,replace}); 
        }
        int minDistance(string s1, string s2) {
            int m = s1.length();
            int n = s2.length();
            dp.assign(m+1,vector<int> (n+1,-1));
            return solve(m,n,s1,s2);
        }
    };