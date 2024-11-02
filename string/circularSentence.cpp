class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        // Approach 1 : using word split and store in vector 
         // Approach 2 : Direct Check in senetence
         for (int i = 0; i < n; i++) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) {
                return false;
            }
            if(sentence[0] != sentence[n-1]) return false;
         }
         return true;
        // int word = 0;
        // vector<string> v;
        // string ch = "";
        // for (int i = 0; i < n; i++) {
        //     if(sentence[i] == ' ') {
        //         if(ch != "") {
        //            v.push_back(ch);
        //            ch = "";
        //         }
        //     } else {
        //         ch += sentence[i];
        //     }
        // }
        
        // if(!ch.empty()) {
        //     v.push_back(ch);
        // }
        //   // Check if there's at least one word
        // if (v.size() < 2) {
        //     return v.size() == 1 && v[0].front() == v[0].back();
        // }
        // for (int i = 0; i < v.size(); i++) {
        //     string currentWord = v[i];
        //     string nextWord = v[(i + 1) % v.size()]; // used % for last and first word
        //      if (currentWord.back() != nextWord.front()) {
        //         return false;
        //     }
        // }
        // return true;
    }
};