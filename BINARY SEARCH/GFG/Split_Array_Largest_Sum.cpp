class Solution {
    public:// TC = O(Nlog(n))
      int splitArray(int arr[] ,int n, int k) {
          // code here
          // binary search approach same as book allocation
          int sum = 0;
          for(int i = 0; i < n ; i++)
          sum += arr[i];
          int ans = -1;
          int maxelem = *max_element(arr,arr+n);
          
          int st = maxelem , end = sum;
                                  // n
          while(st <= end) // O(log(range))
          {
          // prob - find min possible max allowed subarray sum
              // mid = max allowed subarray sum
              int mid = st + (end - st)/2;
              int subarrsum = 0, Noofsubarrays = 1;
              for(int i = 0 ; i < n ; i++) // O(N)
              {
                  subarrsum += arr[i];
                  if(subarrsum > mid)
                  {
                      // we will need 1 more subarray
                      Noofsubarrays++;
                      subarrsum = arr[i];
                  }
              }
              if(Noofsubarrays <= k)
              {
                  // store the valid max no of subarrays and find its minpossible
              ans = mid ;
              end = mid - 1;
              }
              else
              st = mid + 1; // increase the max allowed subarray sum
          }
          return ans;
      }
  };