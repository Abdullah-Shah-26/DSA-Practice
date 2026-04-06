#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


#include <algorithm>
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
/// MIN HEAP - 
// pair - {data,{row,col}} - inorder to access the next element of popped element in its row
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>>p;

//! TC =  KlogK 
int maximum = INT_MIN, minimum;
// first push all the first elements of each row (list) in heap
for(int i =  0; i< nums.size() ; i++)
{
    p.push({nums[i][0], {i,0}});
// compare each element that we are inserting with max and update it when its greater
// we can update the min using heap
    maximum = max(maximum , nums[i][0]);
}
minimum = p.top().first;
vector<int>ans(2); // ans vector storing the smallest range covering at least 1 elements from k lists
ans[0] = minimum;
ans[1] = maximum;

pair<int,pair<int, int>>temp; // vector of pairs
int row , col , elem;

//! TC = n * klogK (k lists * n elements in each) - insertion deletion from heap
// until heap have 1 element from each list  
while(p.size() == nums.size())
{
    temp = p.top();
    p.pop();

    elem = temp.first;
    row = temp.second.first;
    col = temp.second.second;

   
    if(col + 1 < nums[row].size())
    {
        col ++; // push the next element of the popped element
        p.push({nums[row][col], {row,col}});
        maximum = max(maximum, nums[row][col]);
        minimum = p.top().first;

    // if i have got smallest range
    if(maximum - minimum < ans[1] - ans[0])
    {
        ans[0] = minimum ;
        ans[1] = maximum;
    }
   }
 }
    return ans;
}
};