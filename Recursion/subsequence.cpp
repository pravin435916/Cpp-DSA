#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

void subsequence(string s,string ans) {
    if(s.length() == 0) {
        cout<<ans<<endl;
        return;
    }
    subsequence(s.substr(1),ans+"");   //substr(1) 1st string ko chhodke baki pass krdo
    subsequence(s.substr(1),ans+s[0]);
}
int main()
{
    string s = "abc";
    subsequence(s,"");
    cout<<s.substr(1);

    return 0;
}