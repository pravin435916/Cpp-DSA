#include <iostream>
#include <string>
using namespace std;

string replace(string str) {
    string ans = "";
    int i = 0;
    if (str.length() == 0 ) {
        return "";
    }
    while(i < str.length()) {
        if(str[i] == '.') {
            ans+="[.]";
        }else{
            ans = ans + str[i];
        }
        i++;
    }
    return ans;
}

int main() {
    string str = "abc.de.fg";
    string ans = replace(str);
    cout << ans;

    return 0;
}
