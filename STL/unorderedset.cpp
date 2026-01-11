
#include<unordered_set>
#include<iostream>
using namespace std;
int main(){
    unordered_set<int>s; //random arrangement no lower upper bound concept

    s.insert(1);
    s.insert(2);
    s.emplace(4);
    s.emplace(3);

 
    for(int val:s){
        cout<<val<<" ";
    }
}