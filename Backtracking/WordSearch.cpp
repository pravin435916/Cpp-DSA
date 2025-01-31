// Time Complexity :- o(n*m*4^k)
// But How :- n*m for exploring all cells 
// 4^k ? k = word length in worst case we can explore all 4 paths . so for each word we r traversijg all poaths so o(4^k)
// for eg. in recursion ; for take not take we explore 2 paths for all nodes so o(2^n)
class Solution {
public:
    bool findWord(vector<vector<char>>& mat, int i, int j, int idx,string& word) {
        int n = mat.size();
        int m = mat[0].size();
        if (idx == word.length())
            return true; // word matched
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == '$') {
            return false;
        }
        if (mat[i][j] != word[idx]) return false;      // not matched with word
        char temp = mat[i][j]; // stored for backtrack
        mat[i][j] = '$';       // marked
        bool found = findWord(mat, i + 1, j, idx + 1, word) ||
                     findWord(mat, i - 1, j, idx + 1, word) ||
                     findWord(mat, i, j + 1, idx + 1, word) ||
                     findWord(mat, i, j - 1, idx + 1, word);
        mat[i][j] = temp; // backtrack
        return found;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && findWord(mat, i, j, 0, word)) {  // matched with 0 index 
                    return true;
                }
            }
        }
        return false;
    }
};

