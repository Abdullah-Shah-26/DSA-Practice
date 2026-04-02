#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! MergeSort + 2 pointer --- (O(NLogN))
//! MergeSort + Binary Search === O(N (Log^2 N))

class Solution {
public:
  // L <= pref[j] - pref[i] <= R
  // L + pref[i] <= pref[j] <= R + pref[i]
  
  // Fix i , search j 
  // pref[j] E [ L + pref[i], R + pref[i]]

  long long mergeAndCnt(vector<long long>& arr, int low, int mid, int high, int L,int R){
    long long cnt = 0;

    int k = mid + 1; 
    int j = mid + 1; 

    for(int i = low; i <= mid; i++){
      while(k <= high && arr[k] < arr[i] + L) k++;
      while(j <= high && arr[j] <= arr[i] + R) j++;

      // auto lowIt = lower_bound(arr.begin() + mid + 1, arr.begin() + high + 1, arr[i] + L);

      // auto highIt = upper_bound(arr.begin() + mid + 1, arr.begin() + high + 1, arr[i] + R);

      // cnt += (highIt - lowIt);

      cnt += (j-k);
    }

    vector<long long> temp;
    int left = low, right = mid + 1;

    while(left <= mid && right <= high){
      if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
      }
      else{
        temp.push_back(arr[right]);
        right++;
      }
    }
  
    while(left <= mid){
      temp.push_back(arr[left]);
      left++;
    }

    while(right <= high){
      temp.push_back(arr[right]);
      right++;
    }

    for(int i = low; i <= high; i++){
      arr[i] = temp[i-low];
    }

    return cnt;
  }

  long long solve(vector<long long> &pref, int l, int r, int L, int R){
    if(l >= r) return 0;

    int mid = (l + r) >> 1;

    long long cnt = 0;

    cnt += solve(pref, l, mid, L, R);
    cnt += solve(pref, mid+1, r, L, R);
    cnt += mergeAndCnt(pref, l, mid, r, L, R); 

    return cnt;
  }

  int countRangeSum(vector<int>& nums, int L, int R) {
  int n = nums.size();  

  vector<long long> pref(n + 1, 0);

  for(int i = 1; i <= n; i++){
    pref[i] = pref[i - 1] + nums[i - 1];
  }  

  return solve(pref, 0, n, L, R);
  }
};