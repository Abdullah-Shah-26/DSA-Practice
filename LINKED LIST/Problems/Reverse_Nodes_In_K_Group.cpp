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
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* temp = head;
            int cnt = 0;
            //! TO CHECK IF K GROUP EXIST
            while(cnt<k){
                if(temp == NULL){ // means k nodes doesnt exist
                    return head;
                }
                temp = temp->next;
                cnt++;
            }
            //! RECURSIVELY CALL FOR REST OF LL
                ListNode* prevNode = reverseKGroup(temp,k);
    
                //! REVERSE CURRENT GROUP
                    temp = head; cnt = 0;
                    while(cnt < k){
                        ListNode* next = temp->next;
                        temp->next = prevNode;
    
                        prevNode = temp;
                        temp = next;
                        cnt++;
                        
    
                    }
                    return prevNode; //new head of LL
        }
    };