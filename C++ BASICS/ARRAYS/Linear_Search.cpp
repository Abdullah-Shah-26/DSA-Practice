#include<iostream>
using namespace std;
int linearSearch(int arr[], int size , int target)
{
    for (int i=0; i<size;i++){
        if(arr[i]==target ){ 
            return i;//IF TARGET VALUE IS FOUND 
        }// i IS INDEX OF THE ELEMENTS OF THE ARRAY 
    }
    return -1 ; //IF TARGET VALUE IS NOT FOUND 
}


int main(){
    int arr[]={4,2,8,1,2,5,7};
    int size =7;
    int target = 1; // ! VALUE TO BE FOUND IN ARRAY


    cout << linearSearch(arr , size, target)<<endl;
    return 0;

}