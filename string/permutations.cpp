#include <iostream>
#include <string>
using namespace std;

void findPermutations(string str,string t) {
    if(str == ""){  //acb 
        cout<<t<<endl;
        return;
    }
    //bca,abc,acb
   for(int i=0;i<str.length();i++) {
    char ch = str[i]; //suppose  b
    string left = str.substr(0,i); //a
    string right = str.substr(i+1);//c
    string merge = left+right; // ac
    findPermutations(merge,t+ch); //acb
   }
}

int main() {
    string str ="abc";
    findPermutations(str,"");

    return 0;
}
