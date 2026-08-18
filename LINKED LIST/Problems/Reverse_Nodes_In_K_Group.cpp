

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *temp = head;
    int cnt = 0;

    while (cnt < k) {
      if (temp == NULL) {
        return head;
      }
      temp = temp->next;
      cnt++;
    }

    ListNode *prevNode = reverseKGroup(temp, k);

    temp = head;
    cnt = 0;
    while (cnt < k) {
      ListNode *next = temp->next;
      temp->next = prevNode;

      prevNode = temp;
      temp = next;
      cnt++;
    }
    return prevNode;
  }
};