#include<iostream>
using namespace std;
int main(){
    int arr[] = {10,20,30,40,50,60,70,80,900};
    int n = sizeof(arr)/4;
    int MAXIMUM=arr[0]; //! OR INT_MIN;
    for( int i=0; i<n;i++){
       MAXIMUM=max(MAXIMUM,arr[i]); //! ANY ONE CAN BE USED
       //if(arr[i]>MAXIMUM) MAXIMUM=arr[i];
    }
    cout<<MAXIMUM;
}
