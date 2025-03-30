int activitySelection(vector<int> &start, vector<int> &finish) {
    // code here
    vector<pair<int,int>> temp;
    for(int i=0;i<start.size();i++) {
        temp.push_back({start[i],finish[i]});
    }
    
    sort(temp.begin(),temp.end(),[](auto &a,auto &b) {
        return a.second < b.second;
    });
    
    int ct = 1;
    int fTime = temp[0].second;
    
    for(int i=1;i<start.size();i++) {
        if(temp[i].first > fTime) {
            ct++;
            fTime = temp[i].second;
        }
    }
    return ct;
}