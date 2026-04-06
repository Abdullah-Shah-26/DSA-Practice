//     *
//    **
//   ***
  
// ---
// --
// -

//plus

// *
// **
// ***

#include<iostream>

using namespace std;
int main(){
int n =5;
    for(int i=1;i<=n;i++){  // for rows

        for(int j=1;j<=n-i;j++){ //for spaces we are taking n-i cause we dont need space for last row
            cout<<" ";
        }


        for(int j=1;j<=i;j++){  //for stars
            cout<<"*";
        }
        cout<<endl;
    }


cout<<"\n\n";

for(int i=1;i<=n;i++){  // for rows

    for(int j=1;j<=n-i;j++){ //for spaces we are taking n-i cause we dont need space for last row
        cout<<" ";
    }


    for(int j=1;j<=i;j++){  //for numbers
        cout<<j;
    }
    cout<<endl;
}


}