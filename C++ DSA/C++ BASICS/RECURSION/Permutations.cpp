#include<iostream>// permutation nPr=n!/(n-r)!

using namespace std;
int fact(int x){
    int f=1;
    for (int i=1;i<=x;i++){
        f=f*i;
    }
}
int main(){

    int n;
    cout<<"enter n:";
    cin>>n;
    int r;
    cout<<"enter r:";
    cin>>r;
    int a=fact(n);
    int b=fact(n-r);
    // int c=fact(r);
    return a/b; //cout<<a/(b*c) for combinations
}

