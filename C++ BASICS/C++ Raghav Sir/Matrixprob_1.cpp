#include<iostream>
#include<climits>
using namespace std;
// write a prog to store rno and marks of 4 std side by side
// rno marks
// 1    50
// 2    30
// 3    100
// 4    90
int main(){
    int a[4][2]={1,50,2,30,3,100,4,90};
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}