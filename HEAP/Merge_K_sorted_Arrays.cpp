class Solution //! MODIFIED MERGE SORT 
{ public:
    void merge(vector<int> &arr, int st, int mid, int end )
    {
    vector<int>temp; //sorted values are stored in temp
    int i = st;
    int j = mid + 1;
    
    while(i <= mid && j <=end)
    {
        if(arr[i] <= arr[j]){
    // smaller val are first stored in temp
    temp.push_back(arr[i]);
    i++;
    }
    else{
        temp.push_back(arr[j]);
        j++;
    }
    }
    // for left out elements in 
    
    // left half
    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    // right half
    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    // now copy temp in original array
    for(int i = 0; i < temp.size(); i++)
    {
        arr[i + st] = temp[i];
    }
    }
    
    
    void mergesort(vector<int>&arr, int start, int end,int portion, int k)
    {
        if(portion < 2 ) // portion 1 hote hi stop
        return;
        // handle odd and even case 
        int mid = start + (portion / 2)* k - 1;
        
        // recursively call merge sort for left and right portion 
        mergesort(arr, start, mid  , portion/2,k);
        mergesort(arr, mid + 1, end, portion - portion/2, k);
        merge(arr,start,mid,end);
        
    }
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
    // we will uss merge sort and divide based on partition
    // won't be sorting the already sorted part
    vector<int>ans;
    for(int i = 0; i < k ; i++)
        for(int j = 0; j < k ; j++)
            ans.push_back(arr[i][j]);
            
    mergesort(ans, 0 , ans.size() - 1, k , k );
    return ans;
    }
};
//! USING MIN heap 
// SC = O(k) // TC = (k^2logk)
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {   
        
        // first push all first col elements in heap using temp // TC = O(K)
        vector<pair<int,pair<int,int>>>temp;
        for(int i = 0; i<k ; i++)
            {
                temp.push_back({arr[i][0],{i,0}});
            }
// concept similar to kth smallest in martix
// MIN HEAP 
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
    // pair ->  data ,row , col
    
    vector<int>ans;// vector which will store the sorted data
    
    pair<int,pair<int,int>>element;
    int i , j;
    
    while(!p.empty())
    {
        element = p.top();
        p.pop();
        ans.push_back(element.first); // data(element) is pushed in ans
        i = element.second.first; // row 
        j = element.second.second; // col
        
        if( j+1 < k) // popped wale ke row mein next wala element daalo
        p.push({ arr[i][j+1] , {i,j+1}});
        
    }
    return ans;
    }
}; 