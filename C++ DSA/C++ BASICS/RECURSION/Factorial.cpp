#include<iostream> //program to find factorial of a num n
using namespace std;

int main(){

int i=1,n,f=1;
cout << "enter n"<< endl;
cin >>n;
while(i<=n){
    f=f*i;
    i=i+1;
}

cout <<"fact=" << f <<endl;
return 0;
}