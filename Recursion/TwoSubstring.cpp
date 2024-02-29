#include <iostream>
#include <string>
using namespace std;

void substring(string str1, string str2, string ans) {
    if (str1.length() == 0 && str2.length() == 0) {
        cout << ans << endl;
        return;
    }

    if (str1.length() > 0) {
        substring(str1.substr(1), str2, ans + str1[0]);
    }

    if (str2.length() > 0) {
        substring(str1, str2.substr(1), ans + str2[0]);
    }
}

int main() {
    string str1 = "abcd";
    string str2 = "e";
    substring(str1, str2, "");

    return 0;
}
