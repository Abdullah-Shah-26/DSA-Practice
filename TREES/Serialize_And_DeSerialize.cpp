#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)
class Codec {
  public:

  // Encodes a tree to a single string - Level Order Traversal
  string serialize(TreeNode* root) {
    if(!root) return "";

    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
      TreeNode* cur = q.front();
      q.pop();

      if(cur == NULL) s.append("#,");
      else s.append(to_string(cur->val) + ',');

      if(cur != NULL){
        q.push(cur->left);
        q.push(cur->right);
      }
    }

    cout << s << endl;
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;

    stringstream ss(data);
    string str;
    getline(ss, str, ',');

    TreeNode* root = new TreeNode(stoi(str));
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
      TreeNode* node = q.front();
      q.pop();

      getline(ss, str, ','); // (Stream it reads from, String its extracted into, delimiter - stop reading when this char appears)
      if(str == "#"){
        node->left = NULL;
      }
      else{
        node->left = new TreeNode(stoi(str));;
        q.push(node->left);
      }

      getline(ss, str, ',');
      if(str == "#"){
        node->right = NULL;
      }
      else{
        node->right = new TreeNode(stoi(str));
        q.push(node->right);
      }
    }

    return root;
  }
};