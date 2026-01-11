#include<map>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m; //no duplicate keys //random order // cant use m["key"] = 100 to insert but emplace

    m.emplace("tv",100);
    m.emplace("mac",50);
    m.emplace("laptop",500);
    m.emplace("tablet",10);

    for(auto p: m){
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;

}