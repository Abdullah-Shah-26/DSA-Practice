#include<stack>
#include<iostream>
using namespace std;
int main(){
    stack<int>s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);

    stack<int>s2;

    cout<<"size of stack 1 before swap : "<<s.size()<<endl;
    s2.swap(s);
    cout<<"size of stack 1 after swapping "<< s.size()<<endl;
    
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }
    cout<<" is the stack empty : "<<s.empty()<<endl; //1 if true
}
