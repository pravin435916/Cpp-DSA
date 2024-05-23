// #include <iostream>
// #include <vector>
// #include <stack>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     vector<int> arr = {4,3,2,6,8,3};
//     stack<int> st;
//     vector<int> result(arr.size(), -1); // Initialize result vector with -1

//     for (int i = 0; i < arr.size(); i++) {
//         while (!st.empty() && arr[st.top()] < arr[i]) {
//             result[st.top()] = arr[i];
//             st.pop();
//         }
//         st.push(i);
//     }
//     for(int x : result) {
//         cout << x << " ";
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
vector<int> NextGreater(vector<int> arr, int n) 
    {
        vector<int> ans(arr.size(), -1);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--) { //next
            // for(int i=0;i<n;i++) { // prev
            int cur = arr[i];
            while(!st.empty() && st.top() <= cur) {
                st.pop();
            }
            if(!st.empty()) {
            ans[i] = st.top();
            }
            st.push(cur);
        }
       return ans;
    } 
int main()
{
    vector<int> arr = {4,8,5,6,7};
    vector<int> anns = NextGreater(arr,5);
    for(int x : anns) {
        cout << x << " ";
    }
    return 0;
}