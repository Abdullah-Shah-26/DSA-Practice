#include<iostream>
using namespace std;
int main(){

    int i,j; 
    for(i=1; i<=100;i++){           /// optimization for(i=2;i<=100;i+2)    loop is running only 50 times
        if(i%2==0){                                // cout<<i;
            cout<<i<<endl;
        }
    }


     for(j=1; i<=100;i++){
      if(j%2!=0){
         cout<<j<<endl;
       }
     }

}