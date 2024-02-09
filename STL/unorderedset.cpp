#include <bits/stdc++.h>
using namespace std;
int doUnion(int a[], int n, int b[], int m)  {
        vector<int> v;
        int count = 0;
        std::unordered_set<int> un;
        for(int i=0;i<n;i++) {
            un.insert(a[i]);
        }
        for(int i=0;i<m;i++) {
            un.insert(b[i]);
        }
        for(int num : un) {
            count++;
        }
        return count;
    }

int main()
{
    int a[] = {1,2,3,4,5,6};
    int b[]= {2,5,6,7};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(a[0]);
    int uni = doUnion(a,n,b,m);
        cout << uni << " ";
    return 0;
}