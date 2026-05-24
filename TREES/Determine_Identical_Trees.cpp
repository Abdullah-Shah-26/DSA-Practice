class Solution {  // TC = O(n) - we are traversing BT
    // SC = o(n) - rec call stack
public:
// Function to check if two trees are identical.
bool isIdentical(Node *r1, Node *r2) {
// Your Code here

// base cases 
if(r1 == NULL && r2 == NULL)
return 1;

if((!r1 && r2) || (r1 && !r2)) // if one exists but other not return false
return 0;


//// Check if the current nodes match and their left & right subtrees match
return ((r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));

}
};