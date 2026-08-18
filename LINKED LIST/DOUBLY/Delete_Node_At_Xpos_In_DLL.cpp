#include <bits/stdc++.h>
using namespace std;

Node *deleteathead(Node *head) {
  Node *back = head;
  head = head->next;
  head->prev = NULL;
  back->next = NULL;
  delete (back);
  return head;
}
Node *deleteattail(Node *head) {
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  Node *back = tail->prev;
  back->next = NULL;
  tail->prev = NULL;
  delete (tail);
  return head;
}

class Solution {
public:
  Node *deleteNode(Node *head, int x) {

    if (head == NULL)
      return head;

    Node *temp = head;
    int cnt = 0;

    while (temp) {
      cnt++;

      if (cnt == x)
        break;

      temp = temp->next;
    }
    
    Node *back = temp->prev;
    Node *front = temp->next;

    if (back == NULL) {
      return deleteathead(head);
    } else if (back == NULL && front == NULL) {
      delete (temp);
      return NULL;
    } else if (front == NULL) {
      return deleteattail(head);
    }

    else {
      back->next = temp->next;
      front->prev = temp->prev;
      temp->next = NULL;
      temp->prev = NULL;
      delete (temp);
      return head;
    }
  }
};
