// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
    // code here
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* back = head;
    for(int i = 1;i < n; i++)
    {
        Node* temp = new Node(arr[i]);
        back->next = temp;
        temp->prev = back;
        back =temp;
    }
    return head;
    }
};