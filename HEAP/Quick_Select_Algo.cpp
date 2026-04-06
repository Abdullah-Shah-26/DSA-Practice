#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution { 
    public: // TC = O(n) - best & avg case 
    // SC = O(1)
        // partition logic
        int partition_algo(vector<int> &nums, int L ,int R){
            int P = nums[L]; // pivot as first element
            int i = L+1;// i ko 1 se start  karo to handle edge case of single element
            int j = R;
    
            while(i <= j)
            {
                if(nums[i] < P && nums[j] > P)
                {
                    swap(nums[i],nums[j]);
                    i++; 
                    j--;
                }
                if(nums[i] >= P)
                {
                    i++;
                }
                if(nums[j] <= P)
                {
                    j--;
                }
            }
            swap(nums[L], nums[j]);// pivot ko j se swap karenge
            return j; // pivot is at j return pivot idx
        }
    
        int findKthLargest(vector<int>& nums, int k) {
            // quick select algorithm - To find kth largest or smallest element in arr/vec
            int n = nums.size();
            int L = 0;
            int R = n-1;
            int pivot_idx = 0; // taking first element as pivot
            // kth largest pivot element - nums[k-1] hoga (desending order mein partition karenge)
    
            while(true)
            {
                pivot_idx == partition_algo(nums, L, R);
    
                if(pivot_idx == k-1)
                {
                    break;
                }
                else if(pivot_idx > k-1) // left jao
                {
                    R = pivot_idx - 1;
                }
                else{
                    L = pivot_idx + 1; // right jao
                }
            }
    
            return nums[pivot_idx];
        }
    };