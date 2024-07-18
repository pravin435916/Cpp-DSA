#include <iostream>
#include <string>
using namespace std;

void permutation(string s,string ans) {
    if(s.length() ==  0) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++) {
        permutation(s.substr(0,i)+s.substr(i+1),ans+s[i]);
    }
}
int main()
{
    permutation("abc","");
    return 0;
}