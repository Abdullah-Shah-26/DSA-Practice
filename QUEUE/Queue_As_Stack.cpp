#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  // tc of all ops O(1) except pop tc = O(n) amortized tc of pop = O(1)
  // sc = O(n)
public:
  stack<int> s1; // push operation ke liye
  stack<int> s2; // pop ke liye

  MyQueue() {}

  bool empty() { return s1.empty() && s2.empty(); }

  void push(int x) { s1.push(x); }

  int pop() {
    if (empty())
      return 0;

    if (!s2.empty()) {
      int element = s2.top();
      s2.pop();
      return element;
    }

    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    int element = s2.top();
    s2.pop();
    return element;
  }

  int peek() {
    if (empty())
      return 0;

    if (!s2.empty())
      return s2.top();

    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }

    return s2.top();
  }
};