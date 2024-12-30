#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
// Winner of an election
// Difficulty: EasyAccuracy: 53.75%Submissions: 93K+Points: 2
// Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.
// Function to return the name of candidate that received maximum votes.
vector<string> winner(string arr[], int n)
{
    unordered_map<string, int> voteCount;

    // Count the votes for each candidate
    for (int i = 0; i < n; ++i)
    {
        voteCount[arr[i]]++;
    }

    string winner;
    int maxVotes = 0;
    for (const auto &entry : voteCount)
    {
        const string &name = entry.first;
        int votes = entry.second;

        // Update the winner based on votes and lexicographical order
        if (votes > maxVotes || (votes == maxVotes && name < winner))
        {
            maxVotes = votes;
            winner = name;
        }
    }
    vector<string> ans;
    ans.push_back(winner);
    ans.push_back(to_string(maxVotes));
    return ans;
}