class Solution {
    public:
        string minWindow(string s, string t) {
            // sliding window appraoch - 
            int total = t.size();// shows the no of char of t required in s
            // char, count in map
    //!  --- unordered_map<char,int>m; // characters needed in s 
    // can use vector too
        vector<int>m(256,0); // optimization - since we just have 256 char and we can use ascii val
            
            for(int i = 0; i < t.size(); i++)
                m[t[i]]++;
    // in ans we will store the min length of substr and index will store starting idx of ans 
            int start = 0, end = 0 , ans = INT_MAX, index = -1;
    
            while(end < s.size())
            {
                m[s[end]]--; //decrease the count of needed char
                if(m[s[end]] >= 0) // if count is not -ve decrease the total 
                total--; // means we have found the req char decrease its count in map
    
                // can we decrease the size of the window 
                while(!total && start <= end)
                {
                    // update the length of substr -  min substr containing all req char  will be our ans
                    if(ans > end - start + 1 )
                    {
                        ans = end - start + 1;
                        index = start; // storing the st idx of ans substr
                    }
    
                    m[s[start]]++; // increase the count of char
    // the char that are required are stored in map and they will have + ve 
    // some extra char that we dont need will have - ve count
    // since total becomes 0 that means all the req char count is 0 
    // if the req char count increases then total should also inc (since its denoting the no of char req)    
                if(m[s[start]] > 0) 
                total++;
                start++; // decreasing the window size from front
                }
            end++; // total > 0 then increase window size to include the req 
            }    
            if(index == -1) // means we havent found our ans substr
            return "";
    
    
            string str  =  "";
    
            for(int i = index; i < index + ans; i++)
                str  += s[i];
    
            return str;
        }
    };