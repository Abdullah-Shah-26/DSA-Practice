#include<iostream>
using namespace std;
int main(){
    int a[]={2,4,3,5,6,7}; //! PRINTING COMMON ELEMENTS OF BOTH ARRAYS 
    int b[]={9,2,7,6};
    int sizea=sizeof(a)/4;
    int sizeb=sizeof(b)/4;
    int big=(sizea>sizeb)?sizea:sizeb;
    int small=(sizea>sizeb)?sizeb:sizea;
    for(int i=0; i<big;i++){
        for (int j=0;j<small;j++){
            if(a[i]==b[j]){
                cout<<"ELEMENT IS: "<<a[i]<<endl;
            }
        }
    }
    return 0;
}