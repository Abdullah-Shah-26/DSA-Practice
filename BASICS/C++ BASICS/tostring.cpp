#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//! to_string() --> to convert integer to string
int main(){
int x = 12344;
cout<<x<<endl;
string s = to_string(x);
s+="pandu";
cout<<s<<endl;

// RETURN TOTAL NO OF DIGITS IN A NO WITHOUT LOOP using to_string()
int x1 = 3246;
string s1 = to_string(x1);
cout<<s1.length();


}