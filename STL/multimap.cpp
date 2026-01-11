#include<map>
#include<iostream>
using namespace std;
int main(){
    multimap<string, int>m; //fuplicate keys allowed // cant use m["key"] = 100 to insert
    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);
    m.emplace("tv",100);

    m.erase(m.find("tv")); //to erase 1 instance of key 
    
    for(auto p:m){
        cout<<p.first<< "  "<<p.second<<endl;
    }


}