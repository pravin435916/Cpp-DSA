#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

string removeDuplicate(string str) {
    if(str.length() == 0) {
        return "";
    } // base case simple
    char ch = str[0];
    string ans = removeDuplicate(str.substr(1));
    if(ch == ans[0]){
       return ans;
    }
    return ch+ans;
    }
int main()
{
    string str = "adfgludfhbedcjbekhascfkhelfglbdvcjbdevjbedbvljewagsluvfgslcvdbcjle svjbeas;ivhipeshi;vheshvulesgpfuq3wfci;edsjvb";
    sort(str.begin(),str.end());
    string ans = removeDuplicate(str);
    cout << ans;

    return 0;
}