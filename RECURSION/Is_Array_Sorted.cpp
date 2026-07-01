#include <bits/stdc++.h>
using namespace std;

// TC = O(n)     // SC = O(n)
bool isSorted(vector<int> arr ,int n){
  if(n == 0 || n == 1){ // if arr is empty or only 1 element it is sorted 
    return true;
  }
  return arr[n-1] >= arr[n-2] && isSorted(arr , n-1); // check for rest of arr only is last element is sorted
}
int main(){

  vector<int>arr = { 1,2,3,4,5};

  cout<< isSorted(arr , arr.size()) <<endl;
}