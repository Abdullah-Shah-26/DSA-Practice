#include <iostream>
using namespace std;
int diagonalSum(int mat[][4], int n){
    int sum=0;
  for(int i=0;i<n;i++){
//primarydiagonal j=i
//secondary diag j=n-i-1

sum+=mat[i][i];
if(i!=n-i-1){
    sum+=mat[i][n-i-1];
}
       }return sum;
}
int main(){
    int matrix[4][4]={{1, 2, 3,4},{4, 5, 6,7},{7, 8, 9,9},{10, 11, 12,13}};
    int n=4;
    cout <<diagonalSum(matrix,n)<<endl;
    return 0;
}