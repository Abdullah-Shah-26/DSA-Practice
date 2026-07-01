#include <bits/stdc++.h>
using namespace std;

#include <iostream>
int main()
{
  priority_queue<int> p; // Max heap
  p.push(10);
  p.push(20);
  p.push(11);
  p.push(18);
  p.push(15);
  cout << p.top() << " ";
  // Delete
  p.pop();
  cout << p.top() << " ";
  // Size
  cout << p.size() << endl;
  // print
  while (!p.empty())
  {
    cout << p.top() << " ";
    p.pop(); 
  }
}