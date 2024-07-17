#include <iostream>
using namespace std;

int powerof(int m, int n) {
    if(n == 0) {
        return 1;
    }
    int f = powerof(m,n-1);
    return m * f;
}
int main()
{
    int m =2;
    int n =4;
    int x = powerof(m,n);
    cout<< x ;

    return 0;
}
//searching , sum of array , charcter find , vowels find , 
