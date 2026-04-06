#include<iostream> //! ARRAY KE ELEMENTS 0 SE SHURU HOTE HAY MEANS
//! O TH DABBA 1ST DABBA ...
using namespace std;
int main(){
    // 5 integers 
    int arr[5];//!DECLARATION
    cout<<"Enter array elements: ";
    for(int i=0;i<=4;i++){
        cin>>arr[i];
    }
       for(int i=0;i<=4;i++){
        cout<<arr[i]<<" ";
    }
    arr[0]=100;//!UPDATION
    cout<<endl;
      for(int i=0;i<=4;i++){
        cout<<arr[i]<<" ";
    }
}