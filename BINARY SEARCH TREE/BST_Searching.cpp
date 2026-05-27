#include <bits/stdc++.h>
using namespace std;

// TC = O(H) | SC = O(H) (due to call stack)

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
  if (!root) {
    return new TreeNode(target);
  }

  if (target < root->val) {
    root->left = insert(root->left, target);
  } else {
    root->right = insert(root->right, target);
  }

  return root;
}

void inorder(TreeNode *root) {
  if (!root) {
    return;
  }

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

// Function to search element in BST
bool search(TreeNode *root, int target) {
  if (!root) {
    return 0;
  }

  if (root->val == target) {
    return 1;
  }

  // Search left subtree
  if (target < root->val) {
    return search(root->left, target);
  }
  // Search right subtree
  else {
    return search(root->right, target);
  }
}

int main() {
  int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
  TreeNode *root = NULL;

  for (int i = 0; i < 10; i++) {
    root = insert(root, arr[i]);
  }

  cout << endl;
  cout << search(root, 6);
}