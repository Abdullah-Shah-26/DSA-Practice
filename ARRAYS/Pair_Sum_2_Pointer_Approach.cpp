#include <vector> //? TC = O(n)
#include <set>
#include<iostream>
using namespace std;
//! PS 
vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;

    int n = nums.size();
    // 2 pointers - actually variables
    int i = 0 , j = n-1;
    // 3 cases 
    while(i < j){
        int pairSum = nums[i] + nums[j];
        // 1 PS > tar 
        if(pairSum > target){
            j--; // reduce bada NO since arr is sorted
        }
        // 2 PS < tar
        else if(pairSum < target){
            i++;  // increase chota no 
        }
        // 3 PS == tar 

        else{ // RETURN ANS
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans; // returns an empty vec if ans isnt found
}
int main(){
    vector<int> nums = { 2,7,11,15};
    int target = 13;
    
    vector<int> ans = pairSum(nums, target);
    cout<< ans[0] <<" , " << ans[1] <<endl; // returns index of pairs
    
}