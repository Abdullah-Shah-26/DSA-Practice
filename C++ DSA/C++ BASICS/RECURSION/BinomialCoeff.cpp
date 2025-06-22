#include<iostream> //!Combinations nCr=n!/r!*(n-r)!
using namespace std;

using namespace std;
int factorial(int n){
    int fact =1;
    for (int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int ncr(int n, int r){
     return (factorial(n)/(factorial(r)*factorial(n-r)));
}
int main(){

    int n=8;
    int r=2;
   cout<<ncr(n,r)<<endl;
    return 0;
    
}
