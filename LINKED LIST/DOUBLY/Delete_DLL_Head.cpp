#include <bits/stdc++.h>
using namespace std;

Node *deleteHead(Node *head) {
  if (head == NULL || head->next == NULL)
    return NULL;

  Node *back = head;
  head = head->next;
  head->prev = NULL;
  back->next = NULL;
  
  delete (back);
  return head;
}
