#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // sliding window - 2 pointer approach
            // TC = O(N)    SC = O(256) = O(1)
            vector<bool>count(256,0);
    // array containing all 256 char and initally marked as 0 ( not included in window )
    // whenever we find unique char include in window by doing second ++ and change 0 to 1 in char arr
            int first = 0; 
            int second = 0;
            int len = 0;
    
            while(second < s.size())
            {
    // if we find any duplicate char 
    // remove all the char from front until the repeating char gets removed from the window 
        while(count[s[second]])
        {
            count[s[first]] = 0; // mark the char which are going outside of window as not seen 
            first ++;
    
          }
        count[s[second]] = 1; 
        len = max(len , second - first + 1);
        second ++;
       }
        return len;
        }
    };
