//   1 2 3 4 5
//1      *
//2      *
//3  * * * * *  if(i==3||j==3) print * where 3 is middle row
//4      *
//5      *
#include<iostream>
#include<stdbool.h>
using namespace std;
int main(){
int n =5;
int mid = n/2+1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == mid || j == mid) {
                cout << "* ";
            } else {
                cout << "  "; // Ensures proper spacing for alignment
            }
        }
        cout << endl;
    }

  
    cout<< " \n\n";

//  *****         //if i=first or last row     or   j=first or last col      print * else space
//  *   *
//  *   *
//  *****

// rows =4 
for(int i=1;i<=4;i++){
    for(int j=1;j<=4;j++){
        if(i==4||j==4||i==1||j==1){
            cout<<"*";
        }
        else
        cout<<" ";
    }
    cout<<endl;
}


// *   *       i == j to print diagonal
//  * *        i+j == n to print reverse diagonal
//   *
//  * *
// *   *

for(int i=1;i<=5;i++)
{
    for(int j=1;j<=n;j++)
    { 
        if(i==j || (i+j)==6)
        cout<<"*";
    else
    cout<<" ";
    }
cout<<endl;
}
}









