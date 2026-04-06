#include<iostream>
#include<cmath>
using namespace std;
//recursive function with return type
int sum( int n){
    if(n==1)      //! the fun will run recrusively and when base case is hit it will start returning its 
                 //! value to previous calls 
    return 1; 

    return n + sum(n-1);

    //since we know that sum(n) = n + (n-1) + (n-2) +....+1
}
int main(){
    int n;
    cout<<"enter a no: ";
    cin>>n;                 
    cout<<sum(n);
    return 0;
}