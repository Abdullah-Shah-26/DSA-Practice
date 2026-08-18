#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    bool iscycle = false;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        iscycle = true;
        break;
      }
    }

    if (!iscycle) {
      return NULL;
    }
    slow = head;

    while (slow != fast) {
      slow = slow->next;

      fast = fast->next;
    }

    return slow;
  }
};