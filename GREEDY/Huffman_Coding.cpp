#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  class Node {
  public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f) {
      ch = c;
      freq = f;
      left = NULL;
      right = NULL;
    }
  };

  class Compare {
  public:
    bool operator()(Node *a, Node *b) {
      return a->freq > b->freq; // Min Heap
    }
  };

  void dfs(Node *root, string code, unordered_map<char, string> &mp) {

    if (root == NULL)
      return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
      mp[root->ch] = code;
      return;
    }

    dfs(root->left, code + "0", mp);
    dfs(root->right, code + "1", mp);
  }

  vector<string> huffmanCodes(string S, vector<int> f, int N) {

    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Create one node for every character
    for (int i = 0; i < N; i++) {
      pq.push(new Node(S[i], f[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

      Node *first = pq.top();
      pq.pop();

      Node *second = pq.top();
      pq.pop();

      Node *parent = new Node('$', first->freq + second->freq);

      parent->left = first;
      parent->right = second;

      pq.push(parent);
    }

    Node *root = pq.top();

    unordered_map<char, string> mp;
    dfs(root, "", mp);

    vector<string> ans;

    // Return codes in the order of characters in S
    for (char c : S) {
      ans.push_back(mp[c]);
    }

    return ans;
  }
};