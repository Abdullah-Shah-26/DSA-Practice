#include <bits/stdc++.h>
using namespace std;

// TC = O(N^2) worst case, O(NlogN) average | SC = O(H)

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int target) {
  // Base case: null node found, create new node here
  if (!root) {
    return new TreeNode(target);
  }

  // Insert left
  if (target < root->val) {
    root->left = insert(root->left, target);
  }
  // Insert right
  else {
    root->right = insert(root->right, target);
  }

  return root;
}

void inorder(TreeNode *root) {
  if (!root)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main() {
  int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
  TreeNode *root = NULL;

  for (int i = 0; i < 10; i++) {
    root = insert(root, arr[i]);
  }

  // Traverse
  inorder(root);
}