#include<iostream>
using namespace std;
int main(){

int a ,b, c;
cout<<" enter 3 numbers ";
cin>>a; cin>>b; cin>>c;
int max;

//TERNARY OPERATOR 

max = ((a>b)&&(a>c))?a:(((b>a)&&(b>c))?b:c);
cout<<max;
}





