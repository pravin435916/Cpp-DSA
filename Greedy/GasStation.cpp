class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            // Your code here
            int total = 0;
            int req = 0;
            int n = gas.size();
            for(int i=0;i<n;i++) {
                total += gas[i];
                req += cost[i];
            }
            
            if(total < req) return -1;
            
            int ct=0;
            int curGas = 0;
            for(int i=0;i<n;i++) {
                curGas += gas[i] - cost[i];
                if(curGas < 0) {
                    curGas = 0;
                    ct = i+1;
                }
            }
            return ct;
        }
    };