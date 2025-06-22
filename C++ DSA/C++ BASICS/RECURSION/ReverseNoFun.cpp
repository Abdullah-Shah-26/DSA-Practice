#include<iostream> //! REVERSE NO USING FUNCTIONS
using namespace std;
int revDig(int n) 
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10; // r= reverse number 
        n=n/10; // n= number to be reversed
    }
    return r;
}
int main(){
    int n=12345;
    cout<<"reverse of the number is:"<<revDig(n);
    
}