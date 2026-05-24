class Solution
{
public: // TC = O(n)   Sc = O(n)
    vector<int> findSpiral(Node *root)
    {
        // code here

        // we will use 2 stacks
        stack<Node *> s1; //! one for storing nodes for traversing from R - L
        stack<Node *> s2; //! 2nd  for storing nodes for traversing from L - R

        s1.push(root);

        vector<int> ans;

        while (!s1.empty() || !s2.empty())
        {
            // R - L
            if (!s1.empty())
            {
                // jab tak s1 khali na ho
                while (!s1.empty())
                {
                    Node *temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->data);
                    // jis order mein traverse karna hay usi order mein push karna

                    // if temp ke Right exists push in s2
                    if (temp->right != NULL)
                        s2.push(temp->right);

                    // if temp ka Left exists push in s2
                    if (temp->left)
                        s2.push(temp->left);
                }
            }
            else // s2 mein elements present hay
            {
                // jab tak s2 khali na ho
                while (!s2.empty())
                {
                    Node *temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->data);
                    // jis order mein traverse karna hay usi order mein push karna

                    // if temp ka Left exists push in s1
                    if (temp->left)
                        s1.push(temp->left);

                    // if temp ke Right exists push in s1
                    if (temp->right != NULL)
                        s1.push(temp->right);
                }
            }
        }
        return ans;
    }
};