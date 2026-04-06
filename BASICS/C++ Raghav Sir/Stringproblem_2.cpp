#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//reverse a substring from position 2 to 5 using stl functions
int main(){
    string s = "raghav";
    cout<<s<<endl;

    reverse(s.begin()+1,s.begin()+5);

    cout<<s<<endl;


}