class Solution {
    public: //! TC = O(n ^ 2) can be optimized to O(n)
        int timeRequiredToBuy(vector<int>& tickets, int k) {
           queue<int> q; //for storing index of person
           int n = tickets.size(); 
    
    
           for(int i =0; i<n ; i++)
           q.push(i); // pushing all idx into q
    
           int time = 0;
           
           // jab tak k index wale ko saare tickets nai mil jaate cal time
           while(tickets[k] != 0){
            
                tickets[q.front()]--; //ek ticket leliya minus kardo
                // kya ye line mein dobara lagega 
                if(tickets[q.front()]) // kya use aur tickets chahiye
                q.push(q.front()); // haa to phirse Q ke peeche jao
    
                //else
                q.pop(); // no then exit from Q
    
                time++;
                
    
               
           }
            return time;
        }
    };

    //! optimized approach 

    class Solution {
        public: //! TC = O(n ^ 2) can be optimized to O(n)
            int timeRequiredToBuy(vector<int>& tickets, int k) {
                   int time = 0;
                    for(int i = 0; i<= k; i++){
                        time += min(tickets[k],tickets[i]);
                    }
                    for(int i =k+1; i <tickets.size(); i++){
                        time += min(tickets[k-1],tickets[i]);
                    }
                    return time;
               }
            };
        
        