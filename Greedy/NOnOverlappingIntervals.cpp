class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& temp) {
            int ct = 1;
            if (temp.empty()) return 0;
            sort(temp.begin(), temp.end(),[](auto& a, auto& b) { 
                   return  a[1] < b[1]; 
                 });
            int fTime = temp[0][1]; // declare after sorting
            for (int i = 1; i < temp.size(); i++) {
                if (temp[i][0] >= fTime) {
                    ct++;
                    fTime = temp[i][1];
                }
            }
            return temp.size()-ct;
        }
    };
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.