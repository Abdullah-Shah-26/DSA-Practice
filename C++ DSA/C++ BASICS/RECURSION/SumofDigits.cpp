#include<iostream> //!sum of digits 
using namespace std;
int sumofdigits(int num){
    int digSum=0;
    while(num>0){
        int lastDig=num%10; //gives remainder
        num=num/10; //gives quotient
        digSum+=lastDig;  //add sum of digits 
          }
          return digSum;
}

int main(){

cout <<"sum="<<sumofdigits(12345)<<endl;
return 0;
}