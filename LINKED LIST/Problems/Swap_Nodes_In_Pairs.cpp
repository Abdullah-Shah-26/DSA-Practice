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
class Solution { // TC = O(n)  SC = O(1)
    public:
        ListNode* swapPairs(ListNode* head) {
    
            //BASE CASE - If the list is empty or has only one node, return head as it is.
            if(head == NULL || head->next == NULL){
                return head;
    
            }
    
            ListNode* prev = NULL;//prev → keeps track of the last swapped node(used for linking) .              
            ListNode* first = head;
            ListNode* sec = head->next; 
    
            while(first != NULL && sec != NULL){
                ListNode* third = sec->next;//Save the next node(third) before swapping to avoid losing the list
                sec->next = first;
                first->next = third;
    
                if(prev != NULL){ //condn to identify valid prev 
                        prev->next = sec;
                }
                else //prev == NULL that means this is the first swap, update head
                head = sec;
    
                prev = first;
                first = third;
    
                if(third != NULL){
                    sec = third->next;
                    }
            else
            sec = NULL;
            }
            return head;
        }
    };