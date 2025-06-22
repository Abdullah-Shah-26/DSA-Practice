#include<iostream> //!program to explain pass by value {COPY of arguments will be passed to function}
using namespace std;
int sum (int a, int b) //formal parameters
{
    a=a+10; // 15
    b=b+10; // 14
    return a+b; // 29
}
int main(){
    int a=5, b=4;
    cout <<sum (a,b)<<endl; //arguments

    cout<<a<<endl;
     cout<<b<<endl;
     return 0;
}

