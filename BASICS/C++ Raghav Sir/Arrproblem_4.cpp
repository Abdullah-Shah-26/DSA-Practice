//difference between sumof elem at even and odd indexes
#include<iostream>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    int even=0;
    int odd=0;
    for(int i=0; i<=5;i++){
        if(i%2 == 0){
            even+=arr[i];

        }
        if(i%2!= 0){
            odd+=arr[i];

        }
    }
    cout<<"difference= "<<even-odd<<endl;
}
