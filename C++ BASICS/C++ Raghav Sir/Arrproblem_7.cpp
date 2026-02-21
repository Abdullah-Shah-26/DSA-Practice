#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int n=5;
    //!method 1 
    // for(int i=0; i<5; i++){
    //     cout<<arr[n-i-1]<<"  ";
    
    // }
    cout<<endl;
    //!method 2 
    // by swapping 2 nos using 2 pointers
    int i=0;
    int j=n-1;
    while(i<j){
       int temp= arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
        i++;
        j--;

    }   for(int i=0; i<5; i++){
        cout<<arr[i]<<"  ";
    
    }

}  
///! LOGIC TO CHECK IF  GIVEN ARRAY IS PALINDROME OR NOT

// while(i<j){
// if(arr[i]!=arr[j]){
// cout<<"arr isnt palindrome";
// exit(1);
// }
// i++;
// j--;
// }
// cout<<" arr is palindrome";

