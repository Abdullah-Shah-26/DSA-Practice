#include<queue>
#include<iostream>
using namespace std;
int main(){
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.emplace(4);

    queue<int>q2;

    cout<<"before swapping size of queue 1 : "<<q.size()<<endl;

    cout<<"is queue 1 empty : "<<q.empty()<<endl;

    q2.swap(q);

    cout<<"after swapping size of queue 2 : " <<q2.size()<<endl;

    while(!q2.empty()){
        cout<<q2.front()<<endl;
        q2.pop();
    }
   


}