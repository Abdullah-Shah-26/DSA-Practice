#include<iostream> //!RECURSION WITHOUT USING EXTRA PARAMETER
using namespace std;
void print(int n){//FUNCTION
    if(n==0) return;//BASE CASE 
    print(n-1);// CALL
    cout<<n<<endl; //WORK
}
int main(){
    int n;
    cout<<"enetr n:";
    cin>>n;
    print(n);// 
}