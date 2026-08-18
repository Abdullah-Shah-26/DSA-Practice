class Solution {
public:
  ListNode *merge(ListNode *head1, ListNode *head2) {

    ListNode *head = new ListNode(0);
    ListNode *tail = head;

    while (head1 && head2) {
      if (head1->val <= head2->val) {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;
        tail->next = NULL;
      } else {
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
        tail->next = NULL;
      }
    }

    if (head1)
      tail->next = head1;
    else
      tail->next = head2;

    return head->next;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return NULL;

    int k = lists.size();

    ListNode *head = lists[0];

    for (int i = 1; i < k; i++) {
      head = merge(head, lists[i]);
    }
    return head;
  }
};

class Solution {
public:
  ListNode *merge(ListNode *head1, ListNode *head2) {

    ListNode *head = new ListNode(0);
    ListNode *tail = head;

    while (head1 && head2) {
      if (head1->val <= head2->val) {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;
        tail->next = NULL;
      } else {
        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
        tail->next = NULL;
      }
    }

    if (head1)
      tail->next = head1;
    else
      tail->next = head2;

    return head->next;
  }
  void mergesort(vector<ListNode *> &arr, int start, int end) {
    if (start >= end)
      return;

    int mid = start + (end - start) / 2;

    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);

    arr[start] = merge(arr[start], arr[mid + 1]);
  }

  ListNode *mergeKLists(vector<ListNode *> &arr) {
    if (arr.empty())
      return NULL;

    int k = arr.size();

    mergesort(arr, 0, k - 1);
    return arr[0];
  }
};

class Solution {

public:
  class Compare {
  public:
    bool operator()(Node *a, Node *b) { return a->data > b->data; }
  };
  Node *mergeKLists(vector<Node *> &arr) {
    int k = arr.size();

    priority_queue<Node *, vector<Node *>, Compare> p(arr.begin(), arr.end());

    Node *root = new Node(0);
    Node *tail = root;

    Node *temp;

    while (!p.empty()) {
      temp = p.top();
      p.pop();
      tail->next = temp;
      tail = tail->next;

      if (temp->next)
        p.push(temp->next);
    }
    return root->next;
  }
};