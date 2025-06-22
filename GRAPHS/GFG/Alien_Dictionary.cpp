#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        // Step 1: Find all unique characters
        unordered_set<char> uniqueChars;
        for (const string &word : words)
        {
            for (char c : word)
            {
                uniqueChars.insert(c);
            }
        }

        // Step 2: Build the graph (adjacency list)
        vector<int> adj[26]; // For 'a' to 'z'
        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            bool foundDifference = false;

            for (int j = 0; j < len; j++)
            {
                if (word1[j] != word2[j])
                {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    foundDifference = true;
                    break;
                }
            }

            // Edge case: word2 is a prefix of word1, invalid input
            if (!foundDifference && word1.size() > word2.size())
            {
                return ""; // No valid order
            }
        }

        // Step 3: Perform topological sort
        vector<int> inDegree(26, 0);
        for (int i = 0; i < 26; i++)
        {
            for (int neighbor : adj[i])
            {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        for (char c : uniqueChars)
        {
            if (inDegree[c - 'a'] == 0)
            {
                q.push(c - 'a');
            }
        }

        string result;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result += char(node + 'a');

            for (int neighbor : adj[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Validate result
        if (result.size() < uniqueChars.size())
        {
            return ""; // Cycle detected, no valid order
        }

        return result; // Valid order of characters
    }
};