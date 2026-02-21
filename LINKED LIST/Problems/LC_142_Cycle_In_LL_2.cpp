
    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
   class Solution {     // slow fast pointer Time & Space Complexity
    //Time Complexity: O(N) (Both pointers traverse the list once)
   //Space Complexity: O(1) (Only two pointers are used)
public:
ListNode *detectCycle(ListNode *head) {
ListNode* slow = head;
ListNode* fast = head;

bool iscycle = false;

while(fast != NULL && fast->next != NULL){
slow = slow->next;
fast = fast->next->next;

if(slow == fast){
   iscycle = true;
   break;
}
}

if(!iscycle){       // cycle doest exist so no star
return NULL;
}
slow = head;      ///! TO rempve cycle
//! ListNode* prev = NULL;

while(slow != fast){
slow = slow->next;
//! prev = fast;         //prev will store old address of fast ptr
fast = fast->next;

}
//! prev->next = NULL;     // this will break the cycle and make tail pt to NULL
return slow;    // now slow == fast which is starting node of cycle
}

};