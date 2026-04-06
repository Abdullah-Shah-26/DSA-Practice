// 138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:                // TC = O(n)    ///  SC 
        Node* copyRandomList(Node* head) {
            // BASE CASE 
            if( head == NULL){
                return NULL;
            }
            unordered_map<Node*,Node*>m; // to store old(as keys) and new nodes(values) 
    
            Node* newHead = new Node(head->val);
            Node* oldTemp = head->next;
            Node* newTemp =  newHead;
            m[head] = newHead;
    
             //Creating a simple copy Of LL first
    
             while(oldTemp != NULL){
                Node* copyNode = new Node(oldTemp->val); // copy node to create copies of nodes
                m[oldTemp] = copyNode;
    
                newTemp->next = copyNode;                // and pasting in new node 
                oldTemp = oldTemp->next;     //updating both old and new temp
                newTemp = newTemp->next;
             }
             oldTemp = head;
             newTemp = newHead;  // again iterating to create random connections
    
             while(oldTemp != NULL){
                newTemp->random = m[oldTemp->random]; //if old nodes have any random connections with other old nodes
                                                    //the map searches the val of new Node which is stored as value in map 
                                                    // corresponding to old node which is stores as key
                oldTemp = oldTemp->next;
                newTemp = newTemp->next;
    
             }
             return newHead;
    
        }
    };