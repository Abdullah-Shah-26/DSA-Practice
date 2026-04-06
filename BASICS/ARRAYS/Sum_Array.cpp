#include<iostream> //!SUM OF ELEMENTS IN ARRAY
using namespace std;
int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90};
    int n = sizeof(arr)/4;
    int sum=0;
    for( int i=0; i<n;i++){
        sum+=arr[i];
    }
    cout<<sum;
}
