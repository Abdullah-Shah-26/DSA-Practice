#include<iostream>
using namespace std;// size varies in different systems
int main(){
cout << sizeof(int) <<endl; // int is signed by default means it can take bith + - values //!undigned takes only +ve
cout << sizeof(long int) <<endl;
cout << sizeof(short int) <<endl;
cout << sizeof(long long int) <<endl; // ya long long same hota hai
unsigned int x=-10;
cout<< x <<endl; //(compiler is thinking it is a +ve no starting with 1 )





}