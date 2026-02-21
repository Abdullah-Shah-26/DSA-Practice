#include<iostream> //! ARRAYS PASS BY REFERANCE
using namespace std;
void change(int arr[]){//function receiving array
    arr[0]=9; // value updation

}
int main(){
    
    int arr[3]={1,2,3};
       for(int i=0;i<=2;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    change(arr); // funtion calling and sending array
     for(int i=0;i<=2;i++){
        cout<<arr[i]<<" ";

    
}
}