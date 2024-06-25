#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
class MinHeap {
    public:
    void hello() {
        cout<<"hello called"<<endl;
    }
    int nChocolates(int a,vector<int> bi) {
        priority_queue<int> maxHeap;
        int sum=0;
        for(auto x : bi) maxHeap.push(x);
        while(a--) {
            int eat = maxHeap.top();
            maxHeap.pop();
            sum+=eat;
            cout<<"sum  -> "<<sum<<endl;
            maxHeap.push(floor(eat/2));
        }
        return sum;
    }

};

int main() {
    MinHeap heap;
    vector<int> bi ={2,4,6,8,10};
    int a = 4;
    
    int ans = heap.nChocolates(a,bi);
    cout << "ans =  : "<<ans<<endl;
    return 0;
}
