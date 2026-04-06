#include<iostream>
using namespace std;
int main(){
 int arr[5]={1,2,3,4,5};

    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows=3;
    int cols=3;
     
// row wise print

 for(int i=0 ; i<3 ;i++){
        for(int j=0;j<3;j++){
            cout << matrix[i][j]<<" ";
        }
        cout<< endl;
     }

     cout<< "                                      "<<endl;

     // col wise print

 for(int j=0 ; j<3 ;j++){
        for(int i=0;i<3;i++){
            cout << matrix[i][j]<<" ";
        }
        cout<< endl;
     }
    
    
}