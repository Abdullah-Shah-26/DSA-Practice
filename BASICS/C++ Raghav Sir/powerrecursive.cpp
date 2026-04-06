#include<iostream>
#include<cmath>
using namespace std;
// int power(int x,int n){
//     if(n==0)
//     return 1;

//     return x * power(x,n-1);
// }

//!LOGARITHMIC APPROACH
int power(int x, int n) {
    if (n == 0) // Any number raised to the power 0 is 1
        return 1;
    if (n == 1) // Base case: x^1 is x
        return x;

    int halfPower = power(x, n / 2);

    if (n % 2 == 0) // If n is even
        return halfPower * halfPower;
    else // If n is odd
        return halfPower * halfPower * x;
}

// int power(int x,int n){
//     if(n==1)
//     return x;
//     if(n==0)
//     return 1;
//     if(n%2==0)
//     return power(x,n/2)*power(x,n/2);
//     else
//     return power(x,n/2)*power(x,n/2)*x;
// }



int main(){
    int n,x;
    cout<<"enter no & pow : ";
    cin>>n;  cin>>x;              
    cout<<power(x,n);
    return 0;
}
