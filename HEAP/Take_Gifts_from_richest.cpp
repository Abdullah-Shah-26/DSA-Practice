class Solution { // TC =  O(k * logn)
    public: // Max heap
        long long pickGifts(vector<int>& gifts, int k) {
            // first push all the elemets in priority q
            priority_queue<int> p;
    
            for (int i = 0; i < gifts.size(); i++)
                p.push(gifts[i]);
    
            long long sumofroots = 0;
            // while q isnt empty and k isnt 0
            while(k != 0 && !p.empty()) {
                int topValue = p.top();
                      p.pop();
                
                int newValue = (int)floor(sqrt((long double)topValue));
    
                // if root isnt 0 push it 
                if(newValue)
                p.push(newValue);
          
                k--;
            }
    
            while(!p.empty()){
            sumofroots += p.top();
            p.pop();
        }
            return sumofroots;
        }
    };