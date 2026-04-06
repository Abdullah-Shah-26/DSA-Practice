#include<iostream> 
using namespace std;
int main() {//! POWERS OF 2 USING LEFT SHIFT 
    int n;
    cout<<"enter how many powers of 2 to be displayed:"<<endl;
    cin >>n;
    for (int s=0;s<=n;s++){ //S=SHIFT 
        cout<<(1<<s)<<" ";
    }
    return 0;

}