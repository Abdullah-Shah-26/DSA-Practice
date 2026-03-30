#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N)

class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high){
      int left = low;
      int right = mid + 1;
      int cnt = 0;
      vector<int> temp;

      while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
          temp.push_back(arr[left]);
          left++;
        }
        else{
          cnt += (mid - left + 1);
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

    int mergeSort(vector<int> &arr, int low, int high){
      if(low >= high) return 0;
    
      int cnt = 0;
      int mid = (low + high) >> 1;

      cnt += mergeSort(arr, low, mid);
      cnt += mergeSort(arr, mid + 1, high);

      cnt += merge(arr, low, mid, high);
    
     return cnt;
    }
  
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
        
    }
};