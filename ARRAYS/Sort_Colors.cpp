#include <bits/stdc++.h>;
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) { //! DNF algorithm // TC = O(n) - divides arr into 3 partition of 0 s 1 s and 2s along with unsorted part which keeps minimizing and sorts in 1 pass
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
    
            while(mid <= high){
                if( nums[mid] == 0){
                    swap(nums[low], nums[mid]);
                    mid++;
                    low++;
                }
                else if( nums[mid] == 1 ){
                    mid++;
                }
                else{ // 2
                swap(nums[high], nums[mid]);
                high--;
                }
            }
            
        }
    };