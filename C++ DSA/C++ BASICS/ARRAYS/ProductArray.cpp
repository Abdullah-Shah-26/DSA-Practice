#include<iostream>//!PRODUCT OF ELEMENTS IN ARRAY
using namespace std;
int main(){
    int arr[] = {10,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/4;//! GIVES THE NO OF ELEMENTS IN ARRAY
    int product=1;
    for( int i=0; i<n;i++){
        product*=arr[i];
    }
    cout<<product;
}