class Solution {
    public: // binary search approach exactly same as book allocation
        int shipWithinDays(vector<int>& arr, int k) {
            int n = arr.size();    
            int sum = 0;
            int ans = -1;
            for(int i = 0 ; i < arr.size(); i++)
            {
                sum += arr[i];
            }
            int maxelem = *max_element(arr.begin(), arr.end());
    
            int st = maxelem, end = sum; 
            while(st <= end)
            {
                // mid = max allowed weight on ship
                int mid = st + (end - st)/2;
                int days = 1, weights = 0;
            for(int i = 0 ; i < n ; i++)
            {
                weights += arr[i];
                if(weights > mid)
                {
                    // we will need 1 more day
                    days++;
                    weights = arr[i];
                }

                
            }
                if(days <= k )
                {
                    //store valid max weight capacity of ship and find its min possible
                    ans = mid;
                    end = mid - 1;
                }
                else
                st = mid + 1; // increase the max wt capacity of the ship
                 }
           return ans;  
        }
    };