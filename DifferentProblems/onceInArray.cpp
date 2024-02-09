#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,1,2,3,4,3};
    int n = 7;
    int once;
    for(int i=0;i<n;i++) {
        once ^= arr[i];
    }
    cout<< once ;

    return 0;
}