#include<iostream>
using namespace std;
int decToBinary(int decNum)//!FUNCTION TO CONVERT DECIMAL(BASE 10) {0-9} TO BINARY (BASE 2) {0,1}
     
     {
     int ans=0,pow=1;
    while(decNum>0){
        int rem=decNum%2; // remainder
        decNum /=2; //qiuotient 
        ans+=(rem*pow);
        pow*=10; //place gets updates units, tens , hundreds place, thousands place
    }
    return ans; //binary form
}
int main(){
    int decNum=50;
    for (int i=1;i<=10;i++){//! 1 SE 10 TAK SARE NO BINARY MEIN CONVERT HOJAINGE
        cout<<decToBinary(i)<<endl;
    }
    return 0;
}