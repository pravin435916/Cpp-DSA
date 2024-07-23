#include <iostream>
#include<string>
using namespace std;
bool isPal(string s,int start, int end) {
    while(start <= end) {
        if(s[start] == s[end]) {
            start++;
            end--;
        }else return false;
    }
    return true;
   }
int main() {
    string s = "sks";
    cout<<isPal(s,0,s.length()-1);
}


