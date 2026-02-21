#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> p; // min heap
    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout << p.top() << " \n";

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}