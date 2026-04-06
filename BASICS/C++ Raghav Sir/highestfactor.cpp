#include<iostream>
using namespace std;
int main(){
        int n;
        int i;
        int f=1;
        cout<< "Enter n value: ";
        cin>>n;
        for(i=1;i<n;i++)
        {
            if(n%i==0){ ///checking if i is a factor of n
                f=i; // storing the highest factor in f
            }
        }
                    
        cout<<f<<endl;

  //more optimized approach 
/// we know that highest factor of a no apart form itself is less than or equal to its half
for (int i=n/2; i>=1;i--)
{
    if(n%i==0){
        cout<<i;
        break;
    }
}
}