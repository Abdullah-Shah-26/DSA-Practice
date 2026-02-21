#include<iostream>
#include<climits>
using namespace std;
// find sec largest element of arr
int main(){
int mx=INT_MIN;
int secmx=INT_MIN;
int arr[5]={1,2,3,4,5};
for(int i=0;i<=5;i++){
    mx=max(mx,arr[i]);
}
for(int i=0;i<=5;i++){
    if(arr[i]!=mx)
    secmx=max(secmx,arr[i]);
}
cout<<mx<<endl<<secmx;




}