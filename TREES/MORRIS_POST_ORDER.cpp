#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){

        left = right = NULL;
        data = val;
    }
};

// L R N
vector<int>postOrder(Node* root){
    //we will traverse the tree in order N - R - L
    vector<int>ans;

    //we will traverse tree until our root becomes NULL that shows that whole tree is treaversed
    while(root)
    {

        // if right doesnt exist then go left and push ans in ans vector
        if(root -> right )
        {
            ans.push_back(root->data);
            root = root -> left;

        }
        // if right of root exist
        // create a link of the left most node to root node so that we can come back to root node 
        Node *curr = root ->right;

        while(curr->left && curr ->left != root)
        {
            curr = curr -> left;

            // now we have 2 cases 
            //1.  we have not traversed the right part then curr->left will be NULL
            if(curr -> left == NULL)
        {
            // we are visiting that node first time push in ans and create link move to right 
            ans.push_back(root ->data);
            curr -> left = root;
            root = root ->right; 
        }
        // 2. right part is traversed- then break the link and go to left part 
        else{
            curr->left = NULL;
            root = root->left;
        }
        }
    }
    // we will reverse the ans array to get post order traversal 
    reverse(ans.begin(), ans.end());
    return ans;
}
