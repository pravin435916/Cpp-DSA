#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void zigZag(int arr[], int n) {
        sort(arr,arr+n);
        for(int i=1;i<n-1;i+=2) {
                swap(arr[i],arr[i+1]);
        }
    }
int main()
{
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    zigZag(arr,n);
     for (int i =0; i < n; i++){
        cout<< arr[i] << " ";
    }
}