
#include<iostream>
#include<cmath>
using namespace std;
void print(int x, int n){
    if(x>n)
    return ; 
    cout<<x<<" ";
    print(x+1,n);

}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    print(1,n);
    return 0;

}