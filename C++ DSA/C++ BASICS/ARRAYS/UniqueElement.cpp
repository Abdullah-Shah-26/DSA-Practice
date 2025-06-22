#include<iostream>
using namespace std;
 int printUnique(int a[], int size){
    for (int i=0;i<size;i++){
        bool matchFound = false;
        for(int j=0 ;j<size ;j++)
        if (a[i]==a[j] && i!=j)
        matchFound = true;
        if(!matchFound)cout<<a[i]<<endl;
    }
    cout<<endl;
 }
 int main(){
    int a[]={1 ,2,3,4,5,6,3,4,1,8,9,7,8};//NOT PRINTING THE REPEATED ELEMENTS
    int size =13;
    printUnique(a , size );
    return 0;
 }