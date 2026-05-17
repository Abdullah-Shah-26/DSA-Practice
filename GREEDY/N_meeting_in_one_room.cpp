bool comp(pair<int, int>a , pair<int, int>b)
{
    return a.second < b.second;
}


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>timer;
        
        
        /// sort it on the basis of end time in ascending order 
        for(int i = 0; i < n ; i ++)
        {
            timer.push_back({start[i], end[i]});
        }
        /// sort it on the basis of end time in ascending order 
        sort(timer.begin(), timer.end(), comp);
        
        // max kitni meeting karwa sakte hay 
        int total = 0;
        int ending = -1;
        
        for(int i =0; i < n; i++)
        {
            
            if(timer[i].first > ending)
            {
                total++;
                ending = timer[i].second;
            }
        }
        return total;// prev meeting end time should be less than the st time of next meeting 
    }
};