#include<iostream>
#include<stdbool.h>
using namespace std;
int main(){
        int n;
        cout<< "Enter n value: ";
        cin>>n;


if(n==1){ 
cout << "not prime or composite";
exit(1);
}
bool flag = true;
for(int i=2 ; i<=n/2; i++){
    if(n%i==0){
    flag = false;
    break;
    }
}
if(flag==true) 
cout<< " prime";
else 
cout << " composite";
}