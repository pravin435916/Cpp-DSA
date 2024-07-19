#include <iostream>
using namespace std;

void board(int target,string ans,int sum,int last) {
    if(sum == target) {
        cout<<ans<<endl;
        return;
    }
    if(sum > target) return;
    for(int i=last;i<=5;i++) {
    board(target,ans+to_string(i),sum+i);
    }
    // board(target,ans+to_string(1),sum+1);
    // board(target,ans+to_string(2),sum+2);
    // board(target,ans+to_string(3),sum+3);
}
int main()
{
    board(6,"",0,0);
    return 0;
}