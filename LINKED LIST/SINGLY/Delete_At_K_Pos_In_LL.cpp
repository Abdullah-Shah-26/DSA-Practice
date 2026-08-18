#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

Node *deleteNode(Node *head, int k) {

  if (head == NULL)
    return head;

  if (k == 0) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  Node *temp = head;
  Node *prev = NULL;
  int cnt = 0;

  while (temp) {

    if (cnt == k) {
      prev->next = temp->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
    cnt++;
  }
  return head;
}