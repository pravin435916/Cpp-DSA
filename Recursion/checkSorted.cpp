#include <iostream>
#include <vector>
using namespace std;

bool CheckSorted(vector<int> a,int idx) {
    int n = a.size();
    if(idx >= n-1) return true;
    if(a[idx] > a[idx+1]) return false;
    return CheckSorted(a,idx+1);
    
}
int main()
{
    vector<int> a = {1,2,2,4,5};
    // (CheckSorted(a,0)) ? cout<<"true" : cout<< "false";
    cout << "Array is " << (CheckSorted(a,0) ? "sorted." : "not sorted.") << endl;

    return 0;
}