#include<iostream>
using namespace std;
int main() //!FINDING IF A NO IS POWER OF 2 USING BITWISE MANUPULATION AND LOOP
{
    int n;
    cout<<"enter a number:"<<endl;
    cin>> n;
    if((n!=0)&&(n & (n-1))==0 ){
        cout << " number is power of  2";
    
    }
    else {
        cout<< " number is not a power of 2";
    }
return 0;
}