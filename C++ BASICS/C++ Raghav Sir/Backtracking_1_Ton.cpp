#include<iostream>
#include<cmath>
using namespace std;
void print(int n){    //! The function is called multiple times and when it hits base case it will start
                        //! returning its values to the previous call and print n of that call    
    if(n==0) //base
    return;
    print(n-1); //call
    cout<<n<<endl; //work

}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    print(n);
    return 0;
}