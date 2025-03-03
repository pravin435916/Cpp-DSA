class Solution {
    public:
        int lcs(int i,int j,string s1,string s2) {
            if(i>= s1.length() || j>= s2.length()) {
                return 0; 
            }
    
            if(s1[i] == s2[j]) {
                return 1 + lcs(i+1,j+1,s1,s2);
            }else{
                return max(lcs(i+1,j,s1,s2),lcs(i,j+1,s1,s2));
            }
        }
        int longestCommonSubsequence(string s1, string s2) {
            return lcs(0,0,s1,s2);
        }
    };