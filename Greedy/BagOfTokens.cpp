class Solution {
    public:
        int bagOfTokensScore(vector<int>& tokens, int power) {
            int n = tokens.size();
            if (n == 1) {
                if (tokens[0] > power)
                    return 0;
            }
            int i = 0;
            int j = n - 1;
            int score = 0;
            sort(tokens.begin(), tokens.end());
            int maxScore = 0;
            while (i <= j) {
                if (tokens[i] <= power) { // wanty to losse power then will choose minimum
                    power -= tokens[i];
                    score++;
                    i++;
                    maxScore = max(maxScore,score);
                }
                else if (score > 0 ) {  //ofc if i want to add then ill add maximum token to power
                    power += tokens[j];
                    score--;
                    j--;
                }else return maxScore;
            }
            return maxScore;
        }
    };