#include<iostream>  //!  IMPLEMENTATION OF Q AS STACK - using only 1 stack
#include<stack>
using namespace std;
class queue{
    stack<int> s1;

    public: 

    void push(int x){ // TC = O(1)
        s1.push(x);    
    }

    // integrating both pop and top in one fun since both ops happen at front
    int pop(){  //! TC = O(n)
        if(s1.empty()){
            cout<< " queue is empty "<<endl;
            return -1;
        }

        int x = s1.top(); // storing the element before popping
        s1.pop();
        if(s1.empty()){ // only one element in stack return that element
            return x;
        }

        int item = pop();// recursively calling pop
        s1.push(x); // again storing all elements in stack
        return item;

    }

    bool empty(){
        return s1.empty() == 0;
    }


};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}