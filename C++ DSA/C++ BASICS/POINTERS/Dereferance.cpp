#include<iostream>
using namespace  std;
int main(){//  *=dereferance operator 
int a=10;
int* ptr=&a;
 int** parPtr=&ptr;
    cout<<*(&a)<<endl;
    cout<<*(ptr)<<endl;

       cout<<*(parPtr)<<endl;
        cout<<**(parPtr)<<endl;
      return 0;

}