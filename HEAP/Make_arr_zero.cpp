class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            // ! super unoptimized 
    
            // // Min Heap
            // priority_queue<int,vector<int>,greater<int>>q;
            // int k = 0;
            // for(int i = 0 ; i<nums.size(); i++)
            //     q.push(nums[i]);
            // vector<int>temp;
    
            // while(!q.empty())
            // {
            //     int x = q.top();
            //     q.pop();
            //     if(x == 0)
            //     continue;
    
            //     while(!q.empty())
            //     {
            //         int y = q.top();
            //         q.pop();
    
            //         if(y - x)
            //         {
            //             temp.push_back(y-x);
            //         }
            //         k++;
            //     }
            //     for(int i = 0 ; i<temp.size(); i++)
            //         q.push(temp[i]);
    
                     
            // }
            // return k;
            
             // key obsv - no of unique elements = no of ops required
            //! optimized  - tc = o(n)
            unordered_set<int>set;
            for(auto i : nums)
            {
            if(i != 0)
            set.insert(i);
            }
            return set.size();
        }
    };