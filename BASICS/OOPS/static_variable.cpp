#include<iostream>
#include<string>
using namespace std;
void fun(){
    static int x = 0;
    cout<<x<<endl;
    x++;
}
int main(){
    fun();
    fun();
    fun();
    fun();
    fun();
    fun();
    
}