#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // 1 & 1 -> 1  , 0 & 1 -> 0 
        n >>= 1;
    }
    return count;
}

int main()
{
    int n = 6;
    int arr[] ={5,2,8,12,7,6};
    int bit;
    for(int i=0;i<n;i++) {
        bit = countSetBits(arr[i]);
        cout << arr[i] <<" = "<< bit <<endl;
    }
    // sort(arr,arr+n);
    //5 6 12 2 7 8
    // int res = countSetBits(n);
    // cout << res;
}