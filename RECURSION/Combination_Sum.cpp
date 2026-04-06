#include <vector>
#include <set>
using namespace std;

class Solution{ //*Worst-Case Time Complexity: O(3^n)
 
public: // tar == combiantionSUM 
 

//!creating a set to track unique combinations 
set<vector<int>>s;

void getAllCombinations(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin){
    if(idx == arr.size() || tar<0){//base case targetsum not found after travelling whole arr or tar cant be -ve
        return;
    }
    if(tar == 0){ // means our commbination equals targetsum
        if(s.find(combin) == s.end()){ //!checks whether combination already exists in set
        ans.push_back(combin); //store ans 
            s.insert(combin); //!  insert that combination in set
        }
        return;
    }

    combin.push_back(arr[idx]);     
    // single time element inclusion choice
    getAllCombinations(arr, idx+1, tar - arr[idx], ans, combin);
    // multiple inclusion choice
    getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
    combin.pop_back(); // backtracking step popping the included element before returning to prev calls 
    //exclusion of element ki choice
    getAllCombinations(arr, idx+1 , tar - arr[idx], ans, combin);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombinations(arr, 0, target, ans, combin);
    return ans;
}
};