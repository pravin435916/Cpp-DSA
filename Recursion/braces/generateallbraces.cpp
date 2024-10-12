#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(string cur,int n) {
    if(cur.length() == 2*n) {    //in pairs mean 2*n
        cout<<cur<<endl;
        return;
    }
    cur += '(';
    solve(cur,n);
    
    cur.pop_back();
    
    cur+=')';
    solve(cur,n);
}
int main() {
    solve("",2);
    return 0;
}