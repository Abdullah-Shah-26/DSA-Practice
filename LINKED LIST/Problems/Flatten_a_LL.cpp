// SC = O(1)  TC = O(n^2 m )
// problem similar to merge 2 sorted LL
class Solution {
    public:
    // merge funciton
    Node* merge(Node* head1, Node* head2)
    {
        // create a dummy node to avoid writing multiple cond'n like head/tail can be null
        Node* head = new Node(0);
        Node* tail = head;;
        
        while(head1 && head2)
        {
            if(head1->data <= head2->data)
            { // think bottom like next ptr
                tail->bottom = head1;  // tail ka next will pt to smaller head
                head1 = head1->bottom; // update that head
                tail = tail->bottom; // update tail 
               tail->bottom = NULL;  
            }
             else{
                 // head1 > head2
                 tail->bottom = head2;
                 head2 = head2->bottom;
                 tail = tail->bottom;
                 tail->bottom = NULL; 
             }   
            }
            // if any one of LL is exhausted connect left out list directly to merged list
            if(head1)
            tail->bottom = head1;
            else 
            tail->bottom = head2;
            
            
            return head->bottom; // since we started from dummy node return its next(ie head of merged list)
    }
    
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          
          // we will connect 2 lists of head1 and head2 and store head3 to avoid losing next LL address
          // until new head of sorted merged LL (root) ka next becomes NULL repeat the process 
          Node* head1;
          Node* head2;
          Node* head3;
          
          while(root->next)
          {
              head1 = root;
              head2 = root->next;
              head3 = root->next->next;
              
              
              head1->next = NULL;
              head2->next = NULL;
              
              root = merge(head1, head2);
              
              
              root->next = head3;
          }
          return root; //returns head of final sorted merged LL
      }
  };