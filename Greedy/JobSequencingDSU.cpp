class Solution {
    public:
      int find(int i,vector<int> &parent) {
          if(i == parent[i]) return i;
          
          return parent[i] = find(parent[i],parent);
      }
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
          int n = deadline.size();
          vector<pair<int,int>> temp;
          for(int i=0;i<n;i++)  {
              temp.push_back({deadline[i],profit[i]});
          }
          
          sort(temp.begin(),temp.end(),[](pair<int,int> &a,pair<int,int> &b){
              return a.second > b.second;
          });
          int maxDeadline =0;
          for(int i=0;i<n;i++) {
              maxDeadline = max(maxDeadline,temp[i].first);
          }
         
          vector<int> parent(maxDeadline+1);
           for(int i=0;i<=maxDeadline;i++) {
              parent[i] = i;
          }
          int ct=0,maxi=0;
          for(int i=0;i<n;i++) {
              int dead = temp[i].first;
              int pro = temp[i].second;
              int slot = find(dead,parent);
              if(slot > 0) {
                  ct++;
                  maxi += pro;
                  parent[slot] = slot-1;
              }
              
          }
          
          return {ct,maxi};
      }
  };