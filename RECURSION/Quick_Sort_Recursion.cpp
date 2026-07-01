#include <bits/stdc++.h>
using namespace std;

//! partition logic - 2 iterators i and j
//! i = places element <= pivot to left also places piv at correct position at last
//! j = compares all elements to pivot and i makes spaces for <= elements
int partition(vector<int> &arr, int st, int end){
  int idx = st -1 , pivot = arr[end]; // idx is initialized at some empty position before 1st element

  for(int j = st; j < end; j++){
    if(arr[j] <= pivot){   //>= for descending order
      idx ++; //* first place idx at correct position 
      swap(arr[j],arr[idx]);
    }
  }
  idx ++; //* assigning correct position to pivot
  swap(arr[end], arr[idx]);
  return idx; //returns correct position of pivot

}


void quickSort(vector<int> &arr, int st, int end){
  if(st < end){
    int pivIdx = partition(arr, st, end); // partition will return correct piv idx of sorted arr

    quickSort(arr, st, pivIdx-1);// left half
    quickSort(arr, pivIdx+1,end);// right half

  }
}


int main(){
  vector<int> arr = {12, 31, 35, 8, 32, 17};
  quickSort(arr, 0, arr.size()-1); //passing idx
    
  for(int val : arr){
    cout<< val << " ";

  }
  cout<<endl;

}