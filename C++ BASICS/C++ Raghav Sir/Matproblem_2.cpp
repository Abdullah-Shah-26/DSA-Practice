#include<iostream>
#include<climits>
using namespace std;
//store 10 at every cell of 5 by 5 mat
int main(){
    int a[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=10;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}