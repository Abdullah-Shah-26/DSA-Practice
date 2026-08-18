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

class List {
public:
  Node *head;
  Node *tail;

  List() { head = tail = NULL; }

  void push_front(int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
      head = tail = newNode;
      return;
    } else {

      (*newNode).next = head;
      head = newNode;
    }
  }

  void printLL() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  List ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  ll.printLL();
}