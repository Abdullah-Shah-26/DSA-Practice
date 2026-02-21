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
class Solution {  // classical Approach using 3 pointer
public:
    ListNode* reverseList(ListNode* head) { // TC = O(n) -> traversing LL once
                                            // SC = O(1) -> No extra space only using pointers
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
        next = curr->next;    //major step to preserve the address of whole LL
        curr->next = prev;    // to establish reverse connections
        prev = curr;          
        curr = next;
        }
        return prev;  //which will become the new head of reversed LL
    }
};