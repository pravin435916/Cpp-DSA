#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
vector<int> help_classmate(vector<int> arr, int n) 
    {
        vector<int> ans(5);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--) {
            int cur = arr[i];
            while(st.top() >= cur) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(cur);
        }
       return ans;
    } 
int main()
{
    vector<int> arr = {4,8,5,2,25};
    vector<int> anns = help_classmate(arr,5);
    for(int x : anns) {
        cout << x << " ";
    }
    return 0;
}