Node* deleteNode(Node* head, int k) {
    // Edge case 1: empty list
    if (head == NULL) return head;

    // Edge case 2: delete head
    if (head->data == k) {
        Node* temp = head;
        head = head->next;
        delete temp;   // ? use delete
        return head;
    }

    // Case 3: delete node in between / end
    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        
        if (temp->data == k) {
            prev->next = temp->next;
            delete temp;   // ? not free
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}