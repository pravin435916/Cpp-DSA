#include <iostream>
#include <algorithm> // for std::sort
#include <string>
using namespace std;

void substring(string str,string ans) {
    if(str.length() == 0) {
        cout << ans << endl;
        return;
    } // base case simple
    substring(str.substr(1),ans);
    substring(str.substr(1),ans+str[0]);
    }
int main()
{
    string str = "abc";
    string ans = "";
    substring(str,ans);

    return 0;
}

//                  substring("abc", "")
//                 /                   \
//  substring("bc", "")           substring("bc", "a")
//      /        \                   /              \
// sub("c", "")  sub("c", "b")  sub("c", "a")    sub("c", "ab")
//  /     \        /     \        /    \           /       \     
//  ""     "c"   "b"    "bc"   "a"    "ac"        "ab"   "abc"
