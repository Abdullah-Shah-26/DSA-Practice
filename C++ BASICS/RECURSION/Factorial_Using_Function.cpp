#include<iostream> //program to find factorial of a num n using functions
using namespace std;
int factorialN(int n){

int f=1;
for(int i=1; i<=n ;i++){
    f*=i;
}
return f;
}
int main(){
cout <<factorialN(4)<<endl;
cout <<factorialN(5)<<endl;
return 0;
}