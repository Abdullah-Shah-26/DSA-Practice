#include<bits/stdc++.h>
using namespace std;

void insert_before_node(Node* node, int val)
{
    Node* prev = node->back;
    Node* newNode = new Node(val);
    newNode->next = node;
    newNode->back = prev;
    prev->next = newNode;
    node->prev=newNode;


}