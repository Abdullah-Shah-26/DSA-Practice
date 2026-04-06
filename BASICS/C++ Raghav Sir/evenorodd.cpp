#include<iostream>
using namespace std;
int main(){
    int x ;
    cout << " enter a no "<< endl;
    cin>>x;
    if(x%2==0)
        cout<<x<<" is even ";
    else                            // or if(x%2!= 0) cout<<"odd"
        cout<<x<< " is odd";
}