#include<iostream>
using namespace std;
int main(){


int x;
cout<<" enter a no  " ;
cin>>x;
if ((x%3==0 || x%5==0)&&(x%15 != 0))
    cout<< x << "satisfies condition";
    else 
    cout<< " condition not satisfied";
}