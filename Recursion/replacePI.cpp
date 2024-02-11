#include <iostream>
using namespace std;

void replacePI(string str) {
    if(str.length() == 0) {
        return;
    } // base case simple
    if(str[0] == 'p' && str[1] == 'i') {
        cout << "3.14";
        replacePI(str.substr(2));
    }else{
        cout << str[0];
        replacePI(str.substr(1));
    }
}
int main()
{
    string str = "piyupayupiyu";
    replacePI(str);

    return 0;
}