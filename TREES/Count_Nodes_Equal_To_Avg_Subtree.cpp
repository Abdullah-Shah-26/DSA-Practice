#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Post order traversal
//* TC = O(N) || SC = O(H)

class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int &ans){
        if(!root) return {0,0};

        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        if(sum / cnt == root->val) ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};