// Time Complexity: O(n)
// Space Complexity:-
// The space used by the result vector is O(n).
// The recursive call stack uses O(log₁₀(n)) space in the worst case.
// Space Complexity: O(n)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <=9; ++i) {
            solve(n,i,res);
        }
        return res;
    }
    private:
    void solve(int n,int cur,vector<int> &res) {
        if(cur > n) return; // check here
        res.push_back(cur);
        for(int i=0;i<=9;i++) { // till 9 for append
           int newNum = cur * 10 + i; // new Number 
           if(newNum > n) return;
           solve(n,newNum,res);
        }
    }
};