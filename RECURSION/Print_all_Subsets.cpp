#include <bits/stdc++.h>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans , int i){ // index i to track index of elements
  if(i == arr.size()){// base case print all subsets
    for(int val: ans){
      cout<< val <<" ";
    }
    cout<<endl;
    return;
  }

// include element in subset
ans.push_back(arr[i]);
printSubsets(arr , ans, i+1);

ans.pop_back();     //backtracking returning orginal arr to prev call before excluding step 

// excluding step
printSubsets(arr, ans, i+1);
}
int main(){
  vector<int> arr = {1,2,3};
  vector<int> ans; // to store subsets
  printSubsets(arr, ans, 0);
  return 0;
}