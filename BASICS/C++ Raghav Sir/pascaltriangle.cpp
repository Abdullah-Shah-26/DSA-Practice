//pascal triangle
//j= 1 2 3 4          iCj  
//1     1
//2    1 1
//3   1 2 1 
//4  1 3 3 1

#include<iostream>
#include<cmath>
using namespace std;

int fact(int x){
    int f=1;
    for(int i=1;i<=x;i++){
        f=f*i;
    }
    return f;
}

int ncr(int n,int r){
    int a=fact(n);
    int b=fact(r);
    int c=fact(n-r);
    return a/(b*c);
    
}
int main()
{
    int n=5;
    for(int i=0;i<=n;i++){

        for(int j=0;j<=n-i-1;j++){ //spaces
            cout<<"  ";
        }
        for(int j=0;j<=i;j++){    //values = ncr
            cout<<ncr(i,j)<<"   ";
        }cout<<endl;
    }
}