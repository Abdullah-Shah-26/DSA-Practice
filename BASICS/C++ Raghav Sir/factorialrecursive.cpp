#include<iostream>
#include<cmath>
using namespace std;
int fact(int n){
    if(n==1){
    return 1;
    }
    return n*fact(n-1);   
}
int main(){
    int n;
    cout<<"enter a no: ";
    cin>>n;                 
    cout<<fact(n);
    return 0;
}
