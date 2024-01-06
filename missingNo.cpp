#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v = {1,2,4,5};
    int miss = -1;
     for (int i =1; i <= v.size(); i++){
        if(v[i] != i+1) {
            miss = i+1;
            break; 
        }
    }
    cout<<miss;
    // for(int i: v) {
    //     cout<< i <<" ";
    // }
    return 0;
}