class DSU {
    public:
        unordered_map<string, string> parent;
    
        string find(string x) {
            if (parent.find(x) == parent.end())
                parent[x] = x;
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(string x, string y) {
            string px = find(x);
            string py = find(y);
            if (px != py)
                parent[py] = px;
        }
    };
    class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            DSU dsu;
            unordered_map<string, string> emailToName;
    
            // Step 1: Union all emails in the same account
            for (auto& account : accounts) {
                string name = account[0];
                for (int i = 1; i < account.size(); i++) {
                    emailToName[account[i]] = name;
                    dsu.unite(account[1],account[i]); // Union all with the first email
                }
            }
    
            // Step 2: Group emails by their root parent
            unordered_map<string, set<string>> groups;
            for (auto& entry : emailToName) {
                string email = entry.first; 
                string root = dsu.find(email);
                groups[root].insert(email);
            }
    
            // step 3 . merged
            vector<vector<string>> result;
    
            for (const auto& group : groups) {
                const string& root = group.first;
                const set<string>& emails = group.second;
    
                vector<string> merged;
                merged.push_back(emailToName[root]); // Add the name first
    
                for (const string& email : emails) {
                    merged.push_back(email); // Add sorted unique emails
                }
    
                result.push_back(merged); // Add this account to the result
            }
            return result;
        }
    };
    //input 
    // vector<vector<string>> accounts = {
    //     {"John", "johnsmith@mail.com", "john00@mail.com"},
    //     {"John", "johnnybravo@mail.com"},
    //     {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    //     {"Mary", "mary@mail.com"}
    // };
    //output
    // {
    //     "johnsmith@mail.com": {"johnsmith@mail.com", "john00@mail.com", "john_newyork@mail.com"},
    //     "johnnybravo@mail.com": {"johnnybravo@mail.com"},
    //     "mary@mail.com": {"mary@mail.com"}
    //   }
      
        