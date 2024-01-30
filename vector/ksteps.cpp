#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 2;
    k = k % v.size();    // if larger size for %
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin() + k);
    reverse(v.begin() + k,v.begin() + v.size());
    for(int i:v) {
        cout<< i << " ";
    }
    return 0;
}
// 1 2 3 4 5 
// 4 5 1 2 3

// 5 4 3 2 1