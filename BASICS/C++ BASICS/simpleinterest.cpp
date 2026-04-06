#include<iostream>
#define pi 3.14
using namespace std;
int main(){
    float p,r,t;
    cout<<"enter principle amt rate of interest and time"<<endl;
    cin>>p;
    cin>>r;
    cin>>t;
    cout<<"the simple interest is : "<< (p*t*r)/100<<endl;
}