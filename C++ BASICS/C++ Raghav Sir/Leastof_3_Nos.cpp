#include<iostream>
using namespace std;
int main(){

    int x,y,z;
    cout<<" enter the ages of 3 students: ";

    cin>>x ; cin>>y; cin>>z;
    if(x<y){
        if(x<z)
            cout<< x <<" is youngest";
            else
            cout << z << " is youngest";
    }
    else {
        if(y<z)
            cout<<y<<" is youngest";
            else 
            cout<<z<<" is youngest";
        
    }






}