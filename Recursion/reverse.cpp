#include <iostream>
using namespace std;

void reverse(string str) {
    if(str.length() == 0) {
        return;
    } // base case simple
        // cout<<str<<endl;
    reverse(str.substr(1)); //in parameter pass same argument modification
    // cout<<str<<endl;
    cout << str[0]<<endl ; //do only first print
}
int main()
{
    string str = "Pravin";
    // cout << str.substr(1) << endl;
    reverse(str);

    return 0;
}