#include<list>
#include<iostream>
using namespace std;
int main(){
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    
    l.push_front(3);
    l.push_front(5);

    l.pop_back();
    l.pop_front();

    l.emplace_back(100);
    l.emplace_front(200);

    // cout<< " element at spacific index :  "<< l[2] <<endl;  cannot access in list
 
    for(int val: l){
        cout<< val <<" ";
    }
}