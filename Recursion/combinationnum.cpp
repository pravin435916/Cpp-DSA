#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void board(int n, vector<int>& ans, int k, int last, vector<vector<int>>& res) {
        if (ans.size() == k) {
            res.push_back(ans);
            return;
        }
        if (ans.size() > k) return;
        for (int i = last; i <= n; i++) {
            ans.push_back(i);
            board(n, ans, k, i + 1, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        board(n, ans, k, 1, res);
        return res;
    }
};

int main() {
    Solution s1;
    int n = 4, k = 2;  // Default input
    vector<vector<int>> combinations = s1.combine(n, k);

    // Output the combinations
    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
