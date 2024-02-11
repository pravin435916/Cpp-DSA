#include <iostream>
using namespace std;

void reverse(string str) {
    if(str.length() == 0) {
        return;
    } // base case simple
    reverse(str.substr(1)); //in parameter pass same argument modification
    cout << str[0] ; //do only first print
}
int main()
{
    string str = "Pravin";
    cout << str.substr(1) << endl;
    reverse(str);

    return 0;
}