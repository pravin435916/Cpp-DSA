
class Solution {
    public:
      // Function to get the maximum total value in the knapsack.
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          vector<pair<double,int>> ratios;
          int n = val.size();
          for(int i=0;i<n;i++) {
              double ratio = (double) val[i]/(double)wt[i];
              ratios.push_back({ratio,i});
          }
          sort(ratios.begin(),ratios.end());
          double total =0;
          for(int i=n-1;i>=0;i--) {
              int idx = ratios[i].second;
              
              if(wt[idx] <= capacity) {
                  total += val[idx];
                  capacity -= wt[idx];
              }else{
                  total += ((double)capacity/(double)wt[idx]) * (double)val[idx];
                  break;
              }
          }
          return total;
      }
  };