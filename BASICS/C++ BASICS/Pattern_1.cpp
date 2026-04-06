//1
//A B
//1 2 3 
//A B C D
#include<iostream>
#include<stdbool.h>
using namespace std;
int main(){
int n =5;
for(int i=1;i<=n; i++){
    for(int j=1;j<=i;j++){
        if(i%2!=0){          // i stands for row 
                            // even row no == characters
                            // odd row no == numbers

            cout<< j <<" ";
            
        } 
        else 
            cout<<(char)(j+64) <<" ";
           
    } cout<<endl;
}

cout<< " \n\n";
//1               //(i+j) even hay print 1
//0 1             //(i+j) odd hay print 0
//1 0 1
//0 1 0 1

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
        if((i+j)%2==0){
            cout<<1<<" ";
        }
        if ((i+j)%2!=0)
        cout<<0<<" ";
    }
    cout<<endl;
    }













}
