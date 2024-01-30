#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseKstep(vector <int> &v, int k) {
    int n = v.size();
     reverse(v.begin(),v.end()-k); // 4 3 2 1 5 6 
    // reverse(v.begin()+n-k,v.end()); // 1 2 3 4 6 5
}
int main()
{
    vector<int> v = {1,2,3,4,5,6};
    int n = v.size();
    int k = 2;
    reverseKstep(v,k);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
    auto max = *max_element(v.begin(),v.end());
    cout << "Max : "<<max<<endl;
    auto min = *min_element(v.begin(),v.end());
    cout << "min : "<<min<<endl;
    return 0;
}