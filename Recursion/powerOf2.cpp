#include <iostream>
using namespace std;

int powerofTwo(int m, int n) {
    if(n == 0) {
        return 1;
    }
    return m * powerofTwo(m,n-1);
}
int main()
{
    int m =3;
    int n =4;
    int x = powerofTwo(m,n);
    cout<< x ;

    return 0;
}