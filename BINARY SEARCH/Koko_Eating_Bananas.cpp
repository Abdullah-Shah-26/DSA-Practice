class Solution {
    public: // Brute Force approach
        int minEatingSpeed(vector<int>& piles, int h) {
            // O(n^2) // i indicates speed
                for (int i = 1; i <= *max_element(piles.begin(), piles.end()); ++i) {
                int hrs = 0;
                for (int j = 0; j < piles.size(); ++j) {
                    hrs += ceil((double)piles[j] / i);
                }
                if (hrs <= h) {
                    return i;
                }
            }
            return -1;
        }
    };

        //! Binary Search - similar to BOOK allocation
        int st = 0 , end = 0 , mid , ans , n = piles.size(); //TC = O(nlogn)
        // we will st from the min req speed ie sum / hr and end will be max value why ? cause maxvalue of eating bananas/hr will be max speed req
        long long sum = 0; // edge case
        for(int i = 0 ; i < n ; i++)
            {
            sum += piles[i];
            end = max(end, piles[i]); 
            }
        st = sum/h;
        // edge case - div by 0)
        if(!st)
        st = 1; 

        while(st <= end){
            mid = st + (end - st)/2;
        // mid is the speed with which it will consume bananas/hr
            int total_time = 0;
            for(int i = 0; i< n; i++)
            {   

                total_time += (piles[i]/mid);
                // rounding up correctly
                if(piles[i]%mid) 
                total_time++;
            }
            if(total_time > h)// increase the speed of eating bananas
            {// go right
                st = mid + 1;
            }
            else
            {  // if total_time <= h store in ans and find the min possible value of speed 
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};
