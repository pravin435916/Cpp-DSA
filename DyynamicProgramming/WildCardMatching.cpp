class Solution {
    public:
        vector<vector<int>> dp;
        bool solve(int i,int j,string &s,string &p) {
            //base cases v.v. imp
            if(i<0 && j<0) return true;  // if both string end then true
            if(i<0 && j>=0) return false;  
            // if string end mean no char to match then false
    
            if(j<0 && i>=0) {   
                // if still pattern string is there then check for all * 
                // should be there * can be empty also 
                
                for(int k=0;k<=i;k++) { 
                    if(p[k] != '*') return false; 
                }
                return true;
            }
            if(dp[i][j] != -1) return dp[i][j]; 
            //operations 
            if(p[i] == s[j] || p[i] == '?') {  // if matched or pattern ? then move
                return dp[i][j] = solve(i-1,j-1,s,p);
            }else if(p[i] == '*') {  // if * then either move in pattern or string
                return dp[i][j] = solve(i-1,j,s,p) || solve(i,j-1,s,p);
            }
            return false; 
        }
        bool isMatch(string s, string p) {
            int m = s.length();
            int n = p.length();
            dp.assign(n,vector<int> (m,-1));
            return solve(n-1,m-1,s,p); // pass first pattern and then string
        }
    };