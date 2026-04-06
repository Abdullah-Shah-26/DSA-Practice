#include<iostream>
#include<cmath>
using namespace std;
//! the fun will run recrusively and when base case is hit it will start returning its 
                 //! value to previous calls 
 int fibo(int n){
    if(n==0||n==1)
    return n;

    return fibo(n-1)+fibo(n-2); //first fibo(n-1)will be called recursively until 
    //it hits base case and returns a value then fibo(n-2) will be called recursively
 }//!EULERS TOUR TREE

 int main(){
    int n;
    cout<<"enter a no: ";
    cin>>n;                 
    for(int i=0;i<=n;i++){
        cout<<fibo(i)<<" ";
    }
    return 0;
}

