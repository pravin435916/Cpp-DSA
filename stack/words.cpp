#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;
int main()
{
    string word = "Hello How Are YOu ";
    stack<string> str;  // string
    vector<string> v;
    for(int i=0;i<word.length();i++) {
        if(word[i] != ' ') {
            str.push(word);
        }else{
            str.pop();
        }
    }
     while(!str.empty()) {
        v.push_back(str.top());
        str.pop();
    }
    for(string x : v) {
        cout << x << " ";
    }
    return 0;
}