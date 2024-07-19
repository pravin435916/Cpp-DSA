#include <iostream>
#include <string>
using namespace std;

void queen(int n,int qs,bool arr[],string ans,int last) {
    if(qs == n) {
        cout<<ans<<endl;
        return;
    }
    for(int i=last;i<4;i++) {
        if(arr[i] == false ) {
            arr[i] = true;
            queen(n,qs+1,arr,ans+"Q"+to_string(qs)+"B"+to_string(i),i+1);
            arr[i] = false; //backtrack
        }
    }
}
int main()
{
    bool arr[4];
    queen(2,0,arr,"",0);
    return 0;
}
//Hw. string given , multiple charcter,remove duplicates aaaaccccefff   ace