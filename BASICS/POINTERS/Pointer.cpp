#include<iostream>
using namespace  std;
int main(){
    int a=100;
     float price =100.2;
    int* ptr =&a;
    cout <<ptr<<endl;
    cout <<&a<<endl;

    cout <<&ptr<<endl;//pointer ka address

float* pointer=&price;
cout <<&price<<endl;
cout<<pointer<<endl;
 return 0;
 
   

}