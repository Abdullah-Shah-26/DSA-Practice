#include<iostream>
using namespace std;
    int main(){
        int x =3, y,z;
        y = x= 10;    //assignment operator evaluate form right to left
        z = x<10;     //relational operator have high precedence than = 
         // the value is false 
        cout<<x<<endl<< y <<endl<< z<<endl;


    }