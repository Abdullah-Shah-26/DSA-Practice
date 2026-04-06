#include<iostream>
// nCr = n! / r!*(n-r)!
using namespace std;
int main(){
    int n,r;
    cout<<"enter n and r : \n";
    cin>>n; cin>>r;
    int a=1; //n!
    int b=1; //r!
    int c=1; //(n-r)!
    for(int i=1;i<=n;i++){
        a=a*i;
    }
    for(int i=1;i<=r;i++){
        b=b*i;
    }
    for(int i=1;i<=n-r;i++){
        c=c*i;
    }
cout<<a/(b*c)<<endl;


}