#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
      int n = nums.size();

      for(int i = 0; i < n; i++){
        if(nums[i] == target) nums[i] = 1;
        else nums[i] = -1;
      }

      oset os;
      os.insert(0);

      ll ans = 0;
      ll prefSum = 0;

      for(auto &x : nums){
        prefSum += x;

        // Strictly smaller
        ans += os.order_of_key(prefSum);

        os.insert(prefSum);
      }

      return ans;
    }
};    

//! Merge Sort Approach like Count Inversions
class Solution {
public:
    //! TC = O(N Log N)
    //! SC = O(N)
    long long merge(vector<int> &arr, int low, int mid, int high){
      long long cnt = 0;
      vector<int> temp;

      int l = low;
      for(int r = mid + 1; r <= high; r++){
        while(l <= mid && arr[l] < arr[r]){
          l++;
        }
        cnt += (l - low);
      }

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

      return cnt;
    }

    long long mergeSort(vector<int> &arr, int low, int high){
      
      if(low >= high) return 0;
      long long cnt = 0;
      
      int mid = (low + high) >> 1;

      cnt += mergeSort(arr, low, mid);
      cnt += mergeSort(arr, mid + 1, high);

      cnt += merge(arr, low, mid, high);

      return cnt;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {

    int n = nums.size();

    for(int i = 0; i < n; i++){
      if(nums[i] == target) nums[i] = 1;
      else nums[i] = -1;
    }    

    vector<int> pref(n + 1,0);

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i - 1] + nums[i - 1];
    }

    return mergeSort(pref, 0, n);
    }
};