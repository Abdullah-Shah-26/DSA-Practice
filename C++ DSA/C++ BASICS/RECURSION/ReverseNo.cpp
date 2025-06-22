#include<iostream> //! REVERSE OF A NO USING LOOPS
using namespace std;
int main(){
    int n;
    cout<<" enter a number :";
    cin>>n;
    int r=0;
    while(n!=0){
        int lastDig=n%10;   
        r*=10;
        r+=lastDig;
        n/=10;
    }
    cout<<r;
}