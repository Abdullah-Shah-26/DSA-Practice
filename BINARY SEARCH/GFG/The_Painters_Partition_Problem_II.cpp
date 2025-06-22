class Solution { // exactly same approach as book allocation & even same code
// even when we dont req all painters to work
// TC = O(Nlogn)
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        int ans = -1;
        
        int sum = 0 ;
        int n = arr.size();
        for(int i = 0 ; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        int maxelem = *max_element(arr.begin(), arr.end());
          
        int st = maxelem , end = sum;
        
        while(st <= end) // O(logn)
        {
            int mid = st + (end - st)/2;
            int boardslen = 0 , painters = 1; 
            for(int i = 0 ; i < n; i++)// O(N)
            {
                boardslen += arr[i];
                if(boardslen > mid)
                {
                    painters++;
                    boardslen = arr[i];
                }
            }
        if(painters <= k)
        {
            ans = mid;
            end =  mid -1;
        }
        else 
        st = mid + 1;
        }
        return ans;
    }
   
};