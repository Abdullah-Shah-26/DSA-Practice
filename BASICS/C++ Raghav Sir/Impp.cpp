#include<iostream>
using namespace std;
int main(){
     float x = 5/2; 
        cout<< x <<endl; //! wont output 2.5 
        cout<< 5/2 <<endl; // same reason
        cout<< 5.0/2 <<endl;
        cout<< 5.0/2.0 <<endl;


    }     // why?? 
      // first the computer will evaluate rhs and treat 5 and 2 as integer and gives the final ans as integer 
      // which will be stored in x