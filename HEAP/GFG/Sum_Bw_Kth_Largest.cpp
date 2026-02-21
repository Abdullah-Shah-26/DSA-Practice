class Solution{
    public:
    long long sumBetweenTwoKth( long long arr[], long long N, long long k1, long long k2)
    {
    // similar concept to kth largest element
    //we will create 2 Max heaps of k1 and push k1 elements in it 
    // & create another  k2-1 elements and push k2 -1 elements in it  
    //dono ka sum noikalke minus kardo 
    // we get sumofnos bw k1 and k2

    priority_queue<long long >p1;
    
    for(long long i = 0; i < k1; i++)
        p1.push(arr[i]);
    // find k1 smallest element & compare it with p1.top if less then replace it with arr[i]    
    for(long long i = k1 ; i<N; i++)
    {
        if(arr[i] < p1.top())
        {
            p1.pop();
           p1.push(arr[i]);
        }
    }
    
    priority_queue<long long >p2;
    
    for(long long i = 0; i< k2 -1; i++)
        p2.push(arr[i]);
 // find k2-1  smallest  element in array       
    for(long long i = k2-1; i < N; i++)
    {
        if(arr[i] < p2.top())
          {
           p2.pop();
           p2.push(arr[i]);
        }
    }
        
    // sum of first max heap 
    long long sum1 = 0, sum2 = 0;
    while(!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    while(!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }
    
    return sum2 - sum1;        
        }
        
    
    
};