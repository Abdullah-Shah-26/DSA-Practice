class Solution {
    public:
      int search(vector<int>& arr, int target) {
          // binary search apporach
                int st = 0  , end = arr.size() - 1, mid;
                
                while(st <= end)
                {
                    mid = st + (end - st)/2;
                    
                    // if tar is found
                    if(arr[mid] == target)
                    return mid;
                    
                    // Left side sorted
                    else if(arr[mid] >= arr[0])
                    {
          /// check if target lies in left range or right range
                        if(arr[st] <= target && arr[mid] >= target)
                        end = mid -1 ; // search in left
                        else 
                        st =  mid + 1; // search in right
                        
                    }
                   // right side sorted  // arr[mid] > arr[0]
                   else{
              // check if target lies in left range or right range
                  if(arr[mid] < target && arr[end] >= target)
                  st = mid + 1; /// search in right 
                  else 
                  end = mid - 1; // else left
                   }
                }
                return -1;
      }
  };
  