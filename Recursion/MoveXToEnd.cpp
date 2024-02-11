#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

string movex(string str) {
    if(str.length() == 0) {
        return "";
    } // base case simple
    char ch = str[0];
    string ans = movex(str.substr(1));
    if(ch == 'x'){
       return ans+ch;
    }
    return ch+ans;
    }
int main()
{
    string str = "axxxxaaabbbxxsdsd";
    string ans = movex(str);
    cout << ans;

    return 0;
}