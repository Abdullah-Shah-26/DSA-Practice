#include<iostream> //! CHECKING PRIME NUMBERS USING FUNCTIONS
using namespace std;

bool check_prime(int);
int main(){
    int n;
    cout<<"enter a positive integer:";
    cin>>n;
    if(check_prime(n))
    cout<<n<<"is a prime number"<<endl;
    else
    cout<<n<<"is not a prime number"<<endl;
    return 0;
}
bool check_prime (int n){
    bool is_prime =true;
if(n==0|| n==1){ // 0 and 1 are not prime no 
    is_prime =false;
}
for(int i=2;i<=n;i++){
    if(n%i==0){
        is_prime=false;
        break;
    }
    
    
}return is_prime;
}