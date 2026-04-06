class Solution {
    public:
        bool isPossible(vector<int>& target) {
    // reverse thinkiing achieve all 1 ' s
    
    // Max Heap
    priority_queue<long long>p;
    long long sum = 0;
    
    for(int i = 0; i < target.size(); i++)
        {
            p.push(target[i]);
            sum += target[i];
        }
    long long MaxElem , RemSum , Element;
    
    // jab tak heap ka top 1 na ho jaye 
    while(p.top() != 1)
    {
        MaxElem = p.top();
        p.pop();
        RemSum = sum - MaxElem;
    
        // MaxElem = RemSum + Element  - so 
        /// EDGE case
        if(RemSum <= 0 || RemSum >= MaxElem)// remaining sum can't be -ve or > MaxElem
        return 0;    // target array not possible 
    
    // to avoid repetitive steps - avoids TLE
        Element = MaxElem % RemSum;
        if(Element == 0)
        {
            if(RemSum != 1) // ans cannot be possible
            return 0;
            else 
            return 1;
        }
        sum = RemSum + Element; /// update sum
        p.push(Element);
    
        }
    return 1;
    }
    };