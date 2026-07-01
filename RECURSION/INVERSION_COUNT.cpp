#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){
  vector<int>temp;
  int i = st, j= mid+1;
  int invCount = 0; // to count no of inversion pairs
  while(i<= mid && j<= end){
    if(arr[i] <= arr[j]){
      temp.push_back(arr[i]);
      i++;
    }else{
      temp.push_back(arr[j]);
      j++;
      invCount += (mid-i+1);

    }
  }
  while(i<= mid){
    temp.push_back(arr[i]);
    i++; 
  }
  while(j<= end){
    temp.push_back(arr[j]);
      j++;
   }
   for(int idx = 0; idx < temp.size(); idx++) {
    arr[idx + st] = temp[ idx ];

   }
   return invCount;

}

int mergeSort(vector<int> &arr, int st, int end){
  if(st < end){
    int mid = st + (end - st)/2;

    //individual left and right half can half their own seprate inversion pairs
    int leftInvCount = mergeSort(arr, st, mid);
    int rightInvCount = mergeSort(arr, mid+1, end);

    int invCount = merge(arr, st, mid, end); // inversion pair from left and right parts
        
    return leftInvCount + rightInvCount + invCount; // final inversion count
  }
  return 0;//invalid index
}
int main(){
  // vector<int> arr = {6,3,5,2,7};
  vector<int> arr = {1,3, 5,10, 2, 6,8,9};

  int finalInvCount = mergeSort(arr, 0, arr.size()-1);

  cout<< "Inv count : "<< finalInvCount << endl;
  return 0;
}