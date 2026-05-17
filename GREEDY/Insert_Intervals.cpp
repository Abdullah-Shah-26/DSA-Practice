class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>>ans;
       int i = 0; 
       int n = intervals.size();
                    // newinterval st > oldinterval end
       while(i < n && newInterval[0] > intervals[i][1]){
        ans.push_back(intervals[i]); // no overlap
        i++;
       } 

    if(i == n)
    {   // No overlap till last - so new interval will be pushed at last
        ans.push_back(newInterval);
        return ans;

    }
            // newInt end >= oldInt St
while(i < n && newInterval[1] >= intervals[i][0])
{
    // Intervals overlap - Merge them 
    // new st
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    // new end
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i++;
    }

ans.push_back(newInterval);


// For the rest lest out intervals directly push them in ans
while(i < n)
{
    ans.push_back(intervals[i]);
    i++;
}
return ans;
}
};