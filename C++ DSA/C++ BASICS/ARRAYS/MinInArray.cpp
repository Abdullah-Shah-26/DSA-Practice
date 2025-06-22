#include<iostream>
using namespace std;
int main(){
    int arr[] = {10,20,30,40,50,60,70,80,900};
    int n = sizeof(arr)/4;
    int MINIMUM = arr[0]; //! INT_MAX;
    for( int i=0 ; i<n ; i++){
       MINIMUM =min(MINIMUM,arr[i]); //! ANY ONE CAN BE USED
       //if(arr[i]<MINIMUM) MINIMUM = arr[i];
    }
    cout << MINIMUM;
}
