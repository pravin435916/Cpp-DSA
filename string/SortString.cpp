#include<bits/stdc++.h>
using namespace std;
string sort(string s);
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}
string sort(string s){
    vector<int> alpha(26,0);
    for(int i=0;i<s.length();i++) {
        int idx = s[i]-'a';
        alpha[idx]++;
    }
    string str ="";
    for(int i=0;i<26;i++) {
        char ch = 'a'+i;
        while(alpha[i]) {
            str+=ch;
            alpha[i]--;
        }
    }
    return str;
}