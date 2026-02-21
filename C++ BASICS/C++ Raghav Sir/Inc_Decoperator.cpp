#include<iostream>
using namespace std;
int main(){
    int x;
    x=5;
    cout<< x << endl;
    cout<< x++ << endl; // old value is used first and then incremented 
    cout<< x << endl;  // incremented value
    
    int y=10;
    cout<< y << endl;
    cout<< ++y << endl; // (incremented value) first increase then print

   int z=20;
   cout<< z << endl;
   cout<< --z << endl; //(decremented value) first decrement then print 

   int a=100;
   cout<< a <<endl;
   cout<< a-- << endl; // old value is used first then decreased
   cout<< a << endl;

}