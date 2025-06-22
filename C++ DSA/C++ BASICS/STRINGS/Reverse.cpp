#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
int main(){
    string str="apna college";

    reverse(str.begin(),str.end());//iterators
    cout<<str<<endl;
    return 0;
}