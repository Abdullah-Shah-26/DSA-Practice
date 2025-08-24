Node* insertbeforehead(Node* head, val)
{
    Node*  newhead = new Node(val)
    newhead->next = head;
    head->prev = newehead;
    head= newhead;
}