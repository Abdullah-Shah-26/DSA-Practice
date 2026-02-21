
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    if (!root) return res;

    stack<pair<TreeNode*, bool>> st;
    st.push({root, false});

    while (!st.empty()) {
        auto [node, visited] = st.top();
        st.pop();

        if (visited) {
            res.push_back(node->data);
        } else {
            st.push({node, true});
            if (node->right) st.push({node->right, false});
            if (node->left)  st.push({node->left, false});
        }
    }
    return res;
}
