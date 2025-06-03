// 1298. Maximum Candies You Can Get from Boxes
class Solution {
public:
    vector<int> status;
    vector<int> candies;
    vector<vector<int>> keys;
    vector<vector<int>> containedBoxes;
    vector<bool> visited;
    unordered_set<int> foundBoxes;
    int dfs(int box) {
        if(visited[box]) return 0;
        if(status[box] == 0) { // if the box is locked and we don't have the key, we can't open it
            foundBoxes.insert(box);
            return 0;
        }
        visited[box] = true;
        int collected = candies[box];
        for(int insideBox : containedBoxes[box]) { // dfs on contained boxes
            collected += dfs(insideBox);
        }
        for(int keyBox : keys[box]) { // check for keys if it can be open another boxes
            status[keyBox] = 1; // mark the keyBox as unlocked 
            if(foundBoxes.count(keyBox)) {  // if the box is already found, we can collect candies from it
                collected += dfs(keyBox);
            }
        }
        return collected;
    }
    int maxCandies(vector<int>& _status, vector<int>& _candies, vector<vector<int>>& _keys, vector<vector<int>>& _containedBoxes, vector<int>& initialBoxes) {
        status = _status;
        candies = _candies;
        keys = _keys;
        containedBoxes = _containedBoxes;

        int n = candies.size();
        visited.resize(n, false);
        int candy = 0;
        for(int x : initialBoxes) { // start dfs from initial boxes
            if(visited[x]) continue; // skip if already visited
            candy += dfs(x);
        }
        return candy;
    }
};