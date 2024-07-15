// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int main() {
    int arm;
    cin>>arm;
    int x = arm;
    int res =0;
    int d = arm;
    int r=0;
    while(d > 0) {
        r++;
        d/=10;
    }
    while(x > 0) {
        int temp = x % 10;
        res += pow(temp,r);
        x/=10;
    }
    
    cout<<(res == arm)<<endl;
    return 0;
}