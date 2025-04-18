vector<int> calculateSpan(vector<int>& arr) {
    //brute force
    // vector<int> res(arr.size(),1);
    // int n = arr.size();
    // for(int i=0;i<n;i++) {
    //     int span =1;
    //     for(int j=i-1;j>=0;j--) {
    //         if(arr[j] <= arr[i]) {
    //             span++;
    //         }else{
    //             break;
    //         }
    //     }
    //     res[i] = span;
    // }
    // return res;
    //optimzie o(n)  stack
    stack<int> st;
    vector<int> res(arr.size());
    int n = arr.size();
    for(int i=0;i<n;i++) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        res[i] =st.empty()? (i + 1) :( i-st.top());
        
        st.push(i);
    }
    return res;
}