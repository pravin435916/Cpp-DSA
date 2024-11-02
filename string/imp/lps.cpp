#include <iostream>
#include <string>
using namespace std;
    int lps(string str) {
        int s=0,p=1,pos=1,ct=0;
        int n = str.length();
        while(s<n && p < n) {
            if(str[p] == str[s]) {
                p++;
                s++;
                ct++;
            }else{
                p=0;
                pos++;
                s = pos;
                ct=0;
            }
        }
        return ct;
    }
int main() {
    string s1 = "abcdeabcd";
    cout<<lps(s1);
}