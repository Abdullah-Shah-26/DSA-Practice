
#include<iostream>
#include <climits>
using namespace std;
void change(int arr[]){
    arr[0]=100;
}
int main(){
    int a[5]= { 1, 2, 3, 4, 5 };
    // cout<<"enter array elements : ";
    // for(int i=0; i<5; i++){
    //     cin>>a[i];
    // }
    a[0] = 10;
    change(a);   //!ARRAYS PASS BY REFERANCE AUTOMATICALLY SO VLAUES CAN BE CHANGED USING FUNCTONS 

    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;

//     for(int i=4; i>=0; i--){
//         cout<<a[i]<<" ";
//     }
int sum=0;
for(int i=0; i<5; i++){
     sum += a[i];
}
cout<<sum<<endl;

cout<<endl<<endl;

int n=sizeof(a);  //4*5 bytes 
cout<<n;

cout<<endl<<endl;

int mn=INT_MAX;
for(int i=0; i<5; i++){
   mn = min(mn,a[i]);
}

}
