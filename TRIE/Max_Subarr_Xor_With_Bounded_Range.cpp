#include <bits/stdc++.h>
using namespace std;

// Xor Trie + Sliding window monotonic dq
class TrieNode {
public:
  TrieNode *child[2];
  int cnt = 0; // Each bit should now how many no's used me

  TrieNode() {
    child[0] = NULL;
    child[1] = NULL;
    cnt = 0;
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(int num) {
    TrieNode *cur = root;

    for (int i = 15; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (cur->child[bit] == NULL) {
        cur->child[bit] = new TrieNode();
      }

      cur = cur->child[bit];
      cur->cnt++;
    }
  }

  int getMaxXor(int num) {
    TrieNode *cur = root;
    int ans = 0;

    for (int i = 15; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (cur->child[!bit] != NULL && cur->child[!bit]->cnt > 0) {
        ans |= (1 << i);
        cur = cur->child[!bit];
      } else if (cur->child[bit] != NULL && cur->child[bit]->cnt > 0) {
        cur = cur->child[bit];
      }
    }

    return ans;
  }

  void remove(int num) {
    TrieNode *cur = root;

    for (int i = 15; i >= 0; i--) {
      int bit = (num >> i) & 1;
      cur = cur->child[bit];
      cur->cnt--;
    }
  }
};

class Solution {
public:
  int maxXor(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;

    Trie trie;
    deque<int> dqMin;
    deque<int> dqMax;
    vector<int> pref(n + 1, 0);

    // XOR(L,R) = pref[R + 1] ^ pref[L]
    pref[0] = 0;
    trie.insert(pref[0]); // Insert empty pref

    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] ^ nums[i - 1];

    int l = 0;
    for (int r = 0; r < n; r++) {

      while (!dqMax.empty() && nums[r] > dqMax.back())
        dqMax.pop_back();

      dqMax.push_back(nums[r]);

      while (!dqMin.empty() && nums[r] < dqMin.back())
        dqMin.pop_back();

      dqMin.push_back(nums[r]);

      // Shrink window if invalid
      while (!dqMax.empty() && !dqMin.empty() &&
             dqMax.front() - dqMin.front() > k && l <= r) {

        if (nums[l] == dqMax.front())
          dqMax.pop_front();

        if (nums[l] == dqMin.front())
          dqMin.pop_front();

        trie.remove(pref[l]);
        l++;
      }

      ans = max(ans, trie.getMaxXor(pref[r + 1]));
      trie.insert(pref[r + 1]);
    }

    return ans;
  }
};