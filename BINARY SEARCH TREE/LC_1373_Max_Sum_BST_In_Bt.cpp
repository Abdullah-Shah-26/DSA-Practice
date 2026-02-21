class Box{
    public:
    bool BST;
    int sum;
    int min;
    int max;

    // structure of a null node
    Box(){
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
 };
class Solution {
public:
    Box* find(TreeNode* root, int &Totalsum)
    {   // if root doesn't exist
        if(!root)
        {
            return new Box();    
        }
        // if root exist 
        else{ // left and right se info (box) aayegi
        Box* lefthead = find(root->left , Totalsum);
        Box* righthead = find(root->right, Totalsum);

        // BST hay
            if(lefthead->BST && righthead->BST && lefthead->max < root->val && righthead->min > root->val)
        {   // create a new box and update values and find sum
            Box* head = new Box();
            head->sum = root->val + lefthead->sum + righthead->sum;
            // we will handle the case where only one side of root exist
            head->min = min(root->val,lefthead->min);
            head->max = max(root->val,righthead->max);
            // total sum will be updated only if curr sum is max
            Totalsum = max(head->sum,Totalsum);
            
            return head;
        }
        // BST nai hay
        else{ // no need to update anything except BST property
            lefthead->BST = 0;// righthead->BST = 0
            return lefthead;
        } 

        }
    }


    int maxSumBST(TreeNode* root) {
        int Totalsum = 0; // max total sum of BST in  a BT
        find(root,Totalsum);
        return Totalsum;
    }
};