
#include<iostream>
// nCr = n! / r!*(n-r)!
using namespace std;

int fact(int x){
    int f=1;
    for(int i=1;i<=x;i++){
        f=f*i;
    }
    return f;
}
int main(){
    int n,r;
    cout<<"enter n and r : \n";
    cin>>n; cin>>r;
    int a=fact(n);
    int b=fact(r);
    int c=fact(n-r);
    cout<<a/(b*c)<<endl;
    

}