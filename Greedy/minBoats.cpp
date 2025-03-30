class Solution {
    // 881. Boats to Save People
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(),people.end()); 
            int minBoats = 0;
            int n = people.size();
            int i=0;
            int j= n-1;
            while(i<=j) {
                if(people[i] + people[j] <= limit) {
                    i++;
                }
                j--;
                minBoats++;
            }
            return minBoats;
        }
    };