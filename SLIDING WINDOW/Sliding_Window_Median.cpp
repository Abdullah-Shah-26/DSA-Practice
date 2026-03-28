//! CSES Version
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void rebalance(multiset<ll> &left, multiset<ll> &right)
{
  while(left.size() > right.size() + 1)
  {
    auto it = prev(left.end());
    right.insert(*it);
    left.erase(it);
  }

  while (left.size() < right.size())
  {
    auto it = right.begin();
    left.insert(*it);
    right.erase(it);
  }
}

void solve()
{
  ll n, k;
  cin >> n >> k;

  vector<int> nums(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> nums[i];

  multiset<ll> left, right;

  //! Handle First Window
  for (int i = 1; i <= k; i++)
  {
    ll x = nums[i];

    if (left.empty() || x <= *left.rbegin())
      left.insert(x);
    else
      right.insert(x);

    rebalance(left, right);
  }

  cout << *left.rbegin() << " ";

  //! Handle Remaining Windows
  for (int i = k + 1; i <= n; i++)
  {
    int next = nums[i];
    int prev = nums[i - k];

    if (left.empty() || next <= *left.rbegin())
      left.insert(next);
    else
      right.insert(next);

   //! Deletion
  auto it = left.find(prev);
  if(it != left.end()) left.erase(it);
  else{
    auto it2 = right.find(prev); 
    
    if(it2 != right.end())
      right.erase(it2);
  }

    rebalance(left, right);
    cout << *left.rbegin() << " ";
  }
  return;
}

int main()
{
  fastio();
  solve();
}

//! Leetcode Version ---------------------------------------------

class Solution {
public:
    //! 2x MultiSet
    //! TC = O(N Log K)
    //! SC = O(K)
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    // Why not heap ? cause we need arbitary deletion
    multiset<int> left; // LeftMaxHeap   
    multiset<int> right; // RightMinHeap
    int n = nums.size();

    vector<double> ans;

    for(int i = 0; i < n; i++){
      int x = nums[i];

      // Insert new guy
      if(left.empty() || (x <= *left.rbegin())){
        left.insert(x);
      } else {
        right.insert(x);
      }

      // Delete guy that isn't in window
      if(i >= k){
        int y = nums[i-k];

        if(left.find(y) != left.end()){
          left.erase(left.find(y));
        }
        else if(right.find(y) != right.end()){
          right.erase(right.find(y));
        }
      }

      //! Balance cond'n : 
      // (leftMaxHeap size - rightMinHeap size) <= 1 
      // leftMaxHeap >= rightMinHeap but not less
      while(left.size() > right.size() + 1){
        auto it = prev(left.end());
        right.insert(*it);
        left.erase(it);
      }
      while(left.size() < right.size()){
        auto it = right.begin();
        left.insert(*it);
        right.erase(it);
      }

      if(i >= k - 1){
         double median = 0.0;
        // Window Size Odd
        if(k & 1){
          median = *left.rbegin();
        }
        else{ // Even
          median = ((double)*left.rbegin() + *right.begin())/2.0;
        }
        ans.push_back(median);
      }
    }

    return ans;
    }
};

//! Approach 2 
//! 2x Heaps + Map
class Solution {
public:
    //! TC = O(N Log K)
    //! SC = O(K)

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    // Lazy Deletion
    unordered_map<int,int> m;

    int k;
    int leftSize = 0, rightSize = 0;

    // Remove Stale guys
    void pruneLeft(){
      while(!left.empty() && m[left.top()]){
        m[left.top()]--;
        left.pop();
      }
    }
    void  pruneRight(){
      while(!right.empty() && m[right.top()]){
        m[right.top()]--;
        right.pop();
      }
    }

    // Balancing Heaps
    void rebalance(){
      if(leftSize > rightSize + 1){
        right.push(left.top());
        left.pop();
        leftSize--, rightSize++;
        pruneLeft();
      }
      else if(leftSize < rightSize){
        left.push(right.top());
        right.pop();
        leftSize++, rightSize--;
        pruneRight();
      }
    }


    void add(int x){
      if(left.empty() || (x < left.top())){
        left.push(x);
        leftSize++;
      }
      else {
        right.push(x);
        rightSize++;
      }
      rebalance();
    }

    void remove(int x){
      m[x]++;

      if(x <= left.top()){
        leftSize--;
        if(x == left.top()) pruneLeft();
      }
      else{
        rightSize--;
        if(!right.empty() && x == right.top()) pruneRight();
      }

      rebalance();
    }

    double getMedian(){
      if(k & 1) return left.top();
      return ((double) left.top() + right.top())/2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k_) {
        k = k_;
        vector<double> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
          add(nums[i]);

          if(i >= k-1){
            ans.push_back(getMedian());

            remove(nums[i-k+1]);
          }
        }
        return ans;
    }
};
