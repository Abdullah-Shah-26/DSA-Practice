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

class CircularLL {
  Node *head;
  Node *tail;

public:
  CircularLL() { head = tail = NULL; }

  void print() {
    if (head == NULL) {
      cout << " CLL is empty";
      return;
    }
    cout << head->data << " -> ";
    Node *temp = head->next;

    while (temp != head) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << temp->data;
  }

  void insertAtTail(int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
      head = tail = newNode;
      tail->next = head;
    } else {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }
};

int main() {
  CircularLL ll;

  ll.insertAtTail(1);
  ll.insertAtTail(2);
  ll.insertAtTail(3);

  ll.print();
}