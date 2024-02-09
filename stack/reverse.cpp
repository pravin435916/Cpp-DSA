#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
int main()
{
    // stack<int> st;    //int
    // stack<char> str; //char
    stack<string> str;  // string
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    str.push("HELLO");
    str.push("PRAVIN");
    str.push("BRO");
    // str.push('H');
    // str.push('E');
    // str.push('o');
    vector<string> v;
    //  while(!st.empty()) {
    //     v.push_back(st.top());
    //     st.pop();
    // }
     while(!str.empty()) {
        v.push_back(str.top());
        str.pop();
    }
    // for(int i=0;i<v.size();i++) {
    //     cout << v[i] << " ";
    // }
    for(string x : v) {
        cout << x << " ";
    }
    return 0;
}