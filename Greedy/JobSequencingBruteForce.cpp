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
    vector<int> mark(maxDeadline+1,-1);
    int ct=0,maxi=0;
    for(int i=0;i<n;i++) {
        int dead = temp[i].first;
        int pro = temp[i].second;
        
        for(int j=dead;j>0;j--) {  //checking from deadline to 1  where get space left then mark it 
            if(mark[j]==-1) {
            mark[j] = i;
            maxi += pro;
            ct++;
            break;
            }
        }
        
    }
    
    return {ct,maxi};
}