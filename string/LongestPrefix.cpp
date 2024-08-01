// Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
// Output: gee
// Explanation: "gee" is the longest common prefix in all the given strings.
// Input: arr[] = ["hello", "world"]
// Output: -1
// Explanation: There's no common prefix in the given strings.
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        int mini = INT_MAX;
        int ct =0;
        string ex;
        for(int i=0;i<arr.size();i++) {
            if(arr[i].length() < mini) {
                ex = arr[i];
                ct = arr[i].length();
            }
        }
        for(int i=0;i<ct;i++) {
            for(int j=0;j<arr.size();j++) {
                if(arr[j][i] != ex[i]) {
                   string prefix = ex.substr(0, i);
                   return prefix.empty() ? "-1" : prefix;
                }
            }
        }
         return ex.empty() ? "-1" : ex;
    }
};