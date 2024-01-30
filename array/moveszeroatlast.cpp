#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    // vector<int> v = {1,0,1,0,9};
    vector<int> v = {1,2,3,4,5,6,8,7,9,12};
    cout << v.size() << endl;
     for (int i =0; i < v.size(); i++){
        for (int j =i+1; j < v.size(); j++){ 
        if(v[j]% 2 == 0) {
            swap(v[i],v[j]);
        }
        }
    }
    //  for (int i =0; i < v.size(); i++){
    //     for (int j =i+1; j < v.size(); j++){ 
    //     if(v[j] != 0) {
    //         swap(v[i],v[j]);
    //     }
    //     }
    // }
    for(int i: v) {
        cout<< i <<" ";
    }
    return 0;
}