//HALF OF AN INTEGER
#include<iostream>
using namespace std;
int main(){
    int x;        //   int x ; cin>>x ; is valid but a bad way to write
    cin>>x;       // int       x ; is also valid   
    cout<<(float)x/2;

    //or

// float y = (float)x;
// cout<<y/3;
}