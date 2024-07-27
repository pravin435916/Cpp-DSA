#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.empty()<<endl;
    return 0;
}