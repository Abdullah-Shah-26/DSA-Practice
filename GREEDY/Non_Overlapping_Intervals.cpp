// sort on the basis of end value
bool comp(vector<int>a , vector<int>b)
{
    return a[1] < b[1];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);

    int end = INT_MIN;
    int remove = 0; // No of intervals removed

    for(int i = 0; i < intervals.size(); i++)
    {  // if prev ka  end < next ka st
        if(end <= intervals[i][0])
        {
            // No overlap - update end 
            end = intervals[i][1];
        }
        else 
        {
            // overlap - remove that interval
            remove++;
        }
    }
return remove;
    }
};