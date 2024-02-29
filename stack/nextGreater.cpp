#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr = {4,3,2,6,8,3};
    stack<int> st;
    vector<int> result(arr.size(), -1); // Initialize result vector with -1

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(int x : result) {
        cout << x << " ";
    }
    return 0;
}