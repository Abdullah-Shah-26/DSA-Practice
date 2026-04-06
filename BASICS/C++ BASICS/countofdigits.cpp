#include<iostream>
#include<stdbool.h>
using namespace std;
int main(){
    int n;
    cout<< "Enter n value: ";
    cin>>n;
    int c=0;
    int rem;
    int s=0;            // additive identity 
    int product = 1;    // multiplicative identity 
    int sumofevendig=0;
    int revdig=0;
    while(n!=0){
       rem=n%10;             // calculates the last digit 
       s+=rem;               // adds last digit to sum  and calculate sum of all digits
       product*=rem;         //to find product of all digits
        c++;
        if(rem%2==0){
        sumofevendig+=rem;    // to calculate the sum of even digits 
        }
        revdig=revdig*10+rem;  // to reverse the digits       
        n=n/10;       
    
    }

cout<<"count of digits "<<c<<"\n ";
cout<<"sum of digits " <<s<<"\n ";
cout<<"product of digits " << product<<"\n ";
cout<<"sum of even digits " << sumofevendig<<"\n ";
cout<<"reverse of digit " << revdig<<" ";
}