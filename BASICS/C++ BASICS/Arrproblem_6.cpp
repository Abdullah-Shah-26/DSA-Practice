#include<iostream>
#include<climits>
using namespace std;
// copy one arr to other in reverse order

// i+j = n-1;
// j=n-i-1
int main(){
    int arr[5]={1,2,3,4,5};
    int brr[5];
    int n=5;
    int j;
    for(int i=0;i<=5;i++)
   {
   j=n-i-1; //
    brr[i]=arr[j];
   }


for(int i=0; i<5; i++){
    cout<<brr[i]<<"  ";

}

}