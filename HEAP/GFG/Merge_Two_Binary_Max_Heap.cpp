// Brute force 
class Solution{ // TC = O(n+m)log(n + m) + O(n+m)log(n + m)
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int>p;
        for(int i = 0; i<n;i++)
        {
            p.push(a[i]);
        }
        for(int i = 0; i<m; i++)
        {
            p.push(b[i]);
        }
        vector<int>ans;
        while(!p.empty())
        {
            ans.push_back(p.top());
            p.pop();
        }
        return ans;
    }
};
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // optimized approach - just push all n+m to array and convert to heap 
    // heapify process & step down method 
    // TC = O(n+m)
        vector<int>ans;
        
        for(int i = 0; i< n; i++)
        {
            ans.push_back(a[i]);
        }
        for(int i = 0; i< m ; i++)
        {
            ans.push_back(b[i]);
        }
        
        // convert ans array to max heap
        n = ans.size();
        // step down process - Heapify
        for(int i = n/2-1; i>= 0; i--)
        Heapify(ans, i, n);
        
        return ans;
    }
}