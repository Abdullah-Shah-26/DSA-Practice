#include<iostream> 
using namespace std;

int main()
 { // Sum of all odd no from 1 to n
    int n, oddsum=0; 
    cout << "enter n" << endl;
    cin>>n;

int i=1;
while(i<=n){
    if(i%2!=0)
        oddsum=oddsum+i;
        i++;
    }
    cout << "oddsum is = " <<oddsum<<endl;


return 0;
}   