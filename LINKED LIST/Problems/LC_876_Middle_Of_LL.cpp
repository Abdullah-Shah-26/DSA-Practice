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

///! BRUTE FORCE APPROACH 
class Solution {
    public:
        ListNode* middleNode(ListNode* head) {        
            listNode* temp = head;
            int cnt = 0;
            while(temp != NULL){
                temp = temp->next;
                cnt++;
            }  
            int mid = (cnt/2) + 1 ;
            temp = head;
            while(temp != NULL){
                mid--;
            if(mid == 0)
            break;

            temp = temp->next;
            }
            return temp;
        }
    };
    
    class Solution {   //!SLOW AND FAST POINTER APPROACH
        public:
            ListNode* middleNode(ListNode* head) {     // TC = o(n) cause of loop  SC = O(1) cause of 2 ptr
                ListNode* slow = head;
                ListNode* fast = head;
        
                while(fast != NULL && fast->next != NULL){  // FOR EVEN AND ODD LL
                slow = slow->next;             //update by single node 
                fast = fast->next->next;       //update by 2 nodes
                }
                return slow;
            }
        };