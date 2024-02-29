#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

void substring(string str,string ans) {
    if(str.length() == 0) {
        cout << ans << endl;
        return;
    } // base case simple
    char ch = str[0];
    string ros = str.substr(1);
    substring(ros,ans);
    substring(ros,ans+ch);
    }
int main()
{
    string str = "abc";
    string ans = "";
    substring(str,ans);

    return 0;
}