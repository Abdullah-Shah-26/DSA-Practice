#include<iostream>
#include<climits>
#include<string>
using namespace std;
int main(){
    string x = "hello my name is abdullah";
    cout<<x<<endl;

    string s;
    cout<<"enter your hobby  ";
    cin>>s; // cin doest consider string after spaces

    getline(cin,s); // to input a stirng even with spaces

    cout<<"your hobby is "<<s;

}