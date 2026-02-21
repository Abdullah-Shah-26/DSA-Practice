Node* deleteNode(Node* head, int k) {
    // Edge case 1: empty list
    if (head == NULL) return head;

    // Edge case 2: delete head
    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;   // ? use delete
        return head;
    }

    // Case 3: delete node in between / end
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;

    while (temp) {
        
        if (cnt == k) {
            prev->next = temp->next;
            delete temp;   // ? not free
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}