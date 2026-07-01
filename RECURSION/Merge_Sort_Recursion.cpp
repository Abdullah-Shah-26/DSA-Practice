#include <bits/stdc++.h>
using namespace std;

//! TO merge sorted parts
void merge(vector<int> &arr, int st, int mid, int end){ 
vector<int> temp;  // sorted values are first stored in temp
int i = st;   
int j= mid +1;

while (i <= mid && j <= end){
    if(arr[i] <= arr[j]){//smaller values are first stored in temp //*? if we >= sorting will be in descending order  
        temp.push_back(arr[i]);
        i++;
    }
    else{
        temp.push_back(arr[j]);
        j++;
    }
}
// for left out elements in 

  //left half
  while( i<= mid){
    temp.push_back(arr[i]);
    i++;
  }
  // for left out elements in 
  //right half
  while(j <= end){
    temp.push_back(arr[j]);
    j++;
  }
  // now copy temp in original array
  for(int idx = 0; idx< temp.size(); idx++){
    arr[idx + st] = temp[idx];
  }
}


//! recursively dividing arr until it becomes single element and calculating mid
void mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st+(end-st)/2;

        mergeSort(arr, st, mid); //left half
        mergeSort(arr, mid+1, end); //right half

        merge(arr, st, mid, end); //calling merge step
    }
}
int main(){
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr ,0 , arr.size()- 1);  //last index

    for(int val : arr){
    cout<< val << " ";
    }
    cout<<endl;
    return 0;
}