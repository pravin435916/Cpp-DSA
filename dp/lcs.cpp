#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int lcs(string s1, string s2, int n) {
       int dp[n+1][n+1];
       for(int i=0;i<=n;i++) {
         for(int j=0;j<=n;j++) {
            if(i==0 || j==0) dp[i][j] = 0;
         }
       }
       for(int i=1;i<=n;i++) {
         for(int j=1;j<=n;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
         }
       }
       return dp[n][n];
    }
int main() {
  //approch to fin lps
  // find its and its reverse => lcs
    string str1 = "babad";
    string str2 = "ababd";
    int n = str1.length();
    cout<<lcs(str1,str2,n);  //return the longest common subsequence length
}