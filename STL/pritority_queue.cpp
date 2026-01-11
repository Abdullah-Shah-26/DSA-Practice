#include<queue>
#include<iostream>
using namespace std;
int main(){
    priority_queue<int>q;

    q.push(5);
    q.push(3);
    q.push(4);
    q.emplace(10);

    cout<<"size of priority queue : "<<q.size()<<endl;

     while(!q.empty())
     {
        cout<<q.top()<<endl;
        q.pop();
     }

     cout<<endl;

     //reversed priority queue // smallest val more priority

     priority_queue<int,vector<int>,greater<int>>q1;

     q1.push(10000);
     q1.push(100);
     q1.push(10);

     while(!q1.empty()){
         cout<<q1.top()<<endl;
         q1.pop();

     }



}