class Solution {    //! BRUTE FORCE - TC = O(k^2 n ) SC = O(1)
    public: // concept similar to flatten a LL 
        ListNode* merge(ListNode* head1, ListNode* head2)
        {
            // create a dummy node to avoid using wrting multiple cond'n like head/tail is empty
            ListNode* head = new ListNode(0);
            ListNode* tail = head;
    
            while(head1 && head2)
            {
                if(head1->val <= head2->val)
                {
                    tail->next = head1;
                    head1 = head1->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
                else {
                    tail->next = head2;
                    head2 = head2->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
            }
            // if one LL is exhausted connect the other LL to the merge sorted LL directly
            if(head1)
            tail->next = head1;
            else 
            tail->next = head2;
    
    
            return head->next; // since we are starting from dummy node the merged LL head start from next
        }
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty()) // edge case
            return NULL;
    
            int k = lists.size();
    
            ListNode* head = lists[0];
    
            for(int i = 1; i<k; i++)
            {
                head = merge(head, lists[i]); // pass 2 heads to merge fun it will merge & sort LL
            }
            return head;      
        }
    };
//! USING MERGE SORT  
//! TC = O(Nklogk)   SC = O(1)
class Solution {
    public: // concept similar to flatten a LL 
        ListNode* merge(ListNode* head1, ListNode* head2)
        {
            // create a dummy node to avoid using wrting multiple cond'n like head/tail is empty
            ListNode* head = new ListNode(0);
            ListNode* tail = head;
    
            while(head1 && head2)
            {
                if(head1->val <= head2->val)
                {
                    tail->next = head1;
                    head1 = head1->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
                else {
                    tail->next = head2;
                    head2 = head2->next;
                    tail = tail->next;
                    tail->next = NULL;
                }
            }
            // if one LL is exhausted connect the other LL to the merge sorted LL directly
            if(head1)
            tail->next = head1;
            else 
            tail->next = head2;
    
    
            return head->next; // since we are starting from dummy node the merged LL head start from next
        }
       void mergesort(vector<ListNode*> &arr, int start , int end)
        {
            if(start >= end)
            return;
    
            int mid = start + (end - start)/2;
    
            // recursively call merge sort for left & right half
            mergesort(arr, start,mid);
            mergesort(arr, mid +1, end);
    
            // call merge funciton and pass the address of 2 LL and store the address(head) of
            // merged LL in the previous call ka arr[start]
            arr[start] = merge(arr[start],arr[mid + 1]);
        }
        
        
        ListNode* mergeKLists(vector<ListNode*>& arr) {
            if(arr.empty()) // edge case
            return NULL;
    
            int k =arr.size();
            // little optimized approach
            mergesort(arr, 0, k-1);
            return arr[0];    
        }
    };

//! Method 3 
class Solution { // SC = O(nk) - heap
    // TC = O(nklogk) - taking these elemnts out of heap overall
      public:
      
      // custom comparator 
      class Compare
      {
          public:
          bool operator()(Node* a, Node* b)
          {
    // return a->data <= b->data; // kya a & b ka order sahi hay (sorting ascending order)
    // works ultha in heap
    // return a->data < b->data // for Max Heap
    
              return a->data > b->data; // for MIN Heap 
          }
      };
        Node* mergeKLists(vector<Node*>& arr) {
            int k = arr.size();
        // similar approach as Kth smallest in Matrix
        // Using customized min heap
        // we will push addresses of all first k nodes unme se hi first smallest hoga 
        
        priority_queue<Node*, vector<Node*>, Compare>p(arr.begin() , arr.end()); // TC = O(K)
    // create dummy node to avoid checking multiple conditions
        Node* root = new Node(0);
        Node* tail = root;
        
        Node* temp;
        
        while(!p.empty())
        {
            temp = p.top();
            p.pop();
            tail->next = temp;
            tail = tail ->next;
            
            if(temp->next)
            p.push(temp->next);
        }
        return root->next; // dummy node ke baad wali node = head of merged sorted LL
        }
    };