#include<iostream>
using namespace std;
int main(){
        //inrement even index nos by 20 and odd idx nos to their 2nd multiple
    int arr[5]={1,2,3,4,5};
    
    for(int i=0;i<5 ;i++){
        if(i%2 == 0){
            arr[i]+=10;
        }
        if(i%2!= 0){
            arr[i] *=2;
        }
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<"  ";
 
}
}