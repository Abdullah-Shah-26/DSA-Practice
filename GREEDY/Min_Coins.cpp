class Solution {
  public:
  // TC = O n  SC = O n 
    vector<int> minPartition(int N) {
        int curr[] = {2000, 500, 200, 100, 50, 20 , 10 , 5, 2, 1};
        int notes = 0, i = 0;
        
        vector<int>ans;
        while(N)
        {
            notes = N/curr[i];
            
            while(notes--)
            {
                ans.push_back(curr[i]);
            }
            
        N %= curr[i];
        i++;
        }
        return ans;
    }
};