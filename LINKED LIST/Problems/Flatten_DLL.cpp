
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };

//TC = O(n)
class Solution {
    public:
        Node* flatten(Node* head) {
            if(head == NULL){
                return head;
            }
            Node* curr = head;
            while(curr != NULL){
                if(curr->child != NULL){ //means curr has child node
    
                    //! WE WILL FLATTEN THE CHILD NODES
                    Node* next = curr->next;     //pehle curr ka next store kara lenge to avoid losing orginal ptr
                    curr->next = flatten(curr->child); //recursive call attaches child list to curr ka next
                    curr->next->prev = curr; // establishing reverse connections
                    curr->child = NULL; //(flattened) so it removes child ptr
    
                    //! TO FIND TAIL OF THE FLATENNED CHILD LIST 
                    while(curr->next != NULL){ 
                        curr = curr->next;     
    
                    }
                    //! ATTACH TAIL WITH NEXT PTR
                    if(next != NULL){
                        curr->next = next;
                        next->prev = curr;
                    }
                }
                curr = curr->next;    // (else) curr doest have valid child node just update curr
            }                                 
            return head;
        }
    };