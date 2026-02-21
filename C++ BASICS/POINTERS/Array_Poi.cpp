#include<iostream>
using namespace  std;
int main()
{
    int arr[]={1,2,3,4,5};//arr ptr is constant pointer not modifiable

    cout<<arr<<endl; //index 0 ka address
     cout<<*arr<<endl;//index 0 ki value

      cout<<*(arr+1)<<endl;
       cout<<*(arr+2)<<endl;
    return 0;
}