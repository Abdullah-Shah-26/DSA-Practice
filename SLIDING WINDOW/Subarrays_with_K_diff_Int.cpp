#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
         // brute force - TC = O(n^2)
         int n = nums.size();
         int count = 0;
         for(int i = 0; i < n ; i++)
         {
            // unique char & its freq
            unordered_map<int,int>m;
            int total = 0;// no of unique char
            for(int j = i ; j < n ; j++)
            {   
                if(m[nums[j]] == 0){
                    total++;
                } 
                if(total > k )
                continue;  
                m[nums[j]]++;
    
            
                if(total == k )
                count++;
            }
         }
         return count;
        }
    };
//! Method - 2 
class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
           int total = 0;
        // redefine the question
        // (part 1)count of subarr with atleeast k diff elements - (part 2)subarr (k+1)atleast k+1 diff elem = total no of subarrays having exactly k diff elements
    
        // part 1 
        unordered_map<int, int>freq;
        int start = 0 , end = 0, n = nums.size(), count = 0;
        // count variable stores count of unique integers in that window 
        while(end < n )
        {
            freq[nums[end]]++;
            
            if(freq[nums[end]] == 1) // when u see unique char first time inc count
            count++;
    // increase the window size until we get k unique elements in subarr
    
    // decrease window size 
    while(count == k)
    {
        total +=  n - end; // total of all valid subarrays 
        freq[nums[start]]--;
        if(freq[nums[start]] == 0)
        count--;
    
        start++;
    }
    end++;     
        }
        //part 2
        start = 0, end = 0 , count = 0;
        freq.clear();
        k++;  //cleared in map
    
         while(end < n )
        {
            freq[nums[end]]++;
            
            if(freq[nums[end]] == 1) // when u see unique char first time inc count
            count++;
    // increase the window size until we get k unique elements in subarr
    
    // decrease window size 
    while(count == k)
    {
        total -=  n - end; // total of all valid subarrays 
        freq[nums[start]]--;
        if(freq[nums[start]] == 0)
        count--;
    
        start++;
    }
    end++;     
        }
        return total;
    
        }
    };
//! Method - 3
class Solution {
    public:
    int atmost(vector<int>&nums, int k)
    {
        unordered_map<int,int>freq;
        int start = 0, end = 0, total = 0,count = 0;// stores the no of unique elem
        int n = nums.size();
    
        while(end < n)
        {
            freq[nums[end]]++;
    
            if(freq[nums[end]] == 1)
            count++;
    
            // decrease window size 
            while(count > k)
            {
            
            freq[nums[start]]--;
    
            if(freq[nums[start]] == 0)
            count--;
    
            start++;
            }
        total += end - start + 1;
        end++;// increase window size until count <= k
    
        } 
        return total;
    }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Method - 3  
        // no of subarrays having atmost(k) unique elements - no of subarrays having atmost(k-1) unique elements = total no of subarr having exactly k unique elem
        return atmost(nums,k) - atmost(nums,k-1);
        }
    };