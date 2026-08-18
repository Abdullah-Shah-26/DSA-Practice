Node *Insertbeforetail(Node *head, int val) {
  if (head->next == NULL) {

    return insertbeforehead(head, val);
  }
  Node *tail = head;
  while (tail->next) {
    tail = tail->next;
  }
  Node *back = tail->prev;
  Node *newNode = new Node(val);
  newNode->next = tail;
  tail->prev = newNode;
  back->next = newNode;
  newNode->prev = back;
  return head;
}