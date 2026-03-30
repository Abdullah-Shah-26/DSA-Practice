#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N + LogN)

class Solution {
  public:
    
    void merge(vector<int> &arr, int low, int mid, int high){
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        
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
            arr[i] = temp[i - low];
        }
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    
    int mid = (l + r) >> 1;
    
    mergeSort(arr, l , mid);
    mergeSort(arr, mid + 1, r);
    
    merge(arr, l, mid, r);
    }
};  

//! Iterative Merge Sort
//! TC = (N Log N)
//! SC = O(N)

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high){
      vector<int> temp;
      int left = low;
      int right = mid + 1;

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
        arr[i] = temp[i - low];
      }
    }
    
    vector<int> sortArray(vector<int>& arr) {
    int n = arr.size();

    for(int size = 1; size < n; size *= 2){
      for(int left = 0; left < n; left += 2*size){
        int mid = min(n - 1, left + size - 1);
        int right = min(n - 1, left + 2 * size - 1);

        if(mid < right) merge(arr, left, mid, right);
      }
    }

    return arr;
    }
};