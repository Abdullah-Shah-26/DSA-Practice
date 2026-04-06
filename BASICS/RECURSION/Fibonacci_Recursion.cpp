 #include<iostream>  // ! N TH  FIBONACCI TERM USING RECURSION
using namespace std;

int fibo(int n){ 
    if(n==1 || n==2) return 1;
   return fibo(n-1)+fibo(n-2);//fibo n = fibo n-1 + fibo n-2
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<fibo(n);
}                  

