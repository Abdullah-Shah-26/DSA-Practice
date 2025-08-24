/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
Node* deleteathead(Node* head)
{
        Node* back = head;
        head = head->next;
        head->prev = NULL;
        back->next = NULL;
        delete(back);
        return head;
}
Node* deleteattail(Node* head)
{
    Node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    Node* back = tail->prev;
    back->next =NULL;
    tail->prev =NULL;
    delete(tail);
    return head;
}

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
    if(head == NULL) return head;
    Node* temp = head;
    int cnt =0;
    while(temp)
    {
        cnt++;
        if(cnt == x)
        {
            break;
        }
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    
    if(back == NULL){
        // means its the first Node
    return deleteathead(head);
        
    }
    else if(back == NULL && front == NULL)
    {
        // Means its a single node
        delete(temp);
        return NULL;
    }
    else if(front == NULL)
    {
        // means its the last Node
    return deleteattail(head);
        
    }
    // k is somewhere in b.w
    else{
        back->next = temp->next;
        front->prev = temp->prev;
        temp->next = NULL;
        temp->prev =NULL;
        delete(temp);
        return head;
    }
    }
};

