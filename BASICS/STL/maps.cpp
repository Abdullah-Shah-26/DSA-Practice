#include<map> //like pairs 
#include<iostream>
#include<string>
using namespace std;
int main(){
    map<string, int>m;

    m["tv"] = 100;
    m["laptop"] = 200;
    m["headphone"] = 100;

    m.insert({"camera",50});
    m.emplace("tablet",25);

    
    //to remove keys 
    m.erase("tv");

    for(auto p:m){
        cout<<p.first<<"  "<<p.second<<endl;

    }
    cout<<"size of map:  "<<m.size()<<endl;
    cout<<"no of instances a key is associated with : "<<m.count("camera");

    //to use m.find
    if(m.find("camera") != m.end()){
        cout<<"found";
}else{
    cout<<"not found";
}

}