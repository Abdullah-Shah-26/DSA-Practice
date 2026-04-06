#include<iostream>
#include<cmath>
using namespace std;
//recursive function
void sum(int n, int s){
   //! if the base case is hit print the sum obtained by recursive calls and return 
   if(n==0){
    cout<<s;
    return;
   }
   sum(n-1,s+n);


}
int main(){
    int n;
    cout<<"enter a no: ";
    cin>>n;
    sum(n,0);
    return 0;
}