#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    listNode *temp = head;
    int cnt = 0;
    while (temp != NULL) {
      temp = temp->next;
      cnt++;
    }
    int mid = (cnt / 2) + 1;
    temp = head;
    while (temp != NULL) {
      mid--;
      if (mid == 0)
        break;

      temp = temp->next;
    }
    return temp;
  }
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};