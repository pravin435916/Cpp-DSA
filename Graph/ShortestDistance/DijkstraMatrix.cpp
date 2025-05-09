class Solution {
public:
// \Find Minimum Time to Reach Last Room I
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        res[0][0] = 0;
        pq.push({0,{0,0}});  // time,i,j
        while(!pq.empty()) {
            int curTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();
            if(i == n-1 && j == m-1) {
                return curTime;
            }
            for(auto &dir : directions){
                int i_ = i+dir[0];
                int j_ = j+dir[1];
                if(i_ >= 0 && i_ < n && j_ >=0 && j_ < m) {
                    
                   int wait = moveTime[i_][j_] - curTime;
                   if(wait < 0) wait =0;
                   int arrivalTime = curTime + wait + 1;
                   if(res[i_][j_] > arrivalTime) {
                    res[i_][j_] = arrivalTime;
                    pq.push({arrivalTime,{i_,j_}});
                   }
                }
            }
        }
        return -1;

    }
};