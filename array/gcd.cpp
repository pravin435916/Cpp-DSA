// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int a=24,b=36;
    while(b%a !=0) {
        int rem = b%a;
        b =a;
        a=rem;
    }
    cout<<a<<endl;

    return 0;
}