
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        int pos = 0;
        while(cur && cur->next) {
            if(prev && cur->next) { //start from 0 1st index till n-1
                if((cur->val < prev->val && cur->val < cur->next->val) || //minima
                  (cur->val > prev->val && cur->val > cur->next->val)){  //maxima
                    ans.push_back(pos); //if yes then store position
                  }
            }
            prev = cur; //store cur in prev
            cur = cur->next; //move cur
            pos++; //position ++
        }
        if(ans.size() < 2) return {-1,-1}; //if size less than 3 then not possible
        int mini = INT_MAX;
        for(int i=1;i<ans.size();i++) {
            mini = min(mini,ans[i]-ans[i-1]);  //differnce minimum between positions
        }
        int maxi = ans.back() - ans.front();  //last - first ofc maximum
        return {mini,maxi};
    }
};