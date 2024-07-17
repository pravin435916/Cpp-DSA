class Solution {
  public:

    string printString(string s, char ch, int count) {
        int ct = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == ch) ct++;
            if(ct == count){
                return s.substr(i+1,s.length());
            }
        }
        return "";
    }
};