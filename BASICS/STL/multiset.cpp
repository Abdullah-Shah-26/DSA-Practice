#include<set>
#include<iostream>
using namespace std;
int main(){
    multiset<int>s; //dupli allowed 

    s.insert(1);
    s.insert(2);
    s.emplace(3);

    s.insert(1);
    s.insert(2);
    s.emplace(3);

    for(int val:s){
        cout<<val<<" ";
    }
}