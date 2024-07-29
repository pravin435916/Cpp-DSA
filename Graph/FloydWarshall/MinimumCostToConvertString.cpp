// Input: source = "abcd", 
//        target = "acbe",
//  original = ["a","b","c","c","e","d"], 
//  changed =  ["b","c","b","e","b","e"], 
//  cost =     [2,   5,  5,  1,  2, 20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
class Solution {
    private:
    const long long INF = LLONG_MAX;
     void FloydWarshall(vector<vector<long long>> &dist, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        // Initialize the distances based on the given edges
        for(int i = 0; i < n; i++) {
            int s = original[i] - 'a';
            int d = changed[i] - 'a';
            dist[s][d] = min(dist[s][d], (long long)cost[i]);
        }
        // Floyd-Warshall Algorithm
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26,vector<long long>(26,INF));
        for (int i = 0; i < 26; ++i) {
            adj[i][i] = 0;
        }
        FloydWarshall(adj,original,changed,cost);
        long long res = 0;
        for(int i=0;i<source.length();i++) {
            //if character same then no change
            if(source[i] == target[i]) continue;
            if(adj[source[i]-'a'][target[i]-'a'] == INF) return -1;  //no path
            res+=adj[source[i]-'a'][target[i]-'a'];  // -'a' to get index
            // like ex i want distance from 2 to 3 => adj[2][3]
        }
        return res;
    }
};