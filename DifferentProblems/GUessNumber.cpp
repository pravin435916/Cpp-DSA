#include <iostream>
using namespace std;

void findNo(int n) {
    int x;
    while(true) {
        cin >> x;
    if(n == 0) {
        return;
    } // base case simple
    int mid = n/2;
    if(n == x) {
        cout << " got it";
        exit;
    }
    if(n > x) {
        cout << "grater than x"<<endl;
    }else{
        cout << "less than x"<<endl;
    }
    }
}
int main()
{
   int num = 5;
   findNo(num);

    return 0;
}