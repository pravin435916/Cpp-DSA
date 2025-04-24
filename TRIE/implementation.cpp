#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Trie Node
class TrieNode
{
public:
    TrieNode *children[26]; // 26 lowercase letters
    bool isTerminal;       // true if the node represents the end of a word
    char data; // character stored in the node

    TrieNode(char ch)
    {
        data = ch; // initialize the character
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};
// Trie Class
class Trie
{
private:
    TrieNode *root; // root of the trie
public:
     Trie(){
        root = new TrieNode('\0'); // initialize the root node with null character
     }

    // Function to insert a word into the trie
    
    void insertRecursive(TrieNode* node,string word) {
        if(word.length() == 0) {
            node->isTerminal = true; // mark the end of the word as true
            return;
        }
        int charIndex = word[0] -'A'; // get the current character
        TrieNode* child = node->children[charIndex]; // get the child node
        if(child == nullptr) { // if the child node is null, create a new node
            child = new TrieNode(word[0]); // create a new node with the current character
            node->children[charIndex] = child; // set the child node to the new node
        }
        insertRecursive(child,word.substr(1)); // recursively insert the next character
    }
    void insert(string word) {
        insertRecursive(root,word); // start inserting from the root node
    }


    // Function to search for a word in the trie
    bool searchRecursive(TrieNode* node,string word) {
        if(word.length() == 0) {
            return node->isTerminal; // if the end of the word is reached, return true if it is terminal
        }
        int charIndex = word[0] -'A'; // get the current character
        TrieNode* child = node->children[charIndex]; // get the child node
        if(child == nullptr) {
            return false; // if the child node is null, return false
        }
        return searchRecursive(child,word.substr(1)); // recursively search for the next character
    }
    bool search(string word) {
        return searchRecursive(root,word); // start searching from the root node
    }
    bool searchWordStartWith(TrieNode* node,string word) {
        if(word.length() == 0) {
            return true; // if the end of the prefix is reached, return true
        }
        int charIndex = word[0] -'A'; // get the current character
        TrieNode* child = node->children[charIndex]; // get the child node
        if(child == nullptr) {
            return false; // if the child node is null, return false
        }
        return searchWordStartWith(child,word.substr(1)); // recursively search for the next character
    }

    bool startsWith(string prefix) {
        return searchWordStartWith(root,prefix); // start searching from the root node
    }
    // Function to delete a word from the trie
    void deleteRecursive(TrieNode* node,string word) {
        if(word.length() == 0) {
            node->isTerminal = false; // mark the end of the word as false
            return;
        }
        int charIndex = word[0] -'A'; // get the current character
        TrieNode* child = node->children[charIndex]; // get the child node
        if(child == nullptr) {
            return; // if the child node is null, return
        }
        deleteRecursive(child,word.substr(1)); // recursively delete the next character

        // if the child node is not terminal and has no children, delete it
        if(!child->isTerminal) {
            bool canDeleteChild = true;
            for(int i=0;i<26;i++) {
                if(child->children[i] != nullptr) {
                    canDeleteChild = false; // if the child has any children, do not delete it
                    break;
                }
            }
            if(canDeleteChild) {
                delete child; // delete the child node
                node->children[charIndex] = nullptr; // set the child node to null
            }
        }
    }
    void deleteWord(string word) {
        deleteRecursive(root,word); // start deleting from the root node
    }
      

};

int main() {
    Trie trie; // create a new trie
    trie.insert("HELLO"); // insert a word into the trie
    cout << trie.search("HELLO") << endl; // search for the word in the trie
    cout << trie.startsWith("HE") << endl; // check if the prefix exists in the trie
    trie.deleteWord("HELLO"); // delete the word from the trie
    cout << trie.search("HELLO") << endl; // search for the word in the trie after deletion

    return 0;
}

// for insert just charcter by character add the node in the trie
// for search check if the node is null or not
// for checking prefix check if word getting and end of the word or not
// for delete mark the end of the word is not terminal then after searching it will not found and then release the memory of the node


// Time Complexity: O(N) for insert, search, delete and startsWith where N is the length of the word
// Space Complexity: O(N) for insert, search, delete and startsWith where N is the length of the word
// space is taken by the trie nodes in the trie


// ok done with implementation of trie data structure
// trie is a tree data structure used to store a dynamic set of strings where the keys are usually strings
// it is used for searching and storing strings in a efficient way
// it is also used for auto-completion and spell checking in search engines and text editors
// it is also used in dictionary and prefix tree for searching words in a dictionary
// it is also used in longest common prefix problem and longest common substring problem
// it is also used in longest common subsequence problem and longest palindromic substring problem
// it is also used in longest palindromic subsequence problem and longest increasing subsequence problem
// it is also used in longest decreasing subsequence problem and longest common subsequence problem
