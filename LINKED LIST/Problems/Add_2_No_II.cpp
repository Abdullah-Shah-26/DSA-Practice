/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head, *next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
    return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Approach 1 - Reverse LL and add 
    l1 = reverseLL(l1);
    l2 = reverseLL(l2);
    int sum = 0, carry = 0;
    ListNode* ans = new ListNode();

    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        ans->val = sum%10;
        carry = sum/10;
        ListNode* newNode = new ListNode(carry);
        newNode->next = ans;
        ans = newNode;
        sum = carry;
    }     
    if(carry == 0) 
    {
        return ans->next;
    }
    else // Edge case where l1->val + l2->val > 9 and both lengths are same & carry != 0
    {
        return ans;
    }
    }
};9