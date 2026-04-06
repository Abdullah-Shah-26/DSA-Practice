#include<iostream>
using namespace std;
int main(){


int a,b,c;
cout<< " enter the 3 sides of triangle ";
cin>>a;
cin>>b;
cin>>c;
if(a+b>c || b+c>a || a+c>b)
 cout<<"triangle is possible";
 else 
 cout<<" triangle isnt possible";
}