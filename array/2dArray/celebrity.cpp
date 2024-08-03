class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> knows(n, 0);
        vector<int> knownBy(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    knows[i]++;
                    knownBy[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(knows[i] == 0 && knownBy[i] == n-1) {
                return i;
            }
        }
        
        return -1;
    }
};
