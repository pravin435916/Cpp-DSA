#include <iostream>
#include <vector>
using namespace std;

 void convertToWave(int n, vector<int>& arr){
        int len;
        if(n%2 != 0 ) {
            len = n-1;
        }else{
            len = n;
        }
        for(int i=0;i<len;i+=2) {
            swap(arr[i],arr[i+1]);
        }
    }
int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int n = arr.size();
    convertToWave(n,arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}