#include<iostream>// swap 2 nos without extra variable
using namespace std;
int main(){
int x=12;
int y=20;
cout << x <<" "<<y<<endl;
x=x+y;
y=x-y;
x=x-y;
cout << x <<" "<<y<<endl;
}
