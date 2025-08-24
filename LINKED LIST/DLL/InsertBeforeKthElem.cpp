Node* insertBeforeKthElement(Node* head, int  k ,int val)
{
    if(k == 1)
    {
        return insertbeforehead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k)
        break;

        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* newNode = new Node(val);
    back->next = newNode;
    temp->prev = back;
    newNode->next = temp;
    newNode->prev = back;
    return head;
}