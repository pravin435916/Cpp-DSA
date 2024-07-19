#include <iostream>
#include <string>
using namespace std;

void queen(int n,int qs,bool arr[],string ans) {
    if(qs == n) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<4;i++) {
        if(arr[i] == false) {
            arr[i] = true;
            queen(n,qs+1,arr,ans+"Q"+to_string(qs)+"B"+to_string(i));
            arr[i] = false; //backtrack
        }
    }
}
int main()
{
    bool arr[4];
    queen(2,0,arr,"");
    return 0;
}
//Hw. string given , multiple charcter,remove duplicates aaaaccccefff   ace