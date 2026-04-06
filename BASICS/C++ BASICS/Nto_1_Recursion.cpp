#include<iostream>
#include<cmath>
using namespace std;
void print(int n){

    //base case 
    if(n==0)
    return ;

    cout<<n<<" ";  // work 
    //recursive case
    print(n-1);
}

int main(){
    int n=100;
    print(n);
    return 0;

}