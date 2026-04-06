#include<iostream> // pointers
using namespace std;
int main()
{

    int x=3;
    int*p=&x; //pointer 
    cout<<&x<<endl; //address of x
    cout<<p<<endl; //pointer giving address of x
    cout<<*p<<endl; //pointer giving value of x ( drerefrance operator)
    cout<<&p<<endl; //pointer ka khud ka address
    cout<<x<<endl; //CHANGING VALUE WITHOUT USING X 
    *p=20; //POINTER IS UPDATING VALUE OF X
    cout<<x<<endl;
}




