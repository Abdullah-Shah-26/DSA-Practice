#include<iostream> //!RECURSION
using namespace std;
void print(int x,int n){//FUNCTION
    if(x>n) return;//extrra parameter jo check kareG ki x n se bada na ho jaye
    cout<<x<<endl; 
    print(x+1,n);// 
}
int main(){
    int n;
    cout<<"enetr n:";
    cin>>n;
    print(1,n);

}