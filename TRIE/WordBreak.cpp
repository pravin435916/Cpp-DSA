class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
};

class Solution {
public:
  bool solve(string key, Trie& trie, unordered_map<string, bool>& memo) {
        if (key.empty()) return true;
        if (memo.find(key) != memo.end()) return memo[key];

        for (int i = 1; i <= key.length(); i++) {
            string firstPart = key.substr(0, i);
            string otherPart = key.substr(i);

            if (trie.search(firstPart) && solve(otherPart, trie, memo)) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
    bool wordBreak(string key, vector<string>& wordDict) {
        Trie trie;
        for(string word : wordDict) {
            trie.insert(word);
        }
        unordered_map<string, bool> memo;
        return solve(key, trie, memo);
    }
};