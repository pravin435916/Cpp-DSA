class Solution {
    public:
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<string> res;
        int m, n;
    
        struct TrieNode {
            bool isTerminal;
            string word; // store the word at the end of the trie
            TrieNode* children[26];
        };
    
        TrieNode* getNode() { // function to create a new trie node
            TrieNode* newNode = new TrieNode();
            newNode->isTerminal = false;
            for (int i = 0; i < 26; i++) {
                newNode->children[i] = NULL;
            }
            return newNode;
        }
    
        void insert(TrieNode* root, string word) {
            TrieNode* current = root;
            for (char &ch : word) {
                int charIndex = ch - 'a';
                if (current->children[charIndex] == NULL) {
                    current->children[charIndex] = getNode();
                }
                current = current->children[charIndex];
            }
            current->isTerminal = true;
            current->word = word;
        }
    
        void findWordsInTrie(vector<vector<char>> &board, TrieNode* root, int i, int j) {
            char ch = board[i][j];
            if (ch == '$' || root->children[ch - 'a'] == NULL) return;
    
            root = root->children[ch - 'a']; // move to the next node in the trie
            if (root->isTerminal) {
                res.push_back(root->word);
                root->isTerminal = false;  // avoid duplicates
            }
    
            board[i][j] = '$'; // mark visited
            for (auto &dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    findWordsInTrie(board, root, ni, nj);
                }
            }
            board[i][j] = ch; // backtrack
        }
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            m = board.size();
            n = board[0].size();
            TrieNode* root = getNode();
    
            for (string &word : words) { // insert each word into the trie
                insert(root, word);
            }
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) { // check for each charcter in the board
                    // if the character is present in the trie then start searching for the word in the trie
                    findWordsInTrie(board, root, i, j);
                }
            }
            return res;
        }
    };
    