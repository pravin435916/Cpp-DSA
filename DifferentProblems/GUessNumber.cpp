#include <iostream>
using namespace std;

void findNo(int n) {
    int x;
    int ct=0;
    while(true) {
        cin >> x;
    if(n == 0) {
        return;
    } // base case simple
    int mid = n/2;
    if(n == x) {
        cout << "Got it"<<endl;
        cout << "in "<<ct<<" ways"<<endl;
        exit;
    }else if(n > x) {
        ct++;
        cout << "less than x"<<endl;
    }else{
        cout << "grater than x"<<endl;
        ct++;
    }
    }
}
int main()
{
   int num = 15;
   findNo(num);
return 0;
}