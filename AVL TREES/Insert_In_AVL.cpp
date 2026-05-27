#include <iostream>
using namespace std;

// defining a node
class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    // structure of a single node
    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

//! funciton to get height
int getheight(Node *root)
{

    if (!root) // if its null height is 0
        return 0;

    return root->height;
}
//! right rotation - LL

Node *rightrotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // update the height of root and child
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // return address
    return child;
}
//! left rotation - RR
Node *leftrotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // update height of root & child
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    // return address
    return child;
}

//! funciton to check balance --- |-1 =< left ht - right ht <= 1|
int getbalance(Node *root)
{
    return getheight(root->left) - getheight(root->right);
}

//! function to insert in AVL tree
Node *insert(Node *root, int key)
{
    // root doesnt exist
    if (!root)
        return new Node(key);

    // exists

    if (key < root->data) // left side attach karo
        root->left = insert(root->left, key);

    else if (key > root->data) // right side attach karo
        root->right = insert(root->right, key);

    else // equal hay - dont insert -  // duplicates aren't allowed
        return root;

    // return aate time update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // balance check
    int balance = getbalance(root);

    //! Unbalanced cases

    // 1 Left Left case
    if (balance > 1 && key < root->left->data)
        return rightrotation(root); // right rotation top vale ka

    // 2 Right Right case
    else if (balance < -1 && root->right->data < key)
        return leftrotation(root); // top

    // 3 Left Right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftrotation(root->left); // middle wale ka
        return rightrotation(root);            // top ka
    }
    // 4 Right Left case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightrotation(root->right); // middle wale ka
        return leftrotation(root);                // top wale ka
    }
    //? Not unbalanced
    else
        return root;
}
// printing AVL TREE
void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{

    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 100);
    root = insert(root, 5);
    root = insert(root, 95);

    cout << "Preorder : " << endl;
    preorder(root);

    cout << endl;

    cout << "Inorder : " << endl;
    inorder(root);
}
