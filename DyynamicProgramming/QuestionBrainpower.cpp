class Solution {
    public:
        vector<long long> dp;
        long long helper(vector<vector<int>>& questions,int i) {
            if(i >= questions.size()) return 0;
            if(dp[i] != -1) return dp[i];
            // solve 
            long long points = questions[i][0]; // imp have to take this even if below condition not met
            if(i+questions[i][1]+1 < questions.size()) {
                points += helper(questions,1+i+questions[i][1]);
            }
            //skip
            long long skip = helper(questions,i+1);
            return dp[i] = max(points,skip);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            dp.assign(questions.size()+1,-1);
            return helper(questions,0);
        }
    };


//     Input: questions = [[3,2],[4,3],[4,4],[2,5]]
// Output: 5
// Explanation: The maximum points can be earned by solving questions 0 and 3.
// - Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
// - Unable to solve questions 1 and 2
// - Solve question 3: Earn 2 points
// Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.