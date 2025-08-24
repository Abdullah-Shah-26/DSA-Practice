// BULLSHIT PROBLEM BUT EASY JUST REMOVE LEADING ZEROS
Node* reverse(Node* head)
{
    if(head == NULL) return head;

    Node* curr = head , *prev = NULL, *next = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }
    return prev;
}
void insertattail(Node* &head, Node* &tail, int x)
{
    Node* newNode= new Node(x);
    if(head == NULL)
    {
        head = tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    
}
Node* add(Node* first, Node* second)
{
        int carry =0;
    Node* anshead = NULL, *anstail= NULL;
    while(first != NULL || second != NULL || carry!= 0)
    {
        int sum = 0;
        if(first != NULL)
        {
            sum += first->data;
            first = first->next;
        }
        if(second != NULL)
        {
            sum += second->data;
            second = second->next;
        }
        sum += carry;
        
        int dig = sum%10;
        insertattail(anshead, anstail,dig);
        carry = sum/ 10;
    }
    
     return anshead;  
}
Node* RemoveLeadingZeros(Node* head)
{
    while(head && head->data == 0)
    {
        head = head->next;
    }
    return head;
}

class Solution {
  public:
    Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node* ans = add(first, second);
    ans = reverse(ans);
    ans = RemoveLeadingZeros(ans);
    return ans;
    }
};