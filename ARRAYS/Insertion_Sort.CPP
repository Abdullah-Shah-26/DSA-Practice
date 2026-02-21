#include <vector>
#include <set>
#include<iostream>
using namespace std;


void insertionSort(int arr[], int n){ //! TC = O(n ^2)
    for(int i =1; i<n; i++){
        // loop runs n-1 times and starts for 1st element of sorted part
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;// prev travels backwards in sorted part
        }
        arr[prev+1] = curr; //placing arr element in its corrected position
    }
}
int  main(){
    int n = 5;
    int arr[] = { 4,1,5,2,3};
    insertionSort(arr , 5);
    for(int i = 0; i<n; i++){
        cout << arr[i] <<" ";
    }
    cout<<endl;
}