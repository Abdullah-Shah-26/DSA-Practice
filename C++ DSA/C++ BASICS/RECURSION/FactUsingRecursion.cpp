#include<iostream> //! CALCULATING FACTORIAL USING RECURSION
using namespace std;

int fact(int n){ //fact(5)=fact(4)*5 ..repeats
    if(n==1 || n==0) return 1;
    return n* fact(n-1);
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<fact(n);
}