#include <iostream>
#include <list>
using namespace std;
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node(int val) {
    data = val;
    next = prev = NULL;
  }
};

class DoublyList {
  Node *head;
  Node *tail;

public:
  DoublyList() { head = tail = NULL; }

  void print() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " <-> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void push_front(int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }
};
int main() {
  DoublyList dll;
  dll.push_front(1);
  dll.push_front(2);
  dll.push_front(3);
  dll.push_front(4);

  dll.print();
}