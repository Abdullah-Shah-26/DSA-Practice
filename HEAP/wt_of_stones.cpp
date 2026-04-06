
class Solution { 
    public:// Max heap 
        int lastStoneWeight(vector<int>& stones) {
           // first push all elements in PQ
           priority_queue<int>p;
           for(int i = 0; i<stones.size(); i++)
                p.push(stones[i]);
    
           // until q has 1 element left 
           while(p.size() > 1)
           {
            int wt_stone1 = p.top();
            p.pop();
            int wt_stone2 = p.top();
            p.pop();
    
            // after colliding their wt is subtracted 
            int wt = wt_stone1 - wt_stone2;
            // if wt becomes 0 don't push it 
            if(wt)
            p.push(wt);
    
           }
           // edge case
           // eg 2 2 where q becomes empty 
           return p.empty()?  0 : p.top();     
        }
    };