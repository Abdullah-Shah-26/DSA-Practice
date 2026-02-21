#include<iostream>
using namespace std;
//count no of elements of arr > than a given no
int main(){
    int arr[5]={1,2,3,4,5};
   int key = 4;
    int count = 0;
    for(int i = 0; i<=5;i++){
        if(arr[i]>key){
            count++;
        }
    }
    cout<<count;
}